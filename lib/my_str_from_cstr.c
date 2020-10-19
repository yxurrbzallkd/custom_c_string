#ifndef STRING_FROM_CSTR
#define STRING_FROM_CSTR

#include "my_string.h"

int my_str_from_cstr(my_str_t* str, const char* cstr, size_t buf_size){
	if (!str || !cstr){
		return NULL_PTR_ERR;
	}
	str->data = malloc(buf_size+1);
	if (!(str->data)){
		return MEMORY_ALLOCATION_ERR;
	}
	size_t i = 0;
	while (cstr[i] != '\0' & i < buf_size){
		str->data[i] = cstr[i];
		i++;
	}
	str->capacity_m = buf_size;
	str->size_m = i;
	str->data[str->size_m] = '\0';
	return 0;
}

#endif