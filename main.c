#include "main.h"

/*---------------------------------------------------------------------------*/
		/*MAIN*/
/*---------------------------------------------------------------------------*/

/**
 * main - Entry point.
 *
 * @argc: Paramater unused.
 * @argv: Useful for get the name of the executable.
 *
 * Return: always 0.
*/
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *command = NULL, *src_input = NULL, *PATH = NULL, *array_token[128];
	char *name_prog = argv[0];
	size_t size_buff_input = 0;

	while (1)
	{
		errno = 0;
		if (isatty(STDIN_FILENO))
			printf("$ ");
		if ((getline(&src_input, &size_buff_input, stdin)) == -1)
		{
			free_elem(&src_input);
			shell_exit(); }
		if (src_input[0] != '\n')
		{
			command = get_cmd_line(src_input, array_token);
			if (command != NULL)
			{
				if ((is_shell_cmd(command, &src_input)) == 0)
				{
					PATH = is_valid_cmd(command);
					if (PATH != NULL)
					{
						exec_command(PATH, array_token);
						free_elem(&PATH);
					} else
						fprintf(stderr, "%s: %d:'%s': not found\n",
						name_prog, __LINE__, command); } } }
		free_elem(&src_input);
		command = NULL;
	}
	return (0);
}
