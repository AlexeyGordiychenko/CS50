#include "doors.h"

/*
functions to work with the doors table
includes: reading, writing, getting number of records
          and functions to process queries
*/

struct doors_record read_doors(FILE* pfile, int index) {
    int offset = index * sizeof(struct doors_record);
    fseek(pfile, offset, SEEK_SET);
    struct doors_record record;
    fread(&record, sizeof(struct doors_record), 1, pfile);
    rewind(pfile);
    return record;
}

void write_doors(FILE* pfile, const struct doors_record* record_to_write, int index) {
    int offset = index * sizeof(struct doors_record);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct doors_record), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

int file_size_doors(FILE* pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int records_count_doors(FILE* pfile) { return file_size_doors(pfile) / sizeof(struct doors_record); }

void output_doors(FILE* input) {
    printf("Provide the number of records or to output all of them leave empty or type -1:\n");
    int n = validate_user_input_num(-1, -1);

    struct doors_record record;
    int count = 0;

    int column_width[] = {-4, -8, -8};
    char* header[] = {"id", "rooms", "closed"};
    int header_len = sizeof(header) / sizeof(header[0]);

    output_header(column_width, header, header_len);
    while ((n == -1 || count < n) && fread(&record, sizeof(struct doors_record), 1, input)) {
        printf("%*d%*d%*d\n", column_width[0], record.id, column_width[1], record.room, column_width[2],
               record.closed);
        count++;
    }
}

void insert_doors(FILE* input) {
    printf("Room (digit 0-99):\n");
    int room = validate_user_input_num(0, 99);
    printf("Status (1-closed, 0-open):\n");
    int closed = validate_user_input_num(0, 1);
    int records = records_count_doors(input);
    struct doors_record last_record = read_doors(input, records - 1);

    struct doors_record* new_record = calloc(1, sizeof(struct doors_record));
    new_record->id = last_record.id + 1;
    new_record->room = room;
    new_record->closed = closed;
    write_doors(input, new_record, records);
    free(new_record);
    printf("Inserted successfully!\n");
}

void update_doors(FILE* input) {
    printf("ID of the record to update or to update all records leave empty or type -1:\n");
    int id = validate_user_input_num(-1, -1);
    printf("New value for field 'ROOM'(digit 0-99) or to don't change leave empty or type -1:\n");
    int room = validate_user_input_num(-1, 99);
    printf("New value for field 'STATUS' (1-closed, 0-open) or to don't change leave empty or type -1:\n");
    int closed = validate_user_input_num(-1, 1);

    if (room == -1 && closed == -1) {
        printf("Nothing to update\n");
        return;
    }

    int i = 0;
    struct doors_record record;
    while (fread(&record, sizeof(struct doors_record), 1, input)) {
        if (id == -1 || record.id == id) {
            if (room != -1) {
                record.room = room;
            }
            if (closed != -1) {
                record.closed = closed;
            }
            write_doors(input, &record, i);
            if (id != -1) {
                printf("Updated successfully!\n");
                return;
            } else {
                fseek(input, (i + 1) * sizeof(struct doors_record), SEEK_SET);
            }
        }
        i++;
    }
    if (id != -1) {
        printf("ID not found\n");
    } else {
        printf("Updated successfully!\n");
    }
}

void delete_doors(FILE* input) {
    struct doors_record record;
    printf("ID of the record to delete:\n");
    int id = validate_user_input_num(0, -1);

    int i = 0, idx = -1;
    while (fread(&record, sizeof(struct doors_record), 1, input)) {
        if (record.id == id) {
            idx = i;
            break;
        }
        i++;
    }
    if (idx != -1) {
        int n = records_count_doors(input);
        int k = n - idx - 1;
        struct doors_record records[k];
        fseek(input, (idx + 1) * sizeof(struct doors_record), SEEK_SET);
        fread(&records, sizeof(struct doors_record), k, input);
        fseek(input, idx * sizeof(struct doors_record), SEEK_SET);
        fwrite(records, sizeof(struct doors_record), k, input);
        ftruncate(fileno(input), (n - 1) * sizeof(struct doors_record));
        printf("Deleted successfully!\n");
    } else {
        printf("ID not found\n");
    }
}
