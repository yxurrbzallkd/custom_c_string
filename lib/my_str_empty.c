#ifndef STRING_EMPTY
#define STRING_EMPTY

#include "my_string.h"

int my_str_empty(const my_str_t* str){
	if (!str){
		return NULL_PTR_ERR;
	}
	if (str->size_m > 0){
		return 0;
	}
	else{
		return 1;
	}
}

#endif