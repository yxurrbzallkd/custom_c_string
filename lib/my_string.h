#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>

enum error_codes {NOT_FOUND_CODE=-1,\
				  MEMORY_ALLOCATION_ERR=-2,\
				  RANGE_ERR=-3,\
				  IO_READ_ERR=-4,\
				  IO_WRITE_ERR=-5,\
				  NULL_PTR_ERR=-8,\
				  BUFF_SIZE_ERR=-9};

#include "my_string_body.h"
#include "my_string_manipulation.h"
#include "my_string_rw.h"
#include "my_string_comparison.h"

#endif /* STRING_H */