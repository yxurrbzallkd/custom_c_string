#include "my_string.h"
#include <assert.h>
#include <string.h>  //only for test

void test_my_str_create(){
	my_str_t str;
	my_str_create(&str, 2);
	assert(str.capacity_m == 2);
	assert(str.size_m == 0);
	assert(my_str_free(&str) == 0);
	printf("my_str_create test - SUCESS\n");
}

void test_my_str_from_cstr(){
	//!! WHAT IF WE PASSED LESS MEMORY??? ADD CHECKS
	my_str_t str;
	size_t buf_size = 10;
	char *cstr = "abcd";
	my_str_from_cstr(&str, "abcd", buf_size);
	assert(str.capacity_m == buf_size);
	assert(str.size_m == strlen(cstr));
	for (size_t i = 0; i < strlen("abcd"); i++){
		assert(str.data[i] == cstr[i]);
	}
	assert(my_str_free(&str) == 0);
	printf("my_str_from_cstr test - SUCESS\n");
}

void test_my_str_free(){
	my_str_t str;
	my_str_from_cstr(&str, "hello world", 20);
	assert(&str);
	assert(my_str_free(&str) == 0);
	printf("my_str_free test - SUCESS\n");
}

void test_my_str_empty(){
	my_str_t str1;
	my_str_create(&str1, 0);
	assert(my_str_empty(&str1));
	my_str_t str2;
	my_str_from_cstr(&str2, "hello world", 20);
	assert(my_str_empty(&str2) == 0);
	assert(my_str_empty(NULL) == NULL_PTR_ERR);

	assert(my_str_free(&str1) == 0);
	assert(my_str_free(&str2) == 0);
	printf("my_str_empty test - SUCESS\n");
}

void test_my_str_shrink_to_fit(){
	my_str_t str;
	my_str_from_cstr(&str, "aa", 15);
	assert(str.capacity_m == 15 & str.size_m == 2);
	my_str_shrink_to_fit(&str);
	assert(str.size_m == str.capacity_m);  //buffer size same as string size (+terminator)
	assert(my_str_free(&str) == 0);
	printf("my_str_shrink_to_fit test - SUCESS\n");
}

void test_my_str_reserve(){
	my_str_t str;
	my_str_from_cstr(&str, "aa", 5);
	assert(str.capacity_m == 5 & str.size_m == 2);
	my_str_reserve(&str, 15);
	assert(str.capacity_m == 15);  //buffer size same as string size (+terminator)
	for (size_t i = 0; i < str.size_m; i++){
		assert(str.data[i] == 'a');
	}
	assert(my_str_free(&str) == 0);
	printf("my_str_reserve test - SUCESS\n");
}

void test_my_str_get_cstr(){
	my_str_t str;
	my_str_from_cstr(&str, "aa", 15);
	const char* cstr = my_str_get_cstr(&str);
	for (size_t i = 0; i < str.size_m; i++){
		assert(cstr[i] == str.data[i]);
	}
	assert(my_str_free(&str) == 0);
	printf("my_str_get_cstr test - SUCESS\n");
}

int test_string_body(){
	printf("\nCreating and destroying strings\n");
	test_my_str_create();
	test_my_str_from_cstr();
	test_my_str_free();
	test_my_str_empty();
	test_my_str_reserve();
	test_my_str_shrink_to_fit();
	test_my_str_get_cstr();
}

int test_my_str_cmp(){
	my_str_t str1;
	my_str_from_cstr(&str1, "ab", 2);
	my_str_t str1A;
	my_str_from_cstr(&str1A, "ab", 3);
	my_str_t str2;
	my_str_from_cstr(&str2, "abb", 4);
	my_str_t str3;
	my_str_from_cstr(&str3, "aaa", 5);
	my_str_t str4;
	my_str_from_cstr(&str4, "aa", 3);

	assert(my_str_cmp(&str1, &str2) == -1);
	assert(my_str_cmp(&str2, &str3) == 1);
	assert(my_str_cmp(&str1, &str1A) == 0);
	assert(my_str_cmp(&str3, &str4) == 1);

	assert(my_str_free(&str1) == 0);
	assert(my_str_free(&str2) == 0);
	assert(my_str_free(&str1A) == 0);
	assert(my_str_free(&str3) == 0);
	assert(my_str_free(&str4) == 0);
	printf("my_str_cmp test - SUCESS\n");
	return 1;
}

