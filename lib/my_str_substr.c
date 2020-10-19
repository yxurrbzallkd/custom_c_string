#ifndef STRING_SUBSTR
#define STRING_SUBSTR

#include "my_string.h"

int my_str_substr(const my_str_t* from, my_str_t* to, size_t beg, size_t end){
	//! Скопіювати підстрічку, із beg включно, по end не включно ([beg, end)).
	//! Якщо end за межами початкової стрічки -- це не помилка, копіювати всі
	//! символи до кінця. beg має бути в її межах -- якщо beg>size, це помилка.
	//! За потреби -- збільшує буфер.
	//! У випадку помилки повертає від'ємні числа, коди:
	//! RANGE_ERR, MEMORY_ALLOCATION_ERR, NULL_PTR_ERR, якщо все ОК -- 0.
	if (!from || !to){
		return NULL_PTR_ERR;
	}
	if (beg > from->size_m){
		return RANGE_ERR;
	}
	if (end > from->size_m){
		end = from->size_m;
	}
	if (to->capacity_m < end-beg){
		free(to->data);
		to->data = malloc(from->size_m);
		to->capacity_m = from->size_m;
	}
	size_t j = 0;
	for (int i=beg; i<end; i++){
		to->data[j] = from->data[i];
		j++;
	}
	to->size_m = end-beg;
	to->data[to->size_m] = '\0';
	return 0;
}

#endif