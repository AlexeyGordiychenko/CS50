#include "shared.h"

struct login_record read_login(FILE* pfile, int index);
void write_login(FILE* pfile, const struct login_record* record_to_write, int index);
int file_size_login(FILE* pfile);
int records_count_login(FILE* pfile);
void output_login(FILE* input);
void insert_login(FILE* input);
void update_login(FILE* input);
void delete_login(FILE* input);