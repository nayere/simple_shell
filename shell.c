#include "shell.h"

/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Exit Value By Status
 */
int main(__attribute__((unused)) int argc, char **argv) {
    int counter = 0;
    char *input, **cmd;

    setup_initial(argv);

    while (evaluate_statue()) {
        counter++;
        input = get_input();

        if (input[0] == '\0') {
            continue;
        }

        process_input(input, &cmd, &counter, argv);
        free_input_and_cmd(&cmd, input);
    }

    return get_statue();
}

/**
 * setup_initial - Perform initial setup
 * @argv: Argument value
 */
void setup_initial(char **argv) {
    if (argv[1] != NULL)
        read_file(argv[1], argv);
    signal(SIGINT, signal_to_handel);
}

/**
 * evaluate_statue - Evaluate the statue condition
 * Return: Statue value
 */
int evaluate_statue() {
    return statue;
}

/**
 * get_input - Get user input
 * Return: User input
 */
char *get_input() {
    if (isatty(STDIN_FILENO))
        prompt();
    return _getline();
}

/**
 * process_input - Process user input
 * @input: User input
 * @cmd: Command value
 * @counter: Counter value
 * @argv: Argument value
 */
void process_input(char *input, char ***cmd, int *counter, char **argv) {
    history(input);
    *cmd = parse_cmd(input);
    if (_strcmp((*cmd)[0], "exit") == 0)
    {
	    exit_bul(*cmd, input, argv, *counter);
    }
    else if (_strcmp((*cmd)[0], "setenv") == 0)
    {
	    handle_setenv(*cmd);
    }
    else if (_strcmp((*cmd)[0], "unsetenv") == 0)
    {
	    handle_unsetenv(*cmd);
    }
    else if (check_builtin(*cmd) == 0)
    {
	    handle_builtin_command(*cmd);
    } 
    else
    {
	    handle_other_commands(*cmd, input, *counter, argv);
    }
}

/**
 * free_input_and_cmd - Free input and command
 * @cmd: Command value
 * @input: User input
 */
void free_input_and_cmd(char ***cmd, char *input) 
{
	free_all(*cmd, input);
}

/**
 * creat_envi - Creat Array of Enviroment Variable
 * @envi: Array of Enviroment Variable
 * Return: Void
 */
void creat_envi(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}
