#include "stuff.h"
/**
 * main - calls the necessary functions for the shell
 * @argc: argument counter
 * @argv: actual arguments
 * Return: 0 or 1
 */
int main(int argc, char **argv)
{
	/*initiate the shell loop*/
	shell_loop();

	return (0);
}
/**
 * shell_loop - loop till EOF condition is met
 * Return: void
 */
void shell_loop(void)
{
	char *usrIn;
	char **args;
	int flag = 1;

	while (flag)
	{
		printf("$ ");
		usrIn = read_line();
		if (usrIn == NULL)
		{
			flag = 0;
		}
		args = split(usrIn);

		free(usrIn);
		free(args);
	}
}
/**
 * read_line - gets the input from the shell
 * Return: line or -1
 */
char *read_line(void)
{
	size_t size = 0;/*Expected size of input*/
	char *string_ptr = NULL;/*Output*/

	if (getline(&string_ptr, &size, stdin) == -1)/*check errors in input*/
	{
		if (feof(stdin))/*check for EOF*/
		{
			printf("\n");
			exit(EXIT_SUCCESS);/*we got an EOF*/
		}
		else
		{
			perror("Command not found!");
			exit(EXIT_SUCCESS);
		}
	}
	while (string_ptr[0] == '\n')/*if empty line ask again*/
	{
		printf("$ ");
		getline(&string_ptr, &size, stdin);
	}

	return (string_ptr);/*return the input read from the terminal*/
}
/**
 * split - breaks the string into pieces and prints each
 * @str: string pointer we'll receive
 * Return: void but should be 0 for sucess, -1 for failure
 */

char **split(char *str)
{
	int bufsize = TOK_BUFSIZE, pos = 0;
	char **pieces = malloc(bufsize * (sizeof (char *)));
	char *piece;

	if (!pieces)
	{
		fprintf(stderr, "Malloc error\n");
		exit(EXIT_FAILURE);
	}

	piece = strtok(str, TOK_DELIM);/*point to string to split*/
	while (piece != NULL)
	{
		pieces[pos] = piece;/*add token to list of tokens*/
		pos++;

		if (pos >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			pieces = realloc(pieces, bufsize * sizeof(char *));
			if (!pieces)
			{
				fprintf(stderr, "Malloc error\n");
				exit(EXIT_FAILURE);
			}
		}
		printf("%s\n", piece);
		piece = strtok(NULL, TOK_DELIM);/*keep pointing to same string*/
	}
	pieces[pos] = NULL;
	return (pieces);

}
