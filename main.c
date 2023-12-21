#include "main.h"

/*---------------------------------------------------------------------------*/
		/*MAIN*/
/*---------------------------------------------------------------------------*/

/**
 * main - Entry point. Is an infinite loop only on interactive mode, stopped
 * when entering specific commands ("exit" or "ctrl-d"), or when
 * a major error occurs during program execution.
 *
 * @argc: Paramater unused.
 * @argv: Useful for get the name of the executable.
 *
 * Return: always 0.
 *
 * Description: Retrieves input, either entered by the user or via a redirect
 * flow. Tokenize the input and get the first argument. Check if the command
 * is a built-in function or a valid executable file accessible in the PATH
 * variable. If a match is found, the command is executed, otherwise an error
 * message is printed to the standard error output.
*/
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *command = NULL, *src_input = NULL, *PATH = NULL, *array_token[128];
	char *name_prog = argv[0];
	size_t size_buff_input = 0, is_from_input = 0;

	do {
		errno = 0;
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			is_from_input = 1; }
		if ((getline(&src_input, &size_buff_input, stdin)) == -1)
		{
			if (errno == 0)
				break;
			fprintf(stderr, "Input problem\nERR %s\n", strerror(errno));
			shell_exit(&src_input, EXIT_FAILURE); }
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
						fprintf(stderr, "%s: %d: '%s': not found\n",
						name_prog, __LINE__, command); } } }
		if (is_from_input)
			free_elem(&src_input);
		command = NULL;
	} while (is_from_input);
	free_elem(&src_input);
	return (0);
}
