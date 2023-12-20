#include "main.h"

/*---------------------------------------------------------------------------*/
		/*GET_CMD_LINE*/
/*---------------------------------------------------------------------------*/

/**
 * get_cmd_line - Creating token of each word from the input,
 * and return first token (command).
 *
 * @input: Pointer to the not NULL string got with getline().
 * @array_token: Adress of array of string wich will contain at each index
 * each token create from of the input.
 *
 * Return: pointer to the command (first argument). Or NULL if failed.
*/
char *get_cmd_line(char *input, char *array_token[])
{
	int index = 0;
	char *token = NULL, *command = NULL;
	const char *delim = " \t\n\r";

	token = strtok(input, "\n");
	token = strtok(token, delim);
	command = token;
	while (token != NULL)
	{
		array_token[index] = token;
		token = strtok(NULL, delim);
		index++;
	}
	array_token[index] = NULL;
	return (command);
}

/*---------------------------------------------------------------------------*/
		/*IS_VALID_CMD*/
/*---------------------------------------------------------------------------*/

/**
 * is_valid_cmd - Check if command is a file executable in PATH variable
 * get from the environment.
 *
 * @command: Pointer to the string to be checked.
 *
 * Return: Pointer to the string of matched PATH. Or NULL if not.
 *
 * Description: The variable "match_path", was got with malloc().
 * Don't forget : free(match_path)!
*/
char *is_valid_cmd(char *command)
{
	char *PATH = NULL, *token = NULL, *match_path = NULL;
	char *array_token_path[128];
	int index = 0;

	PATH = get_PATH();
	if (PATH == NULL)
	{
		fprintf(stderr, "Problem with malloc().\nERR %s", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		token = strtok(PATH, ":");
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
	free(PATH);
	PATH = NULL;
	return (match_path);
}

/*---------------------------------------------------------------------------*/
			/*GET_PATH*/
/*---------------------------------------------------------------------------*/

/**
 * get_PATH - Get the variable PATH from the environment.
 *
 * Return: Pointer to the string PATH. Or NULL on failure.
 *
 * Description : Use of strdup(), to manipulate the PATH variable.
 * Don't forget : free(PATH)!
 */
char *get_PATH(void)
{
	int index = 0;
	char *PATH = NULL;

	while (environ[index] != NULL)
	{
		if (strncmp(environ[index], "PATH", 4) == 0)
		{
			PATH = strdup(&environ[index][5]);
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
 * is_here - Check if the command got from the input is present and is
 * executable since the environment PATH variable.
 *
 * @path: Path where search the file executable.
 * @exec: File executable to be search. It can either be in the form of :
 * -the executable file name : <FILENAME>.
 * -Or directely in form : </PATH/FILENAME>.
 *
 * Return: Pointer to the path if it exist. NULL if don't exist.
 * Or pointer to the string "Error" if malloc() failed.
 *
 * Description : use of malloc(), to retrieve the string which will be given in
 * comparison to access().
 * Don't forget : free(try_path)!
 */
char *is_here(char *path, char *exec)
{
	size_t len_path = 0, len_exec = 0;
	char *try_path = NULL;

	len_path = strlen(path);
	len_exec = strlen(exec);
	try_path = malloc((sizeof(char) * (len_path + len_exec)) + 2);
	if (try_path == NULL)
	{
		fprintf(stderr, "Problem with malloc().\nERR %s", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		if (exec[0] == '/')
			strcpy(try_path, exec);
		else
		{
			strcpy(try_path, path);
			try_path[len_path] = '/';
			strcpy(&try_path[len_path + 1], exec);
		}
		if ((access(try_path, X_OK)) != 0)
		{
			free(try_path);
			try_path = NULL;
		}
	}
	return (try_path);
}
