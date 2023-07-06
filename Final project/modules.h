#include "shared.h"

struct modules_record read_modules(FILE* pfile, int index);
void write_modules(FILE* pfile, const struct modules_record* record_to_write, int index);
int file_size_modules(FILE* pfile);
int records_count_modules(FILE* pfile);
void output_modules(FILE* input);
void insert_modules(FILE* input);
void update_modules(FILE* input);
void delete_modules(FILE* input);