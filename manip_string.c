#include "main.h"

/*---------------------------------------------------------------------------*/
		/*_STRCPY*/
/*---------------------------------------------------------------------------*/

/**
 * _strcpy - copie the strings from 'src', include '\0' to 'dest
 * @dest: destination for the copy of the string
 * @src: source of the strings at copy
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '\0';
	return (dest);
}

/*---------------------------------------------------------------------------*/
		/*GET_CMD_LINE*/
/*---------------------------------------------------------------------------*/

char *get_cmd_line(char *input, char *array_token[])
{
	int index = 0;
	char *token, *command_buf = NULL;
	const char *delim = " \t\n\r";

	token = strtok(input, "\n");
	token = strtok(token, delim);
	command_buf = token;
	while (token != NULL)
	{
		array_token[index] = token;
		token = strtok(NULL, delim);
		index++;
	}
	array_token[index] = NULL;
	return (command_buf);
}

/*---------------------------------------------------------------------------*/
		/*GET_PATH*/
/*---------------------------------------------------------------------------*/

/**
 * get_PATH - get PATH from the environment
 *
 * Return: pointer to the string PATH or NULL on failure
 */
char *get_PATH(void)
{
	int index = 0;
	char *PATH = NULL;

	while (environ[index] != NULL)
	{
		if (strncmp(environ[index], "PATH", 4) == 0)
		{
			PATH = &environ[index][5];
			break;
		}
		index++;
	}
	return (PATH);
}

/*---------------------------------------------------------------------------*/
		/*IS_HERE*/
/*---------------------------------------------------------------------------*/

/**
 *
*/
char *is_here(char *path, char *exec)
{

}

/*---------------------------------------------------------------------------*/
		/*IS_VALID_CMD*/
/*---------------------------------------------------------------------------*/

char *is_valid_cmd(char *command)
{
	char *PATH = NULL, *token = NULL, buf_PATH = NULL;
	char *match_path = NULL;
	char *array_token_path[128], array_buf_path[1024];
	int index = 0;

	PATH = get_PATH();
	if (PATH != NULL)
	{
		buf_PATH = _strcpy(array_buf_path, PATH);
		token = strtok(buf_PATH, "\n");
		token = strtok(token, ":");
		while (token != NULL)
		{
			array_token_path[index] = token;
			token = strtok(NULL, ":");
			index++;
		}
		array_token_path[index] = NULL;
		for (index = 0; array_token_path[index]; index++)
		{
			match_path = is_here(array_token_path[index], command);
			if (match_path != NULL)
				break;
		}
	}
	return (match_path);
}
