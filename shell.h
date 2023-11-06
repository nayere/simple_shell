#ifndef _SHELL_H_
#define _SHELL_H_

/** environ var */

extern char **environ;

/** MACROS */

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

/** LIBS USED */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/limits.h>

/** STRING FUNCTION */

int main(int argc, char **argv);
int _strncmp(const char *str1, const char *str2, size_t n);
unsigned int check_delim(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
char *_strtok(char *str, const char *tok);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
void array_rev(char *arr, int len);
int set_env(char *var, char *val);
int unset_env(char *var);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
int _isalpha(int c);
int intlen(int n);
void _puts(char *str);
char *_strdup(char *str);
char *_itoa(unsigned int n);
char *_strchr(char *s, char c);

/** Memory  Managment */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *fill_an_array(void *a, int n, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void free_all(char **input, char *line);
void *_calloc(unsigned int size);
void free_env(char **env);

/** error handle and Printer */

void print_number_in(int n);
void print_number(unsigned int n);
void _prerror(char **argv, int c, char **input);
void print_error(char *input, int count, char **argv);

/** Command parser and extractor */

int path_cmd(char **line);
char *_getenv(char *name);
char **parse_cmd(char *input);
int check_builtin(char **cmd);
void creat_envi(char **envi);
char *build(char *token, char *value);
int handle_builtin(char **cmd, int er);
void read_file(char *filename, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);
int check_cmd(char **tokens, char *line, int count, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);

/** INPUT Function */

void prompt(void);
char *_getline(void);
void signal_to_handel(int sig);

/** ####BUL FUNC #####*/


int history(char *input);
int print_echo(char **input);
void hashtag_handle(char *buff);
int dis_env(char **cmd, int er);
int echo_bul(char **cmd, int er);
int change_dir(char **cmd, int er);
int history_dis(char **cmd, int er);
int display_help(char **cmd, int er);
void  exit_bul(char **cmd, char *input, char **argv, int c);

/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif /**Author Job Nayere */

