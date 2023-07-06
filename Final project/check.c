#include <stdio.h>
#include <string.h>

#include "shared.h"

/*
functionality to check all the conditions to end the puzzle
*/
int main(void) {
    FILE* login = open_table("login", "r");
    if (login == NULL) {
        printf(
            "Seems like the database is corrupted. That means you did something terrible, like deleted the "
            "database files...\n");
        return 0;
    }

    struct login_record login_record;
    if (!(fread(&login_record, sizeof(struct login_record), 1, login) && login_record.code == 9714)) {
        printf(
            "The door is still closed. You need to solve the riddle to get the code. And put it in the "
            "database.\n");
        fclose(login);
        return 0;
    }
    fclose(login);

    FILE* modules = open_table("modules", "r");
    if (modules == NULL) {
        printf(
            "Seems like the database is corrupted. That means you did something terrible, like deleted the "
            "database files...\n");
        return 0;
    }

    struct modules_record modules_record;
    int security_module_entry = 0;
    while (fread(&modules_record, sizeof(struct modules_record), 1, modules)) {
        if (strcmp(modules_record.name, "security") == 0) {
            security_module_entry = 1;
            break;
        }
    }
    fclose(modules);
    if (security_module_entry) {
        printf(
            "The door is still closed. The code seems right, but looks like the security module is blocking "
            "the door.\n");
        return 0;
    }

    FILE* doors = open_table("doors", "r");
    if (doors == NULL) {
        printf(
            "Seems like the database is corrupted. That means you did something terrible, like deleted the "
            "database files...\n");
        return 0;
    }

    struct doors_record doors_record;
    int doors_opened = 1;
    while (fread(&doors_record, sizeof(struct doors_record), 1, doors)) {
        if (doors_record.closed == 1) {
            doors_opened = 0;
            break;
        }
    }
    fclose(doors);
    if (!doors_opened) {
        printf(
            "The code seems right, the security module is removed, but you still can't get out. Looks like "
            "not all the doors are opened.\n");
        return 0;
    }

    printf("Congratulations! You've managed to escape this strange room.\n");
}
