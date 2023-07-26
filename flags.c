#include "main.h"
/**
 * get_flags - Calculates active flags
 * @format: string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
    int j, curr_i;
    int flags = 0;
    const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    /*Loop through the format string starting from the position *i + 1*/
    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
      /*Loop through the predefined FLAGS_CH array to check for flag characters*/
        for (j = 0; FLAGS_CH[j] != '\0'; j++)
        {
	  /*If the current character in the format string matches a flag character*/
            if (format[curr_i] == FLAGS_CH[j])
            {
	      /*Set the corresponding flag bit using bitwise OR (|)*/
                flags |= FLAGS_ARR[j];
                break;
            }
        }

        /*If the loop completes without finding a matching flag character, break the loop*/
        if (FLAGS_CH[j] == 0)
            break;
    }

    /*Update the value of *i to the last processed index in the format string*/
    *i = curr_i - 1;

    /* Return the accumulated flags*/
    return flags;
}
