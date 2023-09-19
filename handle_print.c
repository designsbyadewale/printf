#include "main.h"

/**
 * handle_print - Handles formatted printing of arguments.
 * @fmt: Formatted string containing placeholders for arguments.
 * @ind: Pointer to the current position in 'fmt'.
 * @list: List of arguments to be printed (va_list).
 * @buffer: Buffer array to store the printed output.
 * @flags: Flags indicating special formatting options.
 * @width: Width specification for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size specifier for formatting.
 * Return: The number of characters printed or -1 if an error occurs.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknown_len = 0;

	/* Define a structure 'fmt_t' to map format specifiers to functions */
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'\0', NULL}
	};

	/* Iterate through the format specifiers and call */
	/* the corresponding function */
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	}

	/* If no matching format specifier is found, handle it as a character */
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &fmt[*ind], 1);
		return (unknown_len);
}
