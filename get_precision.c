#include "main.h"
#include <ctype.h>

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current position in the format string.
 * @list: List of arguments.
 *
 * Return: Precision value.
 */
int get_precision(const char *format, int *i, va_list list)
{
	/* Initialize the current index to the next character in the format string. */
	int curr_i = *i + 1;
	int precision = -1;

	/* Check if the current character is not a dot (period). */
	if (format[curr_i] != '.')
		return (precision); /* If not, return -1 (no precision). */
	precision = 0; /* Reset precision to 0 since a dot was found, */
	/* indicating precision. */

	/* Loop through characters after the dot to calculate precision. */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (isdigit(format[curr_i]))
		{
			/* If the current character is a digit, update precision accordingly. */
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			/* If an asterisk (*) is encountered, retrieve precision from arguments. */
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break; /* Exit the loop if a non-digit or non-asterisk */
		/* character is encountered. */
	}

	*i = curr_i - 1;
	return (precision);
}
