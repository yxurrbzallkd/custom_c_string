#include "my_string.h"

int my_str_read_file(my_str_t* str, FILE* file){
	//! Прочитати стрічку із файлу. Читає цілий файл.
	//! Не давайте читанню вийти за межі буфера! За потреби --
	//! збільшуйте буфер.
	//! Рекомендую скористатися fgets().
	//! У випадку помилки повертає відповідні коди помилок (див. список),
	//! якщо все ОК -- 0.
    //FILE *file = fopen(fileName, "r");
	//change to reading in chunks, instead of single chars?
	if((!str) || (!file)){
	    return NULL_PTR_ERR;
	}

	#define CHUNK_SIZE 1024 //we will be reading in chunks
	char buffer[CHUNK_SIZE];

	while(fgets(buffer, CHUNK_SIZE, file) != NULL) {
	    if(str->data == NULL) {
	        my_str_empty(str);
	        return IO_READ_ERR;
	    }
		my_str_append_cstr(str, buffer);
		if (str->size_m == str->capacity_m){
			my_str_reserve(str, 2*str->capacity_m);
		}
	}
	int i = 0;
	while (buffer[i] != EOF){
		i ++;
	}
	str->data[str->size_m-CHUNK_SIZE+i] = '\0';    
	return 0; //OK
}