int test_my_str_cmp_cstr(){
	my_str_t str;
	my_str_from_cstr(&str, "ab", 2);

	assert(my_str_cmp_cstr(&str, "aaaa") == 1);
	assert(my_str_cmp_cstr(&str, "bb") == -1);
	assert(my_str_cmp_cstr(&str, "ab") == 0);

	assert(my_str_free(&str) == 0);
	printf("my_str_cmp_cstr test - SUCESS\n");
	return 1;
}

int test_my_str_find_c(){
	my_str_t str;
	my_str_from_cstr(&str, "abcdefab", 10);

	assert(my_str_find_c(&str, 'k', 0) == -1);
	assert(my_str_find_c(&str, 'a', 0) == 0);
	assert(my_str_find_c(&str, 'a', 2) == 6);
	assert(my_str_find_c(&str, 'c', 0) == 2);

	assert(my_str_free(&str) == 0);
	printf("my_str_find_c test - SUCESS\n");
	return 1;
}

int test_my_str_find(){
	my_str_t str1;
	my_str_from_cstr(&str1, "abbaababbbb", 20);
	my_str_t str2;
	my_str_from_cstr(&str2, "ab", 10);
	my_str_t str3;
	my_str_create(&str3, 0);

	assert(my_str_find(&str1, &str2, 0) == 0);
	assert(my_str_find(&str1, &(str2), 7) == -1);
	assert(my_str_find(&str2, &str1, 0) == -1);
	assert(my_str_find(&str1, &str3, 0) == -1);

	assert(my_str_free(&str1) == 0);
	assert(my_str_free(&str2) == 0);
	assert(my_str_free(&str3) == 0);
	printf("my_str_find test - SUCESS\n");
	return 1;
}

int test_my_str_find_if(){
	my_str_t str1;
	my_str_from_cstr(&str1, "abbaababbbb", 20);

	int predicatK(int x){
		return (int)'k' < x;
	}
	assert(my_str_find_if(&str1, 1, *predicatK) == -1);
	int predicatB(int x){
		return (int)'b' == x;
	}
	assert(my_str_find_if(&str1, 3, *predicatB) == 5);
	assert(my_str_find_if(&str1, 16, *predicatB) == -1);
	assert(my_str_find_if(&str1, -6, *predicatB) == -1);
	assert(my_str_find_if(&str1, 0, NULL) == 0);

	assert(my_str_free(&str1) == 0);
	printf("my_str_find test - SUCESS\n");
	return 1;
}

int test_string_comparison(){
	printf("\nComparing and finding in strings\n");
	test_my_str_cmp();
	test_my_str_cmp_cstr();
	test_my_str_find_c();
	test_my_str_find_if();
	test_my_str_find();
}

int test_my_str_putc(){
	my_str_t str1;
	my_str_from_cstr(&str1, "ab", 3);

	assert(my_str_putc(&str1, 2, 'c') == RANGE_ERR);
	assert(my_str_putc(NULL, 0, 'c') == NULL_PTR_ERR);
	assert(my_str_putc(&str1, -4, 'c') == RANGE_ERR);
	assert(my_str_putc(&str1, 1, 'c') == 0);
	assert(str1.data[1] == 'c');

	assert(my_str_free(&str1) == 0);
	printf("my_str_putc test - SUCESS\n");
	return 1;
}

int test_my_str_getc(){
	my_str_t str1;
	my_str_from_cstr(&str1, "ab", 3);

	assert(my_str_getc(&str1, 2) == RANGE_ERR);
	assert(my_str_getc(NULL, 0) == NULL_PTR_ERR);
	assert(my_str_getc(&str1, -1) == RANGE_ERR);
	assert(my_str_getc(&str1, 1) == 'b');

	assert(my_str_free(&str1) == 0);
	printf("my_str_getc test - SUCESS\n");
	return 1;
}

