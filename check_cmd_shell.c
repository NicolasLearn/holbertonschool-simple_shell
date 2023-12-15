#include "main.h"

int is_shell_cmd(char *command)
{
	shell_cmd array_cmd_shell[] = {
		{"env", },
		{"exit", },
		{"-1", },
		{NULL, NULL}
	};
	int i = 0;

	while (array_cmd_shell[i].command != NULL)
	{
		if (strcmp(command, array_cmd_shell[i].command) == 0)
			return (array_cmd_shell[i].func(command));
		i++;
	}
	return (0);
}
