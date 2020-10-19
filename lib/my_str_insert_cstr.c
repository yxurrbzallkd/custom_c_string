#ifndef STRING_INSERT_CSTR
#define STRING_INSERT_CSTR

#include "my_string.h"

int my_str_insert_cstr(my_str_t* str, const char* from, size_t pos){
	//! Вставити C-стрічку в заданій позиції, змістивши решту символів праворуч.
	//! За потреби -- збільшує буфер.
	//! У випадку помилки повертає від'ємні числа, коди -- див. опис my_str_insert_c,
	//! якщо все ОК -- 0. 
	if (!str || !from){
		return NULL_PTR_ERR;
	}
	if (pos > str->size_m | pos < 0){
		return RANGE_ERR;
	}

	int l = length(from); //length of cstr to insert
	size_t new_size = str->size_m+l;
	if (str->capacity_m < new_size){
		int code = my_str_reserve(str, 2*(new_size));
		if (code < 0) //reserve failed
		{
			return code;
		}
	}

	for (size_t j = new_size - 1; j > pos; j--) //shift chars of original string
	{
		str->data[j] = str->data[j-l];
	}
	for (size_t j = 0; j < l; j++){  //insert new symbols into str
		str->data[pos+j] = from[j];
	}
	str->size_m = new_size;
	str->data[new_size] = '\0';  //add termination symbol
	return 0;
}

#endif