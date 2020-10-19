#include "my_string.h"

int main(){
	//find all words where there is a letter > u
	my_str_t string;
	my_str_create(&string, 0);
	FILE * fptr = fopen("words.txt", "r");
	my_str_read_file(&string, fptr);
	fclose(fptr);

	int predicat(int x) {
		return x > (int)'u';
	}

	my_str_t word;
	my_str_create(&word, 0);
	int id = 0;
	int start = 0;
	size_t end;
	while (start < string.size_m){
		id = my_str_find_c(&string, ' ', start);
		if (id > 0){
			my_str_substr(&string, &word, start, id);
			end = my_str_find_if(&word, 0, predicat);
			if (predicat(string.data[end])) {
				my_str_write(&word);
			}
			start = id+1;
		}
		else{
			start = start + word.size_m + 1;
		}
	}
	return 0;
}
