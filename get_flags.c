#include "main.h"

/**
 * get_flags - Calculates active flags in a formatted string
 * @format: The formatted string in which to find flags
 * @i: A pointer to an integer representing the current
 * position in the format string
 * Return: Flags found in the format string
 */
int get_flags(const char *format, int *i)
{
	/* Define characters representing possible flags */
	/* and their corresponding values */
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int j, curr_i;
	int flags = 0;

	/* Start searching for flags at the position after the current 'i' */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{

		/* Iterate through possible flag characters */
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			/* If the current character matches a flag character, */
			/* set the corresponding flag */
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		}

		/* If no flag character is found, exit the loop */
		if (FLAGS_CH[j] == 0)
			break;
	}

	/* Update the 'i' pointer to the last character processed */
	*i = curr_i - 1;

	/* Return the flags found in the format string */
	return (flags);
}
