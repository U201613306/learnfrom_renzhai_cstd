#pragma once
#include "../simple_core_minimal/simple_c_core/simple_core_minimal.h"

typedef enum e_error
{
	SIMPLE_C_SUCCESS = 0,
	SIMPLE_C_LOG,
	SIMPLE_C_WARNING,
	SIMPLE_C_ERROR,
};

_CRT_BEGIN_C_HEADER

const char *get_log_filename();
const char *get_log_path();

void init_log_system(const char *path);

//log
bool log_wirte(enum e_error error, char *format, ...);

#define log_success(...) log_wirte(SIMPLE_C_SUCCESS,__VA_ARGS__)
#define log_log(...) log_wirte(SIMPLE_C_LOG,__VA_ARGS__)
#define log_error(...) log_wirte(SIMPLE_C_ERROR,__VA_ARGS__)
#define log_warning(...) log_wirte(SIMPLE_C_WARNING,__VA_ARGS__)

_CRT_END_C_HEADER