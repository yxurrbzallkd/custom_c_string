#ifndef STRING_SHRINK
#define STRING_SHRINK

#include "my_string.h"

int my_str_shrink_to_fit(my_str_t* str){
	//! Робить буфер розміром, рівний необхідному:
	//! так, щоб capacity_m == size_m. Єдиний "офіційний"
	//! спосіб зменшити фактичний розмір буфера.
	//! У випадку помилки повертає MEMORY_ALLOCATION_ERR або
	//! NULL_PTR_ERR, якщо все ОК -- 0. 
	if (!str){
		return NULL_PTR_ERR;
	}
	if (str->size_m == str->capacity_m){
		return 0;
	}
	char *new_data = malloc(str->size_m + 1);
	if (!new_data){
		return MEMORY_ALLOCATION_ERR;
	}
	new_data[str->size_m] = '\0';
	for (size_t i = 0; i < str->size_m; i++){
		new_data[i] = str->data[i];
	}
	free(str->data);
	str->data = new_data;
	str->capacity_m = str->size_m;
	return 0;
}

#endif