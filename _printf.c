#include "main.h"

/**
 * print_char - Prints a character to stdout.
 * @c: The character to print
 * Return: The number of characters printed
 */

int print_char(int c)
{
	return (_putchar(c));
}


/**
 * print_str - Prints a string to stdout.
 * @str: The string to print
 * Return: The number of characters printed.
 */

int print_str(char *str)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}


/**
 * print_format - Handles different format specifiers.
 * @specifier: The format specifier character.
 * @ap: The va_list containing the arguments.
 * Return: The number of characters printed.
 */

int print_format(char specifier, va_list ap)
{
	int count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == '%')
		count += write(1, &specifier, 1);
	else
		return (-1);
	return (count);

}


/**
 * _printf - mimicing printf from standard stdio 
 * Description: produces output according to a format
 * write output to stdout
 * @format: character string composed of 0 or more directives
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 * Return -1 for incomplete identifier error
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);
	count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format),ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);


}
