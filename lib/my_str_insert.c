#ifndef STRING_INSERT
#define STRING_INSERT


#include "my_string.h"

int my_str_insert(my_str_t* str, const my_str_t* from, size_t pos){
	//! Вставити стрічку в заданій позиції, змістивши решту символів праворуч.
	//! За потреби -- збільшує буфер.
	//! У випадку помилки повертає від'ємні числа, коди - my_str_insert_c,
	//! якщо все ОК -- 0.
	if (!str || !from){
		return NULL_PTR_ERR;
	}
	if (pos >= str->size_m | pos < 0){
		return RANGE_ERR;
	}
	size_t new_size = str->size_m+from->size_m;
	if (str->capacity_m < new_size){
		size_t new_buf_size = 2*(new_size) + 1;
		int code = my_str_reserve(str, new_buf_size);
		if (!(code >= 0)){
			return code;
		}
	}

	for (size_t j = new_size-1; j > pos+from->size_m-1; j--){
		str->data[j] = str->data[j-from->size_m];
	}
	for (size_t j = 0; j < from->size_m; j++){
		str->data[pos+j] = from->data[j];
	}
	str->size_m = new_size;
	str->data[new_size] = '\0';  //add termination symbol
	return 0;
}


#endif