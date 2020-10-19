#ifndef STRING_GETCSTR
#define STRING_GETCSTR

#include "my_string.h"

const char* my_str_get_cstr(my_str_t* str){
	str->data[str->size_m] = '\0';
	return str->data;
}

#endif