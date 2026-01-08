#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * print_number - tam ədədləri tək-tək simvol olaraq çap edir
 * @n: çap ediləcək ədəd
 * Return: çap edilən simvolların sayı
 */
int print_number(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_number(num / 10);

	putchar((num % 10) + '0');
	count++;

	return (count);
}

/**
 * _printf - formatlı çap funksiyası (c, s, %, d, i dəstəkləyir)
 * @format: format stringi
 * Return: çap edilən simvolların ümumi sayı
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
				while (str && *str)
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
			else if (*format == 'd' || *format == 'i')
			{
				count += print_number(va_arg(args, int));
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

