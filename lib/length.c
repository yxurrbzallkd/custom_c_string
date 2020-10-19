#include "my_string.h"

int length(const char *str){
	size_t i = 0;
	while (str[i] != '\0'){
		i++;
	}
	return i;
}
