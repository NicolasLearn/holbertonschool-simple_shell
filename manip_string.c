#include "main.h"

/*---------------------------------------------------------------------------*/
		/*_STRCPY*/
/*---------------------------------------------------------------------------*/

/**
 * _strcpy - copy strings
 * @dest: destination for the copy of strings
 * @src: source of strings at copy
 *
 * Return: pointer of string copy
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*---------------------------------------------------------------------------*/
		/*GET_CMD_LINE*/
/*---------------------------------------------------------------------------*/

/**
 * get_input_cmd - get the input of user, back up the first argument.
 * @command: pointer to the first argument (command).
 *
 * Return: pointer to the input. Or NULL if failed.
*/
char *get_input_cmd(char **command)
{
	char *input = NULL;
	size_t size_buff_input = 0;
	char *buffer = NULL, array_buf[256];

	if ((getline(&input, &size_buff_input, stdin)) != -1)
	{
		buffer = _strcpy(array_buf, input);
		*command = strtok(buffer, " ");
		if (command == NULL)
			input = NULL;
	}
	return (input);
}
