/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** minishell
*/

#include "include/my.h"

void get_path(mysh_t *mysh)
{
    char *path = search_path(mysh->env);
    int e = 0;
    int i, j;
    mysh->path = (char **) malloc(sizeof(char *) * (count_sep(path) + 1));
    for (i = 0; e < my_strlen(path); i++) {
        mysh->path[i] = (char *) malloc(sizeof(char) * (my_strlen(path) + 1));
        for (j = 0; path[e] != ':'; j++, e++) {
            mysh->path[i][j] = path[e];
            if (e >= my_strlen(path))
                break;
        }
        if (e < my_strlen(path)) {
            mysh->path[i][j] = '/';
            mysh->path[i][j + 1] = '\0';
        }
        else
            mysh->path[i][j + 1] = '\0';
        e++;
    }
    mysh->path[i] = NULL;
}

char *str_add(char *str, char *path)
{
    char *str3;
    str3 = (char *) malloc(sizeof(char) * (my_strlen(str) +
    my_strlen(path) + 1));
    int i;
    int e;
    for (i = 0; i < my_strlen(path); i++)
        str3[i] = path[i];
    i = my_strlen(path);
    e = my_strlen(path);
    for (i = 0; i < my_strlen(str); i++)
    {
        str3[e] = str[i];
        e++;
    }
    str3[e] = '\0';
    return (str3);
}

pid_t loop(char *line, mysh_t *mysh, char **str, int e)
{
    pid_t pid, w;
    mysh->e = e;
    char *line3 = my_strncpy(line3, line, my_strlen(line) - 1);
    char **cmd = get_command(str, mysh->y);
    mysh->len = count_word2(cmd);
    int r = check_operateur(cmd, mysh->len);
    if (r == 3)
        mysh->pipe_state = 1;
    else
        mysh->pipe_state = 0;
    int status;
    int nb, k;
    nb = check_fonction(cmd);
    if (nb != -1) {
        mysh->env = other_fonct(cmd, nb, mysh->env);
        my_putstr("$>: ");
        return (-1);
    }
    else
        loop2(line3, mysh, str, cmd);
}

int minishell(mysh_t *mysh)
{
    char *line = NULL;
    size_t len = 0;
    int nb, i;
    ssize_t read = 0;
    pid_t pid;
    if (isatty(STDIN_FILENO) != 0) my_putstr("$>: ");
    while (1) {
        read = getline(&line, &len, stdin);
        if (read == -1) break;
        char **str = str_convertion(line);
        int e = count_cmd(str);
        if (my_strcmp("exit", str[0]) == 0) break;
        if (e > 1) mysh->re = 1;
        for (int i = 0; i < e; i++) {
            mysh->y = i;
            pid = loop(line, mysh, str, e);
            if (pid != -1)
                if (isatty(STDIN_FILENO) != 0) kill(pid, 2); }
    }
    return (0);
}

int main(int argc , char **argv , char **env)
{
    if (argc != 1) return (84);
    if (env == NULL)
        env = create_env();
    mysh_t *mysh = malloc(sizeof(mysh_t));
    mysh->env = env;
    mysh->re = 0;
    get_path(mysh);
    minishell(mysh);
}