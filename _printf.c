#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *p;

    if (format == NULL)
    {
        return -1;
    }

    va_start(args, format);
    for (p = format; *p != '\0'; p++)
    {
        if (*p == '%')
	{
            p++;
            switch (*p)
	    {
                case 'c':
			{
                    char ch = (char)va_arg(args, int);
                    write(1, &ch, 1);
                    count++;
                    break;
                }
                case 's':
			{
                    char *str = va_arg(args, char *);
                    if (str == NULL)
		    {
                        str = "(null)";
                    }
                    while (*str != '\0')
		    {
                        write(1, str, 1);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%': {
                    write(1, "%", 1);
                    count++;
                    break;
                }
                default:
 
                    write(1, "%", 1);
                    write(1, p, 1);
                    count += 2;
                    break;
            }
        } else
	{
            write(1, p, 1);
            count++;
        }
    }
    va_end(args);
    return count;
}
