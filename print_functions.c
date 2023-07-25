#include "main.h"
/*function to print a single character*/
int print_char(va_list arg)
{
        putchar(va_arg(arg, int));
        return (1);
}
/*function to print a string*/
int print_str(va_list arg)
{
        int i;
        char *str = va_arg(arg, char *);

        if (!str)
            str = "(null)";

        for (i = 0; str[i]; i++)
            putchar(str[i]);

        return (i);
}
/*function to print percentage sign*/
int print_mod(va_list arg)
{
	(void)arg;

	putchar('%');
	return (1);
}
/*function to print integer*/
int print_int(va_list arg)
{
	int number = va_arg(arg, int), len = 0;
	unsigned int digits = number;

	if (number < 0)
	{
		putchar('-');
		digits *= -1;
		len++;
	}
	else if (number == 0)
	{
		putchar('0');
		return (1);
	}
	len += int_helper(digits);
	return (len);
}

int int_helper(unsigned int value)
{
    int len;

    if (value == 0)
    {
        return (0);
    }
    len = (1 + int_helper(value / 10));
    putchar(value % 2 + '0');
    return (len);
}

int print_binary(va_list arg)
{
    long int number = va_arg(arg, long int);
    
    if (number == 0)
    {
        putchar('0');
        return (1);
    }
    else if (number > 0)
    	return (binary_helper(number));
    else
	return (0);
}

int binary_helper(long int value)
{
    int len = 0;

    if (value == 0)
        return (0);
    len = (1 + binary_helper(value / 2));
    putchar((value % 2) + '0');
    return (len);
}
