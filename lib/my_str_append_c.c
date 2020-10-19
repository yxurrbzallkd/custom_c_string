#ifndef STRING_APPEND_C
#define STRING_APPEND_C

#include "my_string.h"

int my_str_append_c(my_str_t* str, char c){
	//appends 1 character
	//! add error checks
	if (!str){
		return NULL_PTR_ERR;
	}
	if (str->capacity_m == str->size_m) //we are out of space
	{
		size_t new_buf_size = 2*(str->capacity_m+1);
		size_t code = my_str_reserve(str, new_buf_size);
		if (!(code >= 0)){
			return code;
		}
		str->capacity_m = new_buf_size;
	}
	str->data[str->size_m] = c; //write symbol at next free space
	++str->size_m; //update size of str
	str->data[str->size_m] = '\0';
	return 0;
}

#endif