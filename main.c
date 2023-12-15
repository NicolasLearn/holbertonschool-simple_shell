#include "main.h"

/*---------------------------------------------------------------------------*/
		/*MAIN*/
/*---------------------------------------------------------------------------*/

/**
 * main - Entry point.
 *
 * Return: always 0.
*/
int main(void)
{
	char *command = NULL, *input = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		input = get_input_cmd(&command);
		if (input == NULL)
		{
			free(input);
			input = NULL;
			exit(EXIT_FAILURE);
		}
		free(input);
		input = NULL;
	}
	return (0);
}

		/*appel fonction get_cmd_line -> lis ligne, genere arg[0] avec strtok, return arg[0]*/
		/*appel fonction is_shell_comd -> compare arg[0] avec commandes integrer shell (exit, env), execute fonction si existe, return si exec or not*/
			/*retour debut de la boucle*/
		/*appel fonction is_exist -> recherche si arg[0] est un fichhier executable existant dans les tokens de PATH, return match_path si found or NULL*/
			/*retour debut de la boucle*/
		/*appel exec_cmd -> genere token string, execute la commande avec match_path, token_array, environ*/
