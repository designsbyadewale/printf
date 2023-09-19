#include "main.h"
#include <ctype.h>

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0; /* Initialize width to 0. */

	/* Loop through the characters in the format string, starting from i + 1. */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (isdigit(format[curr_i])) /* If the current character is a digit. */
		{
			width *= 10; /* Multiply the existing width by 10. */
			width += format[curr_i] - '0'; /* Add the digit to the width. */
		}

		else if (format[curr_i] == '*') /* If the current character */
			/*is an asterisk. */
		{
			curr_i++; /* Move to the next character. */
			width = va_arg(list, int); /* Get the width */
			/*from the variable arguments list. */
			break; /* Exit the loop since we've found the width. */
		}

		else
			break; /* Exit the loop if the character is not a digit or an asterisk. */
	}

	*i = curr_i - 1;

	return (width);
}
