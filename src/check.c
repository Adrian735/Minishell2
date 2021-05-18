/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** check
*/

#include "../include/my.h"

int count_sep(char *path)
{
    int count = 0;
    for (int i = 0; i < my_strlen(path); i++)
    {
        if (path[i] == ':')
            count++;
    }
    return (count + 1);
}

int check_line(char *line)
{
    int i;
    char *ex = "exit";
    for (i = 0; i < my_strlen(line) - 1; i++)
    {
        if (line[i] != ex[i])
            return (0);
    }
    if (isatty(STDIN_FILENO) != 0)
        my_putstr("exit");
    return (1);
}

int check_fonction(char **str)
{
    int i;
    int j;
    int a = 0;
    char *funct[4] = {"cd", "setenv", "env", "unsetenv"};
    for (i = 0; i < 4; i++)
    {
        if (my_strcmp(funct[i], str[0]) == 0)
            return (i);
    }
    return (-1);
}

int check_arg_setenv(char **str, char **env)
{
    int i, j;
    if (str[1] == NULL) return (-1);
    if (str[3] != NULL && str[2] != NULL) return (-1);
    for (i = 0; i < my_strlen(str[1]); i++) {
        if (str[1][i] < 65 || (str[1][i] > 90 && str[1][i] < 97) ||
        str[1][i] > 122)
            return (-1);
    }
    for (i = 0; env[i] != NULL; i++) {
        for (j = 0; env[i][j] != 61; j++) {
            if (j == my_strlen(str[1]) - 1)
                return (i);
            if (env[i][j] != str[1][j]) break;
        }
    }
    return (0);
}

int check_arg_unsetenv(char **str, char **env)
{
    int i, j;

    if (str[1] == NULL || str[2] != NULL)
        return (-1);
    for (i = 0; i < my_strlen(str[1]); i++) {
        if (str[1][i] < 65 || (str[1][i] > 90 && str[1][i] < 97) ||
        str[1][i] > 122)
            return (-1);
    }
    return (0);
}