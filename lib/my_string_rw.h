#ifndef STRING_RW_H
#define STRING_RW_H

int my_str_read_file(my_str_t* str, FILE* file);
int my_str_read(my_str_t* str);
int my_str_read_file_delim(my_str_t* str, FILE* file, char delimiter);
int my_str_write_file(const my_str_t* str, FILE* file);
int my_str_write(const my_str_t* str);

#endif