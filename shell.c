#include "shell.h"

/** Authors Mwangii & Nayere */

/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv: Argument Value
 * Return: Exit Value By Status
 */
int main(__attribute__((unused)) int argc, char **argv)
{
    int counter = 0, statue = 1, st = 0, res;
    char *input, **cmd;

    setup_initial(argc, argv);

    while (statue)
    {
        counter++;
        input = get_input();

        if (input[0] == '\0')
            continue;

        handle_input(input, &cmd, &counter, argv, &st, &res);
        free_input_and_cmd(&cmd, input);
    }

    return statue;
}

/**
 * setup_initial - Perform initial setup
 * @argc: Argument Count
 * @argv: Argument Value
 */
void setup_initial(int argc, char **argv)
{
    if (argv[1] != NULL)
        read_file(argv[1], argv);
    signal(SIGINT, signal_to_handel);
    (void)argc;
}

/**
 * get_input - Get user input
 * Return: User input
 */
char *get_input()
{
    if (isatty(STDIN_FILENO))
        prompt();
    return _getline();
}

/**
 * handle_input - Process user input
 * @input: User input
 * @cmd: Command value
 * @counter: Counter value
 * @argv: Argument value
 * @st: Status value
 * @res: Result value
 */
void handle_input(char *input, char ***cmd, int *counter, char **argv, int *st, int *res)
{
    history(input);
    *cmd = parse_cmd(input);

    if (_strcmp((*cmd)[0], "exit") == 0)
    {
        exit_bul(*cmd, input, argv, *counter);
    }
    else if (_strcmp((*cmd)[0], "setenv") == 0)
    {
        handle_setenv(*cmd, res);
    } 
    else if (_strcmp((*cmd)[0], "unsetenv") == 0)
    
        handle_unsetenv(*cmd, res);
    }
    else if (check_builtin(*cmd) == 0)
    {
        *st = handle_builtin_command(*cmd, *st);
        free_all(*cmd, input);
    }
    else
    {
        *st = check_and_handle_cmd(*cmd, input, *counter, argv);
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
