#include "shell.h"

/** By Nayere */

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

    if (argv[1] != NULL)
        read_file(argv[1], argv);
    signal(SIGINT, signal_to_handel);
    
    while (statue) 
    {
        counter++;
        if (isatty(STDIN_FILENO))
            prompt();
        input = _getline();
        
        if (input[0] == '\0') 
        {
            continue;
        }
        
        history(input);
        cmd = parse_cmd(input);
        
        if (_strcmp(cmd[0], "exit") == 0)
        {
            exit_bul(cmd, input, argv, counter);
        } 
        else if (_strcmp(cmd[0], "setenv") == 0)
        {
            if (cmd[1] != NULL && cmd[2] != NULL)
            {
                res = set_env(cmd[1], cmd[2]);
                if (res != 0)
                {
                    fprintf(stderr, "set_env failure\n");
                }
                else 
                {
                    fprintf(stderr, "incorrect set_env usage\n");
                }
            }
        } 
        else if (_strcmp(cmd[0], "unsetenv") == 0)
        {
            if (cmd[1] != NULL)
            {
                res = unset_env(cmd[1]);
                if (res != 0)
                    fprintf(stderr, "failed to unset_env\n");
                else
                    fprintf(stderr, "incorrect unset_env usage");
            }
        }
        else if (check_builtin(cmd) == 0)
        {
            st = handle_builtin(cmd, st);
            free_all(cmd, input);
            continue;
        }
        else
        {
            st = check_cmd(cmd, input, counter, argv);
        }
        
        free_all(cmd, input);
    }
    return statue;
}

/**
* check_builtin - check builtin
* @cmd: command to check
* Return: 0 Success -1 Fail
*/
int check_builtin(char **cmd) 
{
    bul_t fun[] = {
        {"echo", NULL},
        {"history", NULL},
        {"cd", NULL},
        {"help", NULL},
        {NULL, NULL}
    };
    int i = 0;
    
    if (*cmd == NULL)
    {
        return -1;
    }

    while ((fun + i)->command) {
        if (_strcmp(cmd[0], (fun + i)->command) == 0)
            return 0;
        i++;
    }
    return -1;
}

/**
 * creat_envi - Create Array of Environment Variable
 * @envi: Array of Environment Variable
 * Return: Void
 */
void creat_envi(char **envi)
{
    int i;
    
    for (i = 0; environ[i]; i++)
        envi[i] = _strdup(environ[i]);
    envi[i] = NULL;
}
