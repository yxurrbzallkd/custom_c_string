#ifndef STRING_FREE
#define STRING_FREE

#include "my_string.h"

int my_str_free(my_str_t* str){
	// free memory by destroying string
	if (!str){
		return NULL_PTR_ERR;
	}
	free(str->data);
	return 0;
}

#endif