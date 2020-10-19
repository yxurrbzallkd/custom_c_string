#ifndef STRING_CMP
#define STRING_CMP

#include "my_string.h"

int my_str_cmp(const my_str_t* str1, const my_str_t* str2){
	//! Порівняти стрічки, повернути 0, якщо рівні (за вмістом!)
	//! -1 (або інше від'ємне значення), якщо перша менша,
	//! 1 (або інше додатне значення) -- якщо друга.
	//! Поведінка має бути такою ж, як в strcmp() -- порівняння лексикографічне.
	//! Зокрема, для strcmp() описано, що значить "менше" чи "більше".
	if (!str1 | !str2){
		return NULL_PTR_ERR;
	}
	for (size_t i = 0; i < str1->size_m & i < str2->size_m; i++){
		if (str1->data[i] > str2->data[i]){
			return 1;
		}
		else if (str1->data[i] < str2->data[i]){
			return -1;
		}
	}
	if (str1->size_m > str2->size_m){
		return 1;
	}
	else if (str1->size_m < str2->size_m){
		return -1;
	}
	return 0;
}

#endif