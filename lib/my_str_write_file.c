#include "my_string.h"

int my_str_write_file(const my_str_t* str, FILE* file){
	//! Записати стрічку в файл:
	//! У випадку помилки повертає відповідні коди помилок (див. список), якщо все ОК -- 0.
	int results = fputs(str->data, file);
	if (results == EOF) {
	    // Failed to write do error code here.
		return IO_WRITE_ERR;
	}
	fclose(file);
	return 0;
}