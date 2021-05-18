/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** create_env
*/

#include "../include/my.h"

char **create_env(void)
{
    char **env;
    env = malloc (5 * sizeof(char *));
    env[0] = "LANG=fr_FR.utf8\0";
    env[1] = "COLORTERM=truecolor\0";
    env[2] = "PATH=/bin/\0";
    env[3] = "DISPLAY=:0.0\0";
    env[4] = NULL;
    return (env);
}