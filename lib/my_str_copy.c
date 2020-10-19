#ifndef STRING_COPY
#define STRING_COPY


#include "my_string.h"

int my_str_copy(const my_str_t* from, my_str_t* to, int reserve){
	//! Копіює стрічку. Якщо reserve == true,
	//! то із тим же розміром буферу, що й вихідна, інакше:
	//! UPD: 09-20-2020: за можливості, скористатися наявним буфером або
	//! створити буфер мінімального достатнього розміру,
	//! якщо наявного буфера не вистачає. (Якщо створює новий буфер
	//! старий вміст стрічки to перед тим звільняє).
	//! Повертає 0, якщо успішно, різні від'ємні числа для діагностики
	//! проблеми некоректних аргументів. Список див. вище.
	if (!from || !to){
		return NULL_PTR_ERR;
	}
	int code = 0;
	if (reserve){
		int code = my_str_reserve(to, from->capacity_m);
	}
	else{
		if (from->size_m > to->capacity_m){
			int code = my_str_reserve(to, from->size_m);
		}
	}
	if (!(code >= 0)){
		return code;
	}
	for (size_t i = 0; i < from->size_m + 1; i++){
		to->data[i] = from->data[i];
	}
	to->size_m = from->size_m;
	to->data[to->size_m] = '\0';
	return 0;
}

#endif