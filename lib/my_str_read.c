#include "my_string.h"


int my_str_read(my_str_t* str){
	//! Аналог my_str_read_file, із stdin.
	//! У випадку помилки повертає відповідні коди помилок (див. список), якщо все ОК -- 0. 
	/* Preallocate space.  We could just allocate one char here, 
	but that wouldn't be efficient. */
	if(!str){
	    return NULL_PTR_ERR;
	}

	#define CHUNK_SIZE 1024 //we will be reading in chunks
	char buffer[CHUNK_SIZE];

	while(fgets(buffer, CHUNK_SIZE, stdin)) {
	    if(str->data == NULL)
	    {
	        my_str_empty(str);
	        return IO_READ_ERR;
	    }
		my_str_append_cstr(str, buffer);
		if (str->size_m == str->capacity_m){
			my_str_reserve(str, 2*str->capacity_m);
		}
	}

	if(ferror(stdin)){
	    free(str->data);
	    return IO_READ_ERR;
	}
	return 0; //OK
}