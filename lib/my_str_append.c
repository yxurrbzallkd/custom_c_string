#ifndef STRING_APPEND
#define STRING_APPEND

#include "my_string.h"

int my_str_append(my_str_t* str, const my_str_t* from){
	//! Додати стрічку в кінець.
	//! За потреби -- збільшує буфер.
	//! У випадку помилки повертає NULL_PTR_ERR або MEMORY_ALLOCATION_ERR,
	//! якщо все ОК -- 0.
	if (!str || !from){
		return NULL_PTR_ERR;
	}
	size_t new_size = from->size_m + str->size_m;
	if (str->capacity_m < new_size){
		int code = my_str_reserve(str, 2*str->capacity_m);
		if (code < 0){
			return code;
		}
	}
	for (size_t i = 0; i < from->size_m; i++){
		str->data[i+str->size_m] = from->data[i];
	}
	str->size_m = new_size;
	str->data[new_size] = '\0';
	return 0;
}

#endif