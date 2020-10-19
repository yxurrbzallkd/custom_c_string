cmake_minimum_required(VERSION 3.10)

# Specify language
project(string C)

set(CMAKE_C_STANDARD 99)

# Gather source names
file(GLOB string_SRC
	"./lib/*.c",
)
message("Library sources:")
message(${string_SRC})

add_library(string SHARED ${string_SRC})
target_include_directories(string PRIVATE ./lib)
set_target_properties(string PROPERTIES OUTPUT_NAME string)

set(LIBRARY_HEADER ./lib/my_string.h)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

add_executable(main_test ./testing_test.c ${LIBRARY_HEADER})
target_link_libraries(main_test string)
target_include_directories(main_test PRIVATE ./lib)

add_executable(example ./example.c ${LIBRARY_HEADER})
target_link_libraries(example string)
target_include_directories(example PRIVATE ./lib)

set_target_properties( example main_test string
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ../
  LIBRARY_OUTPUT_DIRECTORY ../
  RUNTIME_OUTPUT_DIRECTORY ../
)