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
	int t = 1, get;/*Number of lines of input*/
	char **string_ptr = NULL;/*Output*/

	usrIn = (char *) malloc(size);
	if (usrIn == NULL)
		return (free(usrIn), -1);
	string_ptr = &usrIn;
	while (t)
	{
		printf("$ ");
		get = getline(string_ptr, &size, stdin);
		if (get == -1)/*check for EOF*/
			t = 0;/*change flag to 0, hence end loop*/
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
