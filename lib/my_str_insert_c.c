#ifndef STRING_INSERT_C
#define STRING_INSERT_C

#include "my_string.h"

int my_str_insert_c(my_str_t* str, char c, size_t pos){
	//! Вставити символ у стрічку в заданій позиції, змістивши решту символів праворуч.
	//! За потреби -- збільшує буфер.
	//! Повертає 0, якщо успішно, коди помилок: NULL_PTR_ERR,
	//! MEMORY_ALLOCATION_ERR чи RANGE_ERR (якщо pos > str->size_m).
	if (!str){
		return NULL_PTR_ERR;
	}
	if (pos >= str->size_m | pos < 0){
		return RANGE_ERR;
	}
	if (str->capacity_m == str->size_m + 1){ //we are out of space
		my_str_reserve(str, 2*str->capacity_m);
	}
	for (size_t i = str->size_m; i > pos; i--){
		str->data[i] = str->data[i-1];
	}
	str->size_m++;
	str->data[pos] = c;
	str->data[str->size_m] = '\0';
	return 0;
}

#endif