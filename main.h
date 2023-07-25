#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

/*Define a struct to hold information about each print format specifier*/
typedef struct print_format
{
  char symbol;          /*the cha that represents the format specifier*/
  int (*print)(va_list arg); /*function pointer to the corresponding print function*/
} prt;

/*Function prototypes for the different print functions*/
int print_char(va_list arg);
int print_str(va_list arg);
int print_mod(va_list arg);

/* Function prototype for the custom printf function*/
int _printf(const char *format, ...);

#endif
