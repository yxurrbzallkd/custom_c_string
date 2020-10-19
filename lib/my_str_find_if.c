#ifndef STRING_FIND_IF
#define STRING_FIND_IF

#include "my_string.h"

size_t my_str_find_if(const my_str_t* str, size_t beg, int (*predicat)(int)){
	//! Знайти символ в стрічці, починаючи із beg, для якого передана
	//! функція повернула true, повернути його номер
	//! або (size_t)(-1), якщо не знайдено або beg >= size_m.
	//! Якщо predicat == NULL, вважати, що він завжди повертає false.
	if (!str){
		return NULL_PTR_ERR;
	}
	if (!predicat){
		return (size_t) 0;
	}
	for (size_t i = beg; i < str->size_m; i++){
		if (predicat(str->data[i]) == 1){
			return i;
		}
	}
	return (size_t)(-1);
}

#endif