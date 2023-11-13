#include "shell.h"
/**
 *  _prerror - Print Custome Error
 * @argv: Program Name
 * @c: Error Count
 * @input: Command
 * Return: Void
 */
void _prerror(char **argv, int c, char **input)
{
	char *ch = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(ch);
	PRINTER(": ");
	PRINTER(input[0]);
	PRINTER(": Invalid number: ");
	PRINTER(input[1]);
	PRINTER("\n");
	free(ch);
}
