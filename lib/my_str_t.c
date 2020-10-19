#ifndef STRING_STRUCT
#define STRING_STRUCT

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	char *data;
	size_t size_m;
	size_t capacity_m;
} my_str_t;

#endif