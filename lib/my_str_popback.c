#ifndef STRING_POPBACK
#define STRING_POPBACK

#include "my_string.h"

int my_str_popback(my_str_t* str){
	//! Викидає символ з кінця.
	//! Повертає його, якщо успішно,
	//! Повертає RANGE_ERR або NULL_PTR_ERR, якщо відповідна помилка.
	if (!str){
		return NULL_PTR_ERR;
	}
	if (str->size_m < 1){
		return RANGE_ERR;
	}
	char c = str->data[str->size_m-1]; //store the character
	--str->size_m; //update string size
	str->data[str->size_m] = '\0'; //move termination symbol
	return c;
}

#endif