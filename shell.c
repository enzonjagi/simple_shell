#include <stdio.h>
#include "stuff.h"
#include <stdlib.h>

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
	/*char **args;*/
	int flag = 1;

	while (flag)
	{
		printf("$ ");
		usrIn = read_line();
		if (usrIn == NULL)
		{
			flag = 0;
		}
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
