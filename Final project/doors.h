

#include "shared.h"

struct doors_record read_doors(FILE* pfile, int index);
void write_doors(FILE* pfile, const struct doors_record* record_to_write, int index);
int file_size_doors(FILE* pfile);
int records_count_doors(FILE* pfile);
void output_doors(FILE* input);
void insert_doors(FILE* input);
void update_doors(FILE* input);
void delete_doors(FILE* input);