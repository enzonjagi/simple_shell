#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
/**
 * split - breaks the string into pieces and prints each
 * @str: string pointer we'll receive
 * Return: void but should be 0 for sucess, -1 for failure
 */

void split(char *str)
{
	char *piece = NULL;

	piece = strtok(str, " ");/*point to string to split*/
	while (piece != NULL)
	{
		printf("%s\n", piece);
		/*keep pointing to same string*/
		piece = strtok(NULL, " ");
	}

}
/**
 * main - prints user input on next line
 * Return: 0
 */

int main(void)
{
	char *usrIn;/*Input*/
	size_t size = 100;/*Expected size of input*/
	int flag = 1, get;/*Flag to close or keep shell open*/
	char **string_ptr = NULL;/*Output*/

	usrIn = (char *) malloc(size);
	if (usrIn == NULL)
		return (free(usrIn), -1);
	string_ptr = &usrIn;
	while (flag)
	{
		printf("$ ");
		get = getline(string_ptr, &size, stdin);
		if (get == -1)/*check for EOF*/
		{
			flag = 0;/*change flag to 0, hence end loop*/
			return (-1);
		}
		while (usrIn[0] == '\n')/*if empty line ask again*/
		{
			printf("$ ");
			getline(string_ptr, &size, stdin);
		}
		printf("Print on one line:\n");
		printf("%s", usrIn);
		printf("Split string and print:\n");
		split(usrIn);
	}
	free(usrIn);
	return (0);
}
