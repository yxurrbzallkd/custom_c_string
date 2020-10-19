#ifndef STRING_SUBSTR_CSTR
#define STRING_SUBSTR_CSTR

#include "my_string.h"

int my_str_substr_cstr(const my_str_t* from, char* to, size_t beg, size_t end){
	//! C-string варіант my_str_substr().
	//! Вважати, що в цільовій С-стрічці достатньо місця.
	//! У випадку помилки повертає від'ємні числа, коди:
	//! RANGE_ERR або NULL_PTR_ERR, якщо все ОК -- 0.
	if (!from || !to){
		return NULL_PTR_ERR;
	}
	if (beg > from->size_m | beg < 0 | sizeof(to) < end-beg){
		return RANGE_ERR;
	}
	if (end > from->size_m){
		end = from->size_m;
	}
	for (size_t i=beg; i<end; i++){
		to[i-beg] = from->data[i];
	}
	return 0;
}

#endif