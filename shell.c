#include "main.h"

// Function declarations
int main(void);

/**
 * @brief Custom UNIX-like shell.
 * @return Returns 0 on success.
 */
int main(void)
{
    while (1)
    {
        // Variable declarations
        pid_t pid;
        char *line = NULL;
        size_t n = 0;
        ssize_t char_read;
        char *argv[MAX_ARG];
        char *token = NULL;
        int status, arg_count = 0;

        // Check if the shell is in interactive mode
        if (isatty(STDIN_FILENO) == 1)
            display_prompt();

        // Read user input and check if nothing was read
        char_read = _getline(&line, &n, stdin);
        if (char_read == -1)
        {
            perror("Error reading input.\n");
            free(line);
            exit(EXIT_FAILURE);
        }

        // Tokenize the input
        token = _strtok(line, " \t\n");
        while (token != NULL && arg_count < MAX_ARG - 1)
        {
            argv[arg_count] = token;
            token = _strtok(NULL, " \t\n");
            arg_count++;
        }
        argv[arg_count] = NULL;

        // Exit the shell if the user enters 'exit'
        if (_strcmp(argv[0], "exit") == 0)
            break;
        else if (_strcmp(argv[0], "env") == 0)
        {
            print_environment();
            continue;
        }

        // Fork a child process and check if fork was successful
        pid = fork();
        if (pid == -1)
        {
            perror("Fork failure.\n");
            free(line);
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            // Child process: execute command
            execute(argv);
        }
        else
        {
            // Parent process: wait for the child to finish
            if (waitpid(pid, &status, 0) == -1)
            {
                perror("Waitpid failure.\n");
                free(line);
                exit(EXIT_FAILURE);
            }
        }

        free(line);
    }

    return 0;
}
