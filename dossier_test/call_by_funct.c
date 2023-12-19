#include "main.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
		/*Function called by : IS_SHELL_CMD*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*-----------------------------------------------------------------*/
			/*SHELL_ENV*/
/*-----------------------------------------------------------------*/

/**
 * shell_env - Print the variable environ.
 * @input: Argument unused.
*/
void shell_env(__attribute__((unused)) char *input)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}

/*-----------------------------------------------------------------*/
			/*SHELL_EXIT*/
/*-----------------------------------------------------------------*/

/**
 * shell_exit - Exits the function properly.
 * @input: Command got with dynamic memory allocation (getline), must free.
*/
void shell_exit(char *input)
{
	free(input);
	exit(EXIT_SUCCESS);
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
		/*Function called by : IS_VALID_CMD*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*-----------------------------------------------------------------*/
			/*GET_PATH*/
/*-----------------------------------------------------------------*/

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

/*-----------------------------------------------------------------*/
			/*IS_HERE*/
/*-----------------------------------------------------------------*/

/**
 * is_here - Check if the command got from the input is present and is
 * executable since the environment PATH variable.
 *
 * @path: Path where search the file executable.
 * @exec: File executable to be search. It can either be in the form of :
 * -the executable file name : <FILENAME>.
 * -Or directely in form : </PATH/FILENAME>.
 *
 * Return: Pointer to the path if it exist. NULL if failed.
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
	if (try_path != NULL)
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
