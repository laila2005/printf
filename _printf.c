#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Produces output according to a format
 * @format: A character string composed of zero or more directives
 *
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *p;

if (!format)
return (-1);

va_start(args, format);
for (p = format; *p; p++)
{
if (*p == '%')
{
p++;
if (*p == 'c')
{
char ch = va_arg(args, int);
write(1, &ch, 1), count++;
}
else if (*p == 's')
{
char *str = va_arg(args, char *);
if (!str)
str = "(null)";
while (*str)
write(1, str++, 1), count++;
}
else if (*p == '%')
write(1, p, 1), count++;
else
write(1, "%", 1), write(1, p, 1), count += 2;
}
else
write(1, p, 1), count++;
}
va_end(args);
return (count);
}
