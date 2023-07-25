#ifndef MAIN_H
#define MAIN_H

/* Include necessary standard library header*/
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

/*Define a custom data structure for holding print format information*/
typedef struct print_format
{
  char symbol;            /*symbol rep the print frmt specifier*/
  int (*print)(va_list arg);  /*funo ptr to the  print function*/
} prt;

/*Function prototypes for different print function*/
int print_char(va_list arg);
int print_str(va_list arg);
int print_mod(va_list arg);
#endif
