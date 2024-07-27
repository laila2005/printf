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

/**
* print_number - Prints an integer to standard output
* @n: The integer to print
*
* Return: The number of characters printed
*/
int print_number(int n)
{
int count = 0;
char buf[12];
int i = 0;
unsigned int num;

if (n < 0)
{
write(1, "-", 1);
count++;
num = -n;
}
else
{
num = n;
}
do {
buf[i++] = (num % 10) + '0';
num /= 10;
} while (num > 0);

while (i--)
{
write(1, &buf[i], 1);
count++;
}

return (count);
}
