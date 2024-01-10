#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>

extern char **environ;

// Maximum sizes
#define MAX_ARG              64
#define MAX_LINE             256
#define INITIAL_BUFFER_SIZE 1024

// Function declarations
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, const char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **parse_input(char *input, size_t *arg_count);
char **get_input(void);
char *_strcat(char *dest, char *src);
int _strlen(char *c);
int _strcmp(char *str1, char *str2);
char *locate_cmd(char *cmd);
void execute(char **argv);
int print_environment(void);
unsigned int compare_char(char s, const char *str);
void display_prompt(void);

#endif
