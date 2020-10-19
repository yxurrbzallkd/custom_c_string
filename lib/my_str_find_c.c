#ifndef STRING_FIND_C
#define STRING_FIND_C

#include "my_string.h"

size_t my_str_find_c(const my_str_t* str, char tofind, size_t from){
	//! Знайти перший символ в стрічці, повернути його номер
	//! або (size_t)(-1), якщо не знайдено. from -- місце, з якого починати шукати.
	//! Якщо більше за розмір -- вважати, що не знайдено. 
	if (!str | !tofind){
		return NULL_PTR_ERR;
	}
	for (size_t i = from; i < str->size_m; i++){
		if (str->data[i] == tofind){
			return i;
		}
	}
	return -1;
}

#endif