[200~#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char *str;
    char ch;

    va_start(args, format);

    if (!format)
        return (-1);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')  /* fix for _printf("%") */
                break;
            if (*format == 'c')
            {
                ch = va_arg(args, int);
                putchar(ch);
                count++;
            }
            else if (*format == 's')
            {
                str = va_arg(args, char *);
                if (!str)
                    str = "(null)";
                while (*str)
                {
                    putchar(*str);
                    count++;
                    str++;
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

