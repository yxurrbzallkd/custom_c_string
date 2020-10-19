#ifndef STRING_RESERVE
#define STRING_RESERVE

#include "my_string.h"

int my_str_reserve(my_str_t* str, size_t buf_size){
	//! Збільшує буфер стрічки, із збереженням вмісту,
	//! якщо новий розмір більший за попередній,
	//! не робить нічого, якщо менший або рівний.
	//! (Як показує практика, це -- корисний підхід).
	//! Для збільшення виділяє новий буфер, копіює вміст
	//! стрічки (size_m символів -- немає сенсу копіювати
	//! решту буфера) із старого буфера та звільняє його.
	//! У випадку помилки повертає різні коди помилок:
	//! MEMORY_ALLOCATION_ERR або NULL_PTR_ERR, якщо все ОК -- 0.
	if (!str){
		return NULL_PTR_ERR;
	}
	if (buf_size <= str->capacity_m){
		return 0;
	}
	char * new_data = malloc(buf_size+1);
	if (!new_data){
		return MEMORY_ALLOCATION_ERR;
	}
	new_data[str->size_m] = '\0';
	for (size_t i = 0; i < str->size_m; i++){
		new_data[i] = str->data[i];
	}
	free(str->data);
	str->data = new_data;
	str->capacity_m = buf_size;
	return 0;
}

#endif