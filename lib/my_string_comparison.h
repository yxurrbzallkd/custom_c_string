#ifndef STRING_CMP_H
#define STRING_CMP_H


int my_str_cmp(const my_str_t* str1, const my_str_t* str2);
int my_str_cmp_cstr(const my_str_t* str1, const char* cstr2);
size_t my_str_find_c(const my_str_t* str, char tofind, size_t from);
size_t my_str_find_if(const my_str_t* str, size_t beg, int (*predicat)(int));
size_t my_str_find(const my_str_t* str, const my_str_t* tofind, size_t from);


#endif