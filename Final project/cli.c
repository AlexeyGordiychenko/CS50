#include "cli.h"

int CURRENT_CODE = 0;

/*
main functions of the CLI
handles user input in the menu and delegates the process to the appropriate table handler
*/

int main(void) {
    char* options[] = {"SELECT", "INSERT", "UPDATE", "DELETE"};
    int options_len = sizeof(options) / sizeof(options[0]);

    char* tables[] = {"login", "modules", "doors"};
    int tables_len = sizeof(tables) / sizeof(tables[0]);

    int option = 0;
    CURRENT_CODE = get_current_code();
    printf("Welcome. ");
    do {
        print_options("Please choose one option:\n", options, options_len);
        option = validate_user_input_num(1, 5);

        switch (option) {
            case 1:
                faction outputs[] = {&output_login, &output_modules, &output_doors};
                display_menu(tables, outputs, tables_len, 0);

                break;
            case 2:
                faction inserts[] = {&insert_login, &insert_modules, &insert_doors};
                display_menu(tables, inserts, tables_len, 1);

                break;
            case 3:
                faction updates[] = {&update_login, &update_modules, &update_doors};
                display_menu(tables, updates, tables_len, 1);

                break;
            case 4:
                faction deletes[] = {&delete_login, &delete_modules, &delete_doors};
                display_menu(tables, deletes, tables_len, 1);

                break;
            default:
                break;
        }
    } while (option != 5);
}

void print_options(char* message, char* options[], int options_len) {
    printf("%s", message);
    for (int i = 0; i < options_len; i++) {
        printf("%4s%2d.%s\n", "", i + 1, options[i]);
    }
    printf("%4s%2d.%s\n", "", options_len + 1, "MAIN MENU / EXIT");
}

int table_choose(char* tables[], int tables_len) {
    print_options("Please choose a table:\n", tables, tables_len);
    return validate_user_input_num(1, tables_len + 1);
}

void display_menu(char* tables[], faction func[], int tables_len, int check_code) {
    int option_table = table_choose(tables, tables_len);
    if (option_table <= tables_len) {
        if (check_code && option_table != 1 && CURRENT_CODE != CORRECT_CODE) {
            printf(
                "Not available, the code is missing or incorrect.\nInsert or update the code in the login "
                "table.\n");
            return;
        }
        FILE* input = open_table(tables[option_table - 1], "r+");
        if (input == NULL) {
            printf("Error: corrupted database\n");
            return;
        }
        func[option_table - 1](input);
        fclose(input);
    }
}