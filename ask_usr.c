#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
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
		while (usrIn[0] == '\n')
		{
			printf("$ ");
			getline(string_ptr, &size, stdin);
		}
		printf("%s", usrIn);
	}
	free(usrIn);
	return (0);
}
