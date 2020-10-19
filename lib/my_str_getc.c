#ifndef STRING_GETC
#define STRING_GETC

#include "my_string.h"

char my_str_getc(const my_str_t* str, size_t index){
	//! Повертає символ у вказаній позиції,
	//! або коди помилок RANGE_ERR чи NULL_PTR_ERR.
	//! Тому, власне, int а не char
	if (!str){ //str is NULL
		return NULL_PTR_ERR;
	}
	if (index < 0 | index >= str->size_m){
		return RANGE_ERR;
	}
	return str->data[index];
}

#endif