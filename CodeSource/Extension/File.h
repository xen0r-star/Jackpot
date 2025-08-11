#pragma once

#include <stdbool.h>

int Read_file_int(char Section[0],char Element[0]);
bool Read_file_bool(char Section[0],char Element[0]);
char *Read_file_char(char Section[0],char Element[0]);

int Write_file(const char* file_name, int value);