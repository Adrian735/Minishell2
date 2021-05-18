/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** get_str
*/

/*
** EPITECH PROJECT, 2021
** solo stumper
** File description:
** main
*/

#include "../include/my.h"

char *get_str(char **str)
{
    int i, j;
    int count2;
    int count = my_strlen(str[1]);
    if (str[2] != NULL) count2 = my_strlen(str[2]) - 2;
    else count2 = 0;
    char *str2;
    str2 = (char *) malloc(sizeof(char) * (count + count2 + 1));
    int e = 0;
    for (i = 0; str[1][i] != '\0'; i++)
        str2[i] = str[1][i];
    str2[i] = 61;
    i++;
    if (str[2] != NULL) {
        for (e = 0; str[2][e] != '\0'; i++) {
            str2[i] = str[2][e];
            e++;
        }
    }
    str2[i] = '\0';
    return (str2);
}

char **modif_env(char **str, int a, char **env)
{
    int j, i;
    int b = 0;
    int e = 1;
    int count = 0;
    if (str[2] != NULL)
        env[a] = malloc(my_strlen(str[2]) + my_strlen(str[1]) + 5);
    else
        env[a] = malloc(my_strlen(str[1]) + 5);
    for (i = 0; i < my_strlen(str[1]); i++)
        env[a][i] = str[1][i];
    env[a][i] = 61;
    i++;
    if (str[2] != NULL) {
        for (j = 1; j < my_strlen(str[2]) - 1; j++, i++)
            env[a][i] = str[2][j];
    }
    env[a][i] = '\0';
    return (env);
}

int setenv2(char **str, char **env)
{
    int i;
    int a = check_arg_setenv(str, env);
    if (a == -1) {
        my_putstr("argument incorrect\n");
        my_putstr("$>: ");
        return (1);
    }
    return (0);
}

int unsetenv2(char **str, char **env)
{
    int i, j;
    int e = -1;

    if (check_arg_unsetenv(str, env) != 0)
        return (-1);

    for (i = 0; env[i] != NULL; i++) {
        for (j = 0; env[i][j] != 61; j++) {
            if (j == my_strlen(str[1]) - 1)
                e = i;
            if (env[i][j] != str[1][j]) break;
        }
    }
    return (e);
}

char *search_path(char **env)
{
    char *path = "PATH";
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
        int k = 5;
    value = malloc((my_strlen(env[e]) - 2) * sizeof(char));
        for (j = 0; env[e][k] != '\0'; j++) {
            value[j] = env[e][k];
            k++;
        }
        value[j] = '/';
        value[j + 1] = '\0';
        return (value);
    }
    return (0);}