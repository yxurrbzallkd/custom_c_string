#ifndef STRING_PUTC
#define STRING_PUTC

#include "my_string.h"

int my_str_putc(my_str_t* str, size_t index, char c){
	//! Записує символ у вказану позиції (заміняючи той, що там був),
	//! Повертає 0, якщо позиція в межах стрічки, 
	//! Повертає RANGE_ERR чи NULL_PTR_ERR, не змінюючи її вмісту, якщо ні.
	if (!str){ //str is NULL
		return NULL_PTR_ERR;
	}
	if (index < 0 | index >= str->size_m){
		return RANGE_ERR;
	}
	str->data[index] = c;
	return 0;
}

#endif