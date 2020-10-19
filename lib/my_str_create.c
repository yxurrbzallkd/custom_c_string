#ifndef STRING_CREATE
#define STRING_CREATE

#include "my_string.h"

int my_str_create(my_str_t* str, size_t buf_size){
	if (!str) //str is NULL
	{
		return NULL_PTR_ERR;
	}
	str->data = malloc(buf_size + 1); //allocate memory for string of size buf_size + 1 space for '\0' symbol
	if (!str->data){
		return MEMORY_ALLOCATION_ERR;
	}
	str->size_m = 0; //string is empty, for now
	str->capacity_m = buf_size;
	return 0; //process completed successfully - no errors occured
}

#endif