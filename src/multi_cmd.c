/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** check
*/

#include "../include/my.h"

char *get_file_redirect2(char **cmd)
{
    char *tmp;
    for (int i = 0; cmd[i] != NULL; i++) {
        if (my_strcmp(cmd[i], "<") == 0 && cmd[i + 1] != NULL) {
            cmd[i] = NULL;
            tmp = cmd[i + 1];
            cmd[i + 1] = NULL;
            return (tmp);
        }
    }
    return (NULL);
}

int check_redirect2(char **cmd)
{
    int count = 0;
    for (int i = 0; cmd[i] != NULL; i++)
    {
        if (my_strcmp(cmd[i], "<") == 0)
            return (3);
        if (my_strcmp(cmd[i], "<<") == 0)
            return (4);
    }
    return (0);
}

int multi_command2(char **cmd, mysh_t *mysh, int *fd, int e)
{
    int g, k;
    int c = check_operateur(cmd, mysh->len);
    char *tmp = cmd[0];
    for (int i = 0; mysh->path[i] != NULL; i++) {
        if (cmd[0][0] == '.' && cmd[0][1] == '/')
            cmd[0] = get_binary(cmd[0]);
        else
            cmd[0] = str_add(tmp, mysh->path[i]);
        if (mysh->d == 3)
            g = dup2(fd[1], 0);
        if (e == 2 || e == 1)
            g = dup2(fd[0], 1);
        char *const opt[] = {cmd[0], cmd[1], cmd[2], NULL};
        if (c == 3)
            k = pipe_command(cmd, mysh, mysh->line, i);
        else
            k = execve(cmd[0], opt, NULL);
        if (k != -1) return (1);
    }
    return (0);
}

pid_t loop2(char *line3, mysh_t *mysh, char **str, char **cmd)
{
    int w;
    pid_t pid;
    int status;
    pid = fork();
    char *tmp = str[0];
    if (pid == 0) {
        multi_command(cmd, mysh, line3);
        free_tab(str);
        return (getpid());
    }
    else {
        w = waitpid(pid, &status, WUNTRACED);
        if (isatty(STDIN_FILENO) != 0) {
            if (mysh->y + 1 == mysh->e)
                my_putstr("$>: ");
        }
    }
}

int count_word2(char **cmd)
{
    int count = 0;
    for (int i = 0; cmd[i] != NULL; i++)
    {
        count++;
    }
    return (count);
}