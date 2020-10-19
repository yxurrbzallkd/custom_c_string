#ifndef STRING_BODY_H
#define STRING_BODY_H

#include "my_str_t.c"


int my_str_create(my_str_t* str, size_t buf_size);
int my_str_free(my_str_t* str);
int my_str_empty(const my_str_t* str);
int my_str_reserve(my_str_t* str, size_t buf_size);
int my_str_from_cstr(my_str_t* str, const char* cstr, size_t buf_size);
int my_str_shrink_to_fit(my_str_t* str);
const char* my_str_get_cstr(my_str_t* str);

#endif