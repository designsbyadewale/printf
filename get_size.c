#include "main.h"

/**
 * get_size - Determines the size to cast the argument in a formatted string.
 * @format: Formatted string containing the format specifier.
 * @i: Pointer to the current position in the format string.
 *
 * This function analyzes the format specifier at position i in the format
 * string and returns the corresponding size to cast the argument.
 *
 * Return: Size indicator for casting the argument.
 */

int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	/* Check if the next character in format is 'l' indicating long. */
	if (format[curr_i] == 'l')
		size = S_LONG;

	/* Check if the next character in format is 'h' indicating short. */
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	/* If size is still 0, no size indicator was found, */
	/* so update i accordingly. */
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i; /* Update i to the current position. */

	return (size); /* Return the determined size indicator. */
}
