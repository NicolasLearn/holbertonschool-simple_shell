#include "main.h"

/*---------------------------------------------------------------------------*/
		/*IS_SHELL_CMD*/
/*---------------------------------------------------------------------------*/

int is_shell_cmd(char *command, char *input)
{
	shell_cmd array_cmd_shell[] = {
		{"env", shell_env},
		{"exit", shell_exit},
		{NULL, NULL}
	};
	int i = 0, is_check = 0;

	while (array_cmd_shell[i].command != NULL)
	{
		if (strcmp(command, array_cmd_shell[i].command) == 0)
		{
			array_cmd_shell[i].func(input);
			is_check = 1;
			break;
		}
		i++;
	}
	return (is_check);
}

/*---------------------------------------------------------------------------*/
		/*SHELL_EXIT*/
/*---------------------------------------------------------------------------*/

void shell_exit(char *input)
{
	free(input);
	exit(EXIT_SUCCESS);
}

/*---------------------------------------------------------------------------*/
		/*SHELL_ENV*/
/*---------------------------------------------------------------------------*/

void shell_env(__attribute__((unused)) char *input)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}
