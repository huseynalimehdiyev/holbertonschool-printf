#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - prints formatted output
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				putchar(va_arg(args, int));
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				while (*str)
				{
					putchar(*str++);
					count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				count += 2;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

