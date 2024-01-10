#include "main.h"

/**
 * @brief Prints the environment variables.
 *
 * This function initializes and prints the environment variables.
 *
 * @return Always returns 0 on success. -1 is returned on error.
 */
int print_environment_var(void)
{
    char **env_variable = environ;

    while (*env_variable)
    {
        size_t len = 0;

        // Calculate the length of the environment variable
        while ((*env_variable)[len])
            len++;

        // Write the environment variable to the standard output
        write(STDOUT_FILENO, *env_variable, len);
        write(STDOUT_FILENO, "\n", 1);

        // Move to the next environment variable
        env_variable++;
    }

    return 0;
}
