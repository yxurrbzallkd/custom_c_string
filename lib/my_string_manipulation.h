#ifndef STRING_MANIPULATION_H
#define STRING_MANIPULATION_H

int length(const char *str);
char my_str_getc(const my_str_t* str, size_t index);
int my_str_putc(my_str_t* str, size_t index, char c);
int my_str_copy(const my_str_t* from, my_str_t* to, int reserve);
int my_str_clear(my_str_t* str);
int my_str_insert_c(my_str_t* str, char c, size_t pos);
int my_str_insert(my_str_t* str, const my_str_t* from, size_t pos);
int my_str_insert_cstr(my_str_t* str, const char* from, size_t pos);
int my_str_append_c(my_str_t* str, char c);
int my_str_append(my_str_t* str, const my_str_t* from);
int my_str_append_cstr(my_str_t* str, const char* from);
int my_str_substr(const my_str_t* from, my_str_t* to, size_t beg, size_t end);
int my_str_substr_cstr(const my_str_t* from, char* to, size_t beg, size_t end);
int my_str_erase(my_str_t* str, size_t beg, size_t end);
int my_str_popback(my_str_t* str);


#endif