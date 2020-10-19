#ifndef STRING_ERASE
#define STRING_ERASE

#include "my_string.h"

int my_str_erase(my_str_t* str, size_t beg, size_t end){
	//! Викидає символи із номерами [beg, end), зсуваючи залишок ліворуч.
	//! Якщо end більший за розмір -- це не помилка, зсувати всі наявні. 
	//! beg має бути в її межах -- якщо beg>size, це помилка.
	//! У випадку помилки повертає від'ємні числа, коди:
	//! RANGE_ERR, MEMORY_ALLOCATION_ERR, NULL_PTR_ERR, якщо все ОК -- 0.
	if (!(beg < str->size_m)){
		return RANGE_ERR;
	}
	if (end > str->size_m){
		end = str->size_m;
	}
	size_t j = beg;
	for (size_t i = end; i < str->size_m+1; i++){
		str->data[i] = str->data[j];
		j++;
	}
	str->data[j] = '\0'; //move termination symbol
	str->size_m = j;
	return 0;
}

#endif