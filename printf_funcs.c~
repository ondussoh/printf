#include "main.h"

int print_char(va_list arg)
{
        putchar(va_arg(arg, int));
        return (1);
}

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

int print_mod(va_list arg)
{
	(void)arg;

	putchar('%');
	return (1);
}
