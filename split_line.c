#include "main.h"

/**
 * split_line - Spliting the line using delimeter
 * extracts the argument by placing it in a new array until STRTOK is null
 * @line: string
 * @argv: Tokens
 * Return: number of tokens, -1 when in error
 */

int split_line(char *line, char *argv[])
{
	int i = 0;
	char *arg;
	const char *delim = " \t\n\r";

	if (line == NULL)
	{
		return (-1);
	}
	arg = strtok(line, "\n");
	arg = strtok(arg, delim);
	while (arg != NULL)
	{
		argv[i] = arg;
		i = i + 1;
		arg = strtok(NULL, delim);
	}
	argv[i] = 0;
	return (i);
}
