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
	size_t size_buff_input = 0;
	char *array_token[128];
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		if (((getline(&input, &size_buff_input, stdin)) == -1) || (input == NULL))
		{
			free(input);
			input = NULL;
			exit(EXIT_FAILURE);
		}
		command = get_cmd_line(input, array_token);
		if (command == NULL)
		{
			free(input);
			input = NULL;
			exit(EXIT_FAILURE);
		}
		if ((is_shell_cmd(command)) == 0)
		{
			if(is_valid_cmd(command) == 1)
				/*fonction exec*/
			else
				/*error message*/
		}
		free(input);
		input = NULL;
	}
	return (0);
}
/*lecture de input directement sur le main, plus de fonction de lecture, pas utile*/
/*test input pas au point attente gestion des erreurs*/
/*j'ai modifier ta fonction get_cmd_line pour qu'elle renvoie un pointeur de arg[0], pour l'utiliser plus facilement grâce a une variable*/
/*test command identique que test input*/
/*modification aussi de la fonction is_shell_cmd, ajout d'une struct et adaptattion pour utliser la variable command*/
/*j'ai supprimer environ des paramètres car variable global, on y a accès partout grâce a inclusion de main.h*/
/*et sinon je travail pour la fonction is_valid_cmd*/
/*du coup j'ai affiner un peu le main pour que ça colle avec nos functions et la tram de départ*/
/*dis moi si ça te convient et ce que tu vois qui peut être améliorer*/
