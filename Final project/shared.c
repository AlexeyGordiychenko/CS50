#include "shared.h"

/*
functions: output_header and output_delimiter_row
output the header of a table with indentation
example:
======================
id  name
======================
*/
void output_header(int column_width[], char* header[], int header_len) {
    output_delimiter_row(column_width, header_len);
    printf("\n");
    for (int i = 0; i < header_len; i++) {
        printf("%*s", column_width[i], header[i]);
    }
    printf("\n");
    output_delimiter_row(column_width, header_len);
    printf("\n");
}

void output_delimiter_row(int column_width[], int n) {
    char d = '=';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < abs(column_width[i]); j++) {
            printf("%c", d);
        }
    }
}

/*
functions validate_user_input_num, validate_user_input_str
promt a user for an int or string in the given range
*/
int validate_user_input_num(int min, int max) {
    char* chk;
    char* input = NULL;
    size_t input_len;
    while (1) {
        input_len = getline(&input, &input_len, stdin);
        int num = strtol(input, &chk, 10);
        if (*chk == '\n' && input_len == 1) {
            num = -1;
        }
        if (*chk == '\n' && num >= min && (max == -1 || num <= max)) {
            free(input);
            return num;
        } else {
            printf("Invalid input, try again\n");
        }
    }
}

void validate_user_input_str(int min, int max, char* input) {
    char* line;
    size_t len = 0;
    int nread;
    while (1) {
        nread = getline(&line, &len, stdin);
        if (nread != -1 && (int)strcspn(line, "\n") == nread - 1) {
            nread--;
            if (nread >= min && nread <= max) {
                line[strcspn(line, "\n")] = 0;
                strcpy(input, line);
                break;
            }
        }
        printf("Invalid input, try again\n");
    }
    free(line);
}

// separate function to open a table with concatenation of the db folder
FILE* open_table(char* table_name, char* mode) {
    char* path = calloc(DB_FOLDER_LEN + strlen(table_name) + 1, 1);
    strcat(strcat(path, DB_FOLDER), table_name);
    FILE* input = fopen(path, mode);
    free(path);
    return input;
}