int test_my_str_copy(){
	my_str_t str1;
	my_str_from_cstr(&str1, "ab", 3);
	my_str_t str2;
	my_str_create(&str2, 0);

	assert(my_str_copy(&str1, &str2, 1) == 0);
	assert(my_str_cmp(&str1, &str2) == 0);

	assert(my_str_free(&str1) == 0);
	assert(my_str_free(&str2) == 0);
	printf("my_str_copy test - SUCESS\n");
	return 1;
}

int test_my_str_clear(){
	my_str_t str1;
	my_str_from_cstr(&str1, "5", 3);

	assert(my_str_clear(&str1) == 0);
	assert(str1.size_m == 0);

	assert(my_str_free(&str1) == 0);
	printf("my_str_clear test - SUCESS\n");
	return 1;
}

int test_my_str_insert_c(){
	my_str_t str1;
	my_str_from_cstr(&str1, "abc", 7);

	assert(my_str_insert_c(&str1, '?', 9) == RANGE_ERR);
	assert(my_str_insert_c(&str1, '?', 2) == 0);
	assert(str1.data[2] == '?');

	assert(my_str_free(&str1) == 0);
	printf("my_str_insert_c test - SUCESS\n");
	return 1;
}

int test_my_str_insert(){
	my_str_t str1;
	my_str_from_cstr(&str1, "abc", 7);
	my_str_t str2;
	my_str_from_cstr(&str2, "aa", 3);

	assert(my_str_insert(&str1, &str2, 10) == RANGE_ERR);
	assert(my_str_insert(&str1, &str2, -2) == RANGE_ERR);
	assert(my_str_insert(&str1, &str2, 1) == 0);
	assert(my_str_cmp_cstr(&str1, "aaabc") == 0);

	assert(my_str_free(&str1) == 0);
	assert(my_str_free(&str2) == 0);
	printf("my_str_insert test - SUCESS\n");
	return 1;
}

int test_my_str_insert_cstr(){
	my_str_t str;
	my_str_from_cstr(&str, "abc", 7);

	assert(my_str_insert_cstr(&str, "af", 10) == RANGE_ERR);
	assert(my_str_insert_cstr(&str, "af", -2) == RANGE_ERR);
	assert(my_str_insert_cstr(&str, "ff", 2) == 0);
	assert(my_str_cmp_cstr(&str, "abffc") == 0);

	assert(my_str_free(&str) == 0);
	printf("my_str_insert_cstr test - SUCESS\n");
	return 1;
}

int test_my_str_append_c(){
	my_str_t str;
	my_str_from_cstr(&str, "abc", 7);

	assert(my_str_append_c(&str, 'a')==0);
	assert(str.data[str.size_m-1] == 'a');

	assert(my_str_free(&str) == 0);
	printf("my_str_append_c test - SUCESS\n");
	return 1;
}

int test_my_str_append(){
	my_str_t str1;
	my_str_from_cstr(&str1, "abc", 7);
	my_str_t str2;
	my_str_from_cstr(&str2, "aa", 3);

	assert(my_str_append(&str1, &str2) == 0);
	assert(my_str_cmp_cstr(&str1, "abcaa") == 0);

	assert(my_str_free(&str1) == 0);
	assert(my_str_free(&str2) == 0);
	printf("my_str_append test - SUCESS\n");
	return 1;
}

int test_my_str_append_cstr(){
	my_str_t str1;
	my_str_from_cstr(&str1, "abc", 7);

	assert(my_str_append_cstr(&str1, "aa") == 0);
	assert(my_str_cmp_cstr(&str1, "abcaa") == 0);

	assert(my_str_free(&str1) == 0);
	printf("my_str_append_cstr test - SUCESS\n");
	return 1;
}

