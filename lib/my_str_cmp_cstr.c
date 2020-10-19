#ifndef STRING_CMP_CSTR
#define STRING_CMP_CSTR


#include "my_string.h"

int my_str_cmp_cstr(const my_str_t* str1, const char* cstr2){
	//! Порівняти стрічку із С-стрічкою, повернути 0, якщо рівні (за вмістом!)
	//! -1 (або інше від'ємне значення), якщо перша менша,
	//! 1 (або інше додатне значення) -- якщо друга.
	//! Поведінка має бути такою ж, як в strcmp(). 
	if (!str1 | !cstr2){
		return NULL_PTR_ERR;
	}
	size_t l = length(cstr2);
	for (size_t i = 0; i < str1->size_m & i < l; i++){
		if (str1->data[i] > cstr2[i]){
			return 1;
		}
		else if (str1->data[i] < cstr2[i]){
			return -1;
		}
	}
	if (str1->size_m > l){
		return 1;
	}
	else if (str1->size_m < l){
		return -1;
	}
	return 0;
}

#endif