#include "my_string.h"

int my_str_read_file_delim(my_str_t* str, FILE* file, char delimiter){
	//! На відміну від my_str_read_file(), яка читає до кінця файлу,
	//! читає по вказаний delimiter, за потреби
	//! збільшує стрічку.
	//! У випадку помилки повертає відповідні коди помилок (див. список), якщо все ОК -- 0. 
	if (!file || !str)
        return NULL_PTR_ERR; //could not open file

	char c;
	size_t code;
    while ((c = fgetc(file)) != EOF & c != delimiter){
		if (c == delimiter){
			break;
		}
        code = my_str_append_c(str, c);
		if (!(code >= 0)){
			return code;
		}
    }
    return 0;
}