/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** minishell
*/

#include "../include/my.h"

char *get_binary(char *str)
{
    int e = 0;
    char *path = malloc(sizeof(char) * my_strlen(str) - 1);
    for (int i = 0; i < my_strlen(str); i++)
    {
        if (i > 1)
        {
            path[e] = str[i];
            e++;
        }
    }
    path[e] = '\0';
    return (path);
}

char **get_command_pipe(char **cmd, int nb)
{
    char **new_cmd;
    int i;
    if (nb == 0) {
        for (i = 0; cmd[i] != NULL; i++) {
            if (my_strcmp(cmd[i], "|") == 0)
                break;
        }
        new_cmd = malloc(sizeof(char *) * i + 1);
        for (i = 0; cmd[i] != NULL; i++) {
            if (my_strcmp(cmd[i], "|") == 0)
                break;
            new_cmd[i] = cmd[i];
        }
        new_cmd[i] = NULL;
    }
    else
        new_cmd = get_command_pipe2(cmd, nb);
    return (new_cmd);
}

int pipe_command(char **cmd, mysh_t *mysh, char *line, int i)
{
    pid_t pid;
    int k;
    char **first_cmd = get_command_pipe(cmd, 0);
    char **second_cmd = get_command_pipe(cmd, 1);
    int fd[2];
    pipe(fd);
    pid = fork();
    if (pid == 0) {
        pipe_command_1(fd, mysh, second_cmd, i);
        return (-1);
    }
    else {
        pipe_command_2(fd, mysh, first_cmd, i);
        return (-1);
    }
    return (0);
}

int multi_command(char **cmd, mysh_t *mysh, char *line)
{
    int fd[2];
    int e = check_redirect(cmd);
    mysh->d = check_redirect2(cmd);
    mysh->line = line;
    char *tmp = cmd[0];
    if (e != 0 || mysh->d != 0) {
        char *file = get_file_redirect(cmd);
        if (e == 1)
            fd[0] = open(file, (O_CREAT | O_WRONLY | O_TRUNC), S_IRWXU);
        if (e == 2)
            fd[0] = open(file, (O_CREAT | O_WRONLY | O_APPEND), S_IRWXU);
        if (mysh->d == 3)
            fd[1] = open(get_file_redirect2(cmd), O_RDONLY, S_IRWXU);
    }
    int count = multi_command2(cmd, mysh, fd, e);
    if (count == 0) miniprint("%s%s", tmp, ": Command not found.\n");
    close(fd[0]);
    close(fd[1]);
    kill(getpid(), 9);
    return (0);
}