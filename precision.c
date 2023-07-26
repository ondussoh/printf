#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	/* Initialize variables */
	int curr_i = *i + 1;
	int precision = -1;

	/* Check if current char is not '.', rtn default precision (-1) */
	if (format[curr_i] != '.')
		return (precision);

	/* Initialize precision to 0 */
	precision = 0;

	/* Loop thru the frmt string to extract the precision value */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		/* If char is a digit, update the precision value accordingly */
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		/* If the char is '*', extract the precision from  va_list arg */
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		/* If the character is not a digit or '*', break the loop */
		else
		{
			break;
		}
	}

	/* Update value of *i 2 last processed index in frmt string */
	*i = curr_i - 1;

	/* Return the calculated precision value */
	return (precision);
}
