#include "login.h"

/*
functions to work with the login table
includes: reading, writing, getting number of records
          and functions to process queries
also there is a function get_current_code to get the current code at the start of the program
*/

struct login_record read_login(FILE* pfile, int index) {
    int offset = index * sizeof(struct login_record);
    fseek(pfile, offset, SEEK_SET);
    struct login_record record;
    fread(&record, sizeof(struct login_record), 1, pfile);
    rewind(pfile);
    return record;
}

void write_login(FILE* pfile, const struct login_record* record_to_write, int index) {
    int offset = index * sizeof(struct login_record);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct login_record), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

int file_size_login(FILE* pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int records_count_login(FILE* pfile) { return file_size_login(pfile) / sizeof(struct login_record); }

void output_login(FILE* input) {
    int column_width[] = {-4};
    char* header[] = {"code"};
    int header_len = sizeof(header) / sizeof(header[0]);

    output_header(column_width, header, header_len);
    if (records_count_login(input) > 0) {
        struct login_record record = read_login(input, 0);
        printf("%*d\n", column_width[0], record.code);
    }
}

void insert_login(FILE* input) {
    if (records_count_login(input) > 0) {
        printf("Table is not empty, update the code instead of inserting.\n");
        return;
    }

    printf("Code (4 digits):\n");
    int code = validate_user_input_num(0, 9999);

    struct login_record* new_record = calloc(1, sizeof(struct login_record));
    new_record->code = code;
    int records = records_count_login(input);
    write_login(input, new_record, records);
    free(new_record);
    printf("Inserted successfully!\n");
    CURRENT_CODE = code;
}

void update_login(FILE* input) {
    if (records_count_login(input) == 0) {
        printf("Table is empty, insert instead of updating.\n");
    } else {
        printf("Code (4 digits):\n");
        int code = validate_user_input_num(0, 9999);
        struct login_record current_record = read_login(input, 0);
        current_record.code = code;
        write_login(input, &current_record, 0);
        printf("Updated successfully!\n");
        CURRENT_CODE = code;
    }
}

void delete_login(FILE* input) {
    if (records_count_login(input) > 0) {
        ftruncate(fileno(input), 0);
        printf("Deleted successfully!\n");
    } else {
        printf("Nothing to delete\n");
    }
    CURRENT_CODE = 0;
}

int get_current_code() {
    FILE* input = open_table("login", "r+");
    int code = 0;

    if (input == NULL) {
        return code;
    }

    if (records_count_login(input) > 0) {
        code = read_login(input, 0).code;
    }

    fclose(input);
    return code;
}