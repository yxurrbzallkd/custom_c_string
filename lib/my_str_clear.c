#ifndef STRING_CLEAR
#define STRING_CLEAR


#include "my_string.h"

int my_str_clear(my_str_t* str){
	//! Очищає стрічку -- робить її порожньою. Складність має бути О(1). 
	//! Уточнення (чомусь ця функція викликала багато непорозумінь):
	//! стрічка продовжує існувати, буфер той самий, того ж розміру, що був,
	//! лише містить 0 символів -- єдине, що вона робить, це size_m = 0.
	//! Може завжди повертати нуль.
	//! Повинна перевіряти, чи str != NULL, і якщо так -- просто повернути 0.
	//! Припустимим є також повернути NULL_PTR_ERR (по принципу fail fast).
	if (!str){
		return NULL_PTR_ERR;
	}
	str->size_m = 0;
	return 0;
}

#endif