int test_my_str_substr(){
	my_str_t str1;
	my_str_from_cstr(&str1, "abcabc", 7);
	my_str_t str2;
	my_str_create(&str2, 0);

	assert(my_str_substr(&str1, &str2, 2, 4) == 0);
	assert(my_str_cmp_cstr(&str2, "ca") == 0);

	assert(my_str_free(&str1) == 0);
	assert(my_str_free(&str2) == 0);
	printf("my_str_substr test - SUCESS\n");
	return 1;
}

int test_my_str_substr_cstr(){
	my_str_t str1;
	my_str_from_cstr(&str1, "abcabc", 7);

	char str2[4];
	assert(my_str_substr_cstr(&str1, str2, 2, 4) == 0);
	assert(str2[0] =='c' & str2[1] =='a' );

	assert(my_str_free(&str1) == 0);
	printf("my_str_substr_cstr test - SUCESS\n");
	return 1;
}


int test_my_str_erase(){
	my_str_t str1;
	my_str_from_cstr(&str1, "abcabc", 7);
	my_str_t str2;
	my_str_from_cstr(&str2, "abc", 7);

	assert(my_str_erase(&str1, 0, 4) == 0);
	assert(my_str_cmp(&str2, &str1) == 0);

	assert(my_str_free(&str1) == 0);
	assert(my_str_free(&str2) == 0);
	printf("my_str_erase test - SUCESS\n");
	return 1;
}


int test_my_str_popback(){
	my_str_t str;
	my_str_from_cstr(&str, "ab", 2);

	assert(my_str_popback(&str) == 'b');
	assert(str.data[str.size_m-1] == 'a');
	assert(my_str_popback(&str) == 'a');
	assert(my_str_popback(&str) == RANGE_ERR);

	assert(my_str_free(&str) == 0);
	printf("my_str_popback test - SUCESS\n");
	return 1;
}

int test_string_manipulation(){
	printf("\nChanging & Manipulating strings\n");

	test_my_str_putc();
	test_my_str_getc();
	test_my_str_copy();
	test_my_str_clear();
	test_my_str_insert_c();
	test_my_str_insert();
	test_my_str_insert_cstr();
	test_my_str_append_c();
	test_my_str_append();
	test_my_str_append_cstr();
	test_my_str_substr();
	test_my_str_substr_cstr();
	test_my_str_erase();
	test_my_str_popback();
}

void test_io(){
	printf("\nTesting read and write\n");
	my_str_t string;
	my_str_from_cstr(&string, "Hello\nWorld\n!", 20);
	//testing my_str_write
	FILE * fPtr_write;
	fPtr_write = fopen("file.txt", "w");
	assert(my_str_write_file(&string, fPtr_write) == 0);
	//fclose(fPtr_write);
	printf("my_str_write_file - SUCESS\n");


	FILE * fPtr_read = fopen("file.txt", "r");
	my_str_t contents;
	my_str_create(&contents, 0);
	assert(my_str_read_file(&contents, fPtr_read) == 0);
	printf("my_str_read_file - SUCESS\n");
	fclose(fPtr_read);

	assert(my_str_cmp(&string, &contents) == 0);
	printf("contents read same as contents written - SUCESS\n");

	FILE * fPtr_read_delim  = fopen("file.txt", "r");
	my_str_t to_delim;
	my_str_create(&to_delim, 4);
	assert(my_str_read_file_delim(&to_delim, fPtr_read_delim, 'o') == 0);
	assert(my_str_cmp_cstr(&to_delim, "Hell") == 0);
	fclose(fPtr_read_delim);
	printf("my_str_read_file_delim - SUCESS\n");
	printf("read \"Hello\\nWorld\\n!\" to delimiter = 'o'\" == 'Hell'\n");

	/*
	my_str_t from_stdin;
	my_str_create(&from_stdin, 4);
	my_str_write(&string);
	//FINISH READ FROM STDIN
	my_str_read(&from_stdin);
	assert(my_str_cmp(&from_stdin, &to_delim)==0);
	my_str_free(&from_stdin);
	*/

	my_str_free(&string);
	my_str_free(&to_delim);
	my_str_free(&contents);
	return;
}

int main(){
	printf("Testing String Library\n");
	test_string_body();
	test_string_comparison();
	test_string_manipulation();
	test_io();
}
