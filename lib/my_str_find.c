#ifndef STRING_FIND
#define STRING_FIND

#include "my_string.h"

size_t my_str_find(const my_str_t* str, const my_str_t* tofind, size_t from){
	if (!str || !tofind){
		return NULL_PTR_ERR;
	}
	//! Знайти першу підстрічку в стрічці, повернути номер її
	//! початку або (size_t)(-1), якщо не знайдено. from -- місце, з якого починати шукати.
	//! Якщо більше за розмір -- вважати, що не знайдено.
	//! Порожня tofind вважається такою, що не знайдена в str (не є підстрічкою).
	if (my_str_empty(tofind)){
		return -1;
	}
	if (!(from >= 0) | str->size_m < tofind->size_m | str->size_m-tofind->size_m<0){
		return -1;
	}
	//printf("%d %d\n", from, str->size_m-tofind->size_m);
	for (size_t i = from; i<str->size_m-tofind->size_m; i++){
		//printf("%d %d\n", i, str->size_m-tofind->size_m);
		size_t j = 0;
		while (str->data[i+j] == tofind->data[j]){
			j++;
		}
		if (j == tofind->size_m){
			return i;
		}
	}
	return -1;
}

#endif