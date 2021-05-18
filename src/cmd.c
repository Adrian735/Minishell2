/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** check
*/

#include "../include/my.h"

int pipe_command_1(int *fd, mysh_t *mysh, char **second_cmd, int i)
{
    int k;
    dup2(fd[0], 0);
    close(fd[1]);
    if (i != -1)
        second_cmd[0] = str_add(second_cmd[0], mysh->path[i]);
    else
        second_cmd[0] = get_binary(second_cmd[0]);
    char *const opt2[] = {second_cmd[0], second_cmd[1],
    second_cmd[2], NULL};
    k = execve(second_cmd[0], opt2, NULL);
}

int pipe_command_2(int *fd, mysh_t *mysh, char **first_cmd, int i)
{
    int k;
    dup2(fd[1], 1);
    close(fd[0]);
    char *const opt1[] = {first_cmd[0], first_cmd[1], first_cmd[2], NULL};
    k = execve(first_cmd[0], opt1, NULL);
    close(fd[0]);
    close(fd[1]);
    waitpid(-1, NULL, 0);
    kill(getpid(), 9);
}

int check_redirect(char **cmd)
{
    int count = 0;
    for (int i = 0; cmd[i] != NULL; i++)
    {
        if (my_strcmp(cmd[i], ">") == 0)
            return (1);
        if (my_strcmp(cmd[i], ">>") == 0)
            return (2);
    }
    return (0);
}

char *get_old_pwd(char **env)
{
    char *path = "OLDPWD";
    char *value;
    int i, j;
    int e = -1;
    for (i = 0; env[i] != NULL; i++) {
        for (j = 0; env[i][j] != 61; j++) {
            if (j == my_strlen(path) - 1)
                e = i;
            if (env[i][j] != path[j]) break;
        }
    }
    if (e != -1) {
        int k = 7;
        value = malloc((my_strlen(env[e]) - 2) * sizeof(char));
        for (j = 0; env[e][k] != '\0'; j++, k++)
            value[j] = env[e][k];
        value[j] = '/';
        value[j + 1] = '\0';
        return (value); }
    return (NULL);
}

char **get_command_pipe2(char **cmd, int nb)
{
    char **new_cmd;
    int i;
    int count = -1;
    for (i = 0; cmd[i] != NULL; i++) {
        if (count != -1)
            count++;
        if (my_strcmp(cmd[i], "|") == 0)
            count = 0;
    }
    new_cmd = malloc(sizeof(char *) * count + 1);
    count = -1;
    for (i = 0; cmd[i] != NULL; i++) {
        if (count != -1) {
            new_cmd[count] = cmd[i];
            count++;
        }
        if (my_strcmp(cmd[i], "|") == 0)
            count = 0; }
    new_cmd[i] = NULL;
    return (new_cmd);
}