/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** function
*/

#include "../include/my.h"

int check_operateur(char **cmd, int nb)
{
    int count = 0;
    for (int i = 0; i <= nb; i++)
    {
        if (cmd[i] != NULL && my_strcmp(cmd[i], "|") == 0)
            return (3);
    }
    return (0);
}

char *get_file_redirect(char **cmd)
{
    char *tmp;
    for (int i = 0; cmd[i] != NULL; i++) {
        if ((my_strcmp(cmd[i], ">") == 0 || my_strcmp(cmd[i], ">>") == 0)
        && cmd[i + 1] != NULL) {
            cmd[i] = NULL;
            tmp = cmd[i + 1];
            cmd[i + 1] = NULL;
            return (tmp);
        }
    }
    return (NULL);
}

int count_cmd(char **str)
{
    int count = 0;
    for (int i = 0; str[i] != NULL; i++)
    {
        if (my_strcmp(str[i], ";") == 0)
            count++;
    }
    return (count + 1);
}

char **get_command(char **str, int y)
{
    int i;
    int e = 0;
    int count = 0;
    for (i = 0; str[i] != NULL; i++);
    char **command = malloc((i + 1) * sizeof(char *));
    if (y == 0) {
        for (i = 0; str[i] != NULL; i++) {
            if (my_strcmp(";", str[i]) == 0)
                break;
            command[i] = str[i]; }
        e = i; }
    else {
        for (i = 0; str[i] != NULL; i++) {
            if (count == y && my_strcmp(";", str[i]) != 0) {
                command[e] = str[i];
                e++; }
            if (my_strcmp(";", str[i]) == 0)
                count++; } }
    command[e] = NULL;
    return (command);
}