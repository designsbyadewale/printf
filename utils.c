#include "main.h"

/**
 * is_printable - Checks if a character is printable.
 * @c: The character to evaluate.
 *
 * Return: 1 if 'c' is printable, 0 otherwise.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1); /* 'c' is printable if its ASCII value is within this range */

	return (0);
}

/**
 * append_hexa_code - Appends ASCII character in hexadecimal code to a buffer.
 * @buffer: Array of characters to append to.
 * @i: Index at which to start appending.
 * @ascii_code: ASCII code of the character to append.
 *
 * Return: Always returns 3 (the number of characters appended).
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1; /* Make sure the ASCII code is positive */

	/* Append the ASCII code as a hexadecimal escape sequence */
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3); /* Always returns 3 characters appended */
}

/**
 * is_digit - Checks if a character is a digit.
 * @c: The character to evaluate.
 *
 * Return: 1 if 'c' is a digit, 0 otherwise.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1); /* 'c' is a digit if it's within the '0' to '9' range */

	return (0);
}

/**
 * convert_size_number - Converts a number to the specified size.
 * @num: The number to be casted.
 * @size: The size indicating the type to cast
 * to (S_LONG, S_SHORT, or default).
 *
 * Return: Casted value of 'num'.
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}

/**
 * convert_size_unsgnd - Converts an unsigned number to the specified size.
 * @num: The number to be casted.
 * @size: The size indicating the type to cast
 * to (S_LONG, S_SHORT, or default).
 *
 * Return: Casted value of 'num'.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
