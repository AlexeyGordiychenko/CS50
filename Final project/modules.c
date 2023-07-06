#include "modules.h"

/*
functions to work with the modules table
includes: reading, writing, getting number of records
          and functions to process queries
*/
struct modules_record read_modules(FILE* pfile, int index) {
    int offset = index * sizeof(struct modules_record);
    fseek(pfile, offset, SEEK_SET);
    struct modules_record record;
    fread(&record, sizeof(struct modules_record), 1, pfile);
    rewind(pfile);
    return record;
}

void write_modules(FILE* pfile, const struct modules_record* record_to_write, int index) {
    int offset = index * sizeof(struct modules_record);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct modules_record), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

int file_size_modules(FILE* pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int records_count_modules(FILE* pfile) { return file_size_modules(pfile) / sizeof(struct modules_record); }

void output_modules(FILE* input) {
    printf("Provide the number of records or to output all of them leave empty or type -1:\n");
    int n = validate_user_input_num(-1, -1);

    struct modules_record record;
    int count = 0;

    int column_width[] = {-4, -18};
    char* header[] = {"id", "name"};
    int header_len = sizeof(header) / sizeof(header[0]);

    output_header(column_width, header, header_len);
    while ((n == -1 || count < n) && fread(&record, sizeof(struct modules_record), 1, input)) {
        printf("%*d%*s\n", column_width[0], record.id, column_width[1], record.name);
        count++;
    }
}

void insert_modules(FILE* input) {
    printf("Name (1-%d characters):\n", MAX_MODULE_NAME);
    char name[MAX_MODULE_NAME];
    validate_user_input_str(1, MAX_MODULE_NAME, name);
    int records = records_count_modules(input);
    struct modules_record last_record = read_modules(input, records - 1);

    struct modules_record* new_record = calloc(1, sizeof(struct modules_record));
    new_record->id = last_record.id + 1;
    strcpy(new_record->name, name);
    write_modules(input, new_record, records);
    free(new_record);
    printf("Inserted successfully!\n");
}

void update_modules(FILE* input) {
    printf("ID of the record to update or to update all records leave empty or type -1:\n");
    int id = validate_user_input_num(-1, -1);
    printf("New value for field 'NAME' (1-%d characters) or to don't change leave empty:\n", MAX_MODULE_NAME);
    char name[MAX_MODULE_NAME];
    validate_user_input_str(0, MAX_MODULE_NAME, name);

    if (strlen(name) == 0) {
        printf("Nothing to update\n");
        return;
    }

    int i = 0;
    struct modules_record record;
    while (fread(&record, sizeof(struct modules_record), 1, input)) {
        if (id == -1 || record.id == id) {
            strcpy(record.name, name);
            write_modules(input, &record, i);
            if (id != -1) {
                printf("Updated successfully!\n");
                return;
            } else {
                fseek(input, (i + 1) * sizeof(struct modules_record), SEEK_SET);
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

void delete_modules(FILE* input) {
    printf("ID of the record to delete:\n");
    int id = validate_user_input_num(0, -1);

    struct modules_record record;
    int i = 0, idx = -1;
    while (fread(&record, sizeof(struct modules_record), 1, input)) {
        if (record.id == id) {
            idx = i;
            break;
        }
        i++;
    }
    if (idx != -1) {
        int n = records_count_modules(input);
        int k = n - idx - 1;
        struct modules_record records[k];
        fseek(input, (idx + 1) * sizeof(struct modules_record), SEEK_SET);
        fread(&records, sizeof(struct modules_record), k, input);
        fseek(input, idx * sizeof(struct modules_record), SEEK_SET);
        fwrite(records, sizeof(struct modules_record), k, input);
        ftruncate(fileno(input), (n - 1) * sizeof(struct modules_record));
        printf("Deleted successfully!\n");
    } else {
        printf("ID not found\n");
    }
}