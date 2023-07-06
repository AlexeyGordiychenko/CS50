#include "doors.h"
#include "login.h"
#include "modules.h"

typedef void (*faction)(FILE*);

void print_options(char* message, char* options[], int options_len);
void display_menu(char* tables[], faction func[], int tables_len, int check_code);
int get_current_code();