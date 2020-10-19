#ifndef STRING_APPEND_CSTR
#define STRING_APPEND_CSTR

#include "my_string.h"

int my_str_append_cstr(my_str_t* str, const char* from){
	size_t l = length(from);
	//is there enough space?
	if (str->capacity_m <= str->size_m + l) //we are out of space
	{
		size_t code = my_str_reserve(str, str->size_m + l);
		if (!(code >= 0)){
			return code;
		}
	}
	size_t i = str->size_m;
	for (size_t j = 0; j < l; j++){
		str->data[i] = from[j];
		i++;
	}
	str->size_m = str->size_m+l; //update size of str
	str->data[str->size_m] = '\0';
	return 0;
}

#endif