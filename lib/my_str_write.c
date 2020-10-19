#include "my_string.h"

int my_str_write(const my_str_t* str){
	//! Записати стрічку на консоль:
	//! У випадку помилки повертає відповідні коди помилок (див. список), якщо все ОК -- 0.
	if (!str){
		return NULL_PTR_ERR;
	}
	/*
	for (size_t i = 0; i < str->size_m; i++){
		printf("%c", str->data[i]);
	}
	printf("\n");*/
	if (my_str_empty(str)){
		printf("\n");
	}
	else{
		printf("%s\n", str->data);
	}
	return 0;
}