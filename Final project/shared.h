#ifndef SHARED_H
#define SHARED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// the max length of the field 'Name' of the table Modules
#define MAX_MODULE_NAME 30
// the path to the folder where the database files are located
#define DB_FOLDER "db/"
#define DB_FOLDER_LEN strlen(DB_FOLDER)

typedef struct login_record {
    int code;
} login_record;

typedef struct doors_record {
    int id;
    int room;
    int closed;
} doors_record;

typedef struct modules_record {
    int id;
    char name[MAX_MODULE_NAME + 1];
} modules_record;

// the value and the global variable for the correct code to access the db
#define CORRECT_CODE 9714
extern int CURRENT_CODE;

void output_header(int column_width[], char* header[], int header_len);
void output_delimiter_row(int column_width[], int n);
int validate_user_input_num(int min, int max);
void validate_user_input_str(int min, int max, char* input);
FILE* open_table(char* table_name, char* mode);
#endif