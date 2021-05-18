/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** function
*/

#include "../include/my.h"

int command_cd(char **str, int nb, char **env)
{
    if (str[1] == NULL)
        return (0);
    if (my_strcmp(str[1], "-") == 0)
        str[1] = get_old_pwd(env);
    int a = chdir(str[1]);
    if (a == -1)
        miniprint("%s%s", str[1], ": Not a directory.\n");
    return (0);
}

char **command_setenv(char **str, char **env, int nb)
{
    int i;
    char **copy_env;
    if (setenv2(str, env) == 1) return (env);
    int a = check_arg_setenv(str, env);
    if (a != 0) {
        env = modif_env(str, a, env);
        return (env);
    }
    copy_env = env;
    for (i = 0; copy_env[i] != NULL; i++);
    if (str[2] != NULL)
        copy_env[i] = (char *) malloc((my_strlen(str[1]) + \
        my_strlen(str[2]) + 1) * sizeof(char));
    else
        copy_env[i] = (char *) malloc((my_strlen(str[1]) + 1) * sizeof(char));
    copy_env[i] = get_str(str);
    copy_env[i + 1] = NULL;
    return (copy_env);
}

int command_env(char **str, char **env, int nb)
{
    int i;
    for (i = 0; env[i] != NULL; i++)
    {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return (0);
}

char **command_unsetenv(char **str, char **env, int nb)
{
    char **copy_env;
    int i, j;
    int e = unsetenv2(str, env);

    if (e == -1) {
        return (env);
    }

    copy_env = env;
    for (; copy_env[e] != NULL; e++)
        copy_env[e] = copy_env[e + 1];

    return (copy_env);
}

char **other_fonct(char **cmd, int nb, char **env)
{
    int a = isatty(STDIN_FILENO);
    if (nb == 0)
        command_cd(cmd, a, env);
    if (nb == 1)
        env = command_setenv(cmd, env, a);
    if (nb == 2)
        command_env(cmd, env, a);
    if (nb == 3)
        env = command_unsetenv(cmd, env, a);
    return (env);
}