#include "main.h"

/**
 * @brief Gets the value of an environment variable.
 *
 * This function searches for the specified environment variable and returns
 * its value.
 *
 * @param name Name of the desired variable.
 * @return If found, returns the environmental variable string; otherwise, returns NULL.
 */
char *print_environment_var(const char *name)
{
    const char *delimiter = "=";
    char *env_var;
    char *token;
    char *value;
    int count = 0;
    int i;

    // Count the number of environment variables
    while (environ[count] != NULL)
    {
        count++;
    }

    // Loop through each environment variable
    for (i = 0; i < count; i++)
    {
        // Duplicate the environment variable to avoid modifying the original
        env_var = strdup(environ[i]);
        if (env_var == NULL)
        {
            perror("strdup");
            exit(EXIT_FAILURE);
        }

        // Tokenize the environment variable using the delimiter
        token = strtok(env_var, delimiter);

        // Check if the token matches the desired variable name
        if ((token != NULL) && (strcmp(token, name) == 0))
        {
            // Get the value of the environment variable
            token = strtok(NULL, delimiter);
            value = strdup(token);
            free(env_var);
            return value;
        }

        // Free the duplicated environment variable
        free(env_var);
    }

    // Print an error message if the variable is not found
    dprintf(STDERR_FILENO, "Variable not found: %s\n", name);
    return NULL;
}
