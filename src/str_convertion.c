/*
** EPITECH PROJECT, 2021
** solo stumper
** File description:
** main
*/

#include "../include/my.h"

int count_word(char *str)
{
    int i;
    int count = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if ((str[i - 1] == 32 || str[i - 1] == 9) &&
        (str[i] != 9 && str[i] != 32 && str[i] != '\0' && str[i] != '\n'))
            count++;
    }
    return (count);
}

int len_word(char *str, int i)
{
    int e = 0;
    while (str[i] != 32 && str[i] != 9 && str[i] != '\n' && str[i] != '\0') {
        i++;
        e++;
    }
    return (e);
}

char **str_convertion(char *str)
{
    int i, j, e;
    int count = count_word(str);
    char **str2;
    str2 = (char **) malloc(sizeof(char *) * (count + 2));
    for (e = 0, i = 0; str[e] != '\0' && str[e] != '\n'; i++) {
        if (i == count + 1) break;
        while (str[e] == 32 || str[e] == 9) e++;
        int len = len_word(str, e);
        str2[i] = (char *) malloc(sizeof(char) * (len + 1));
        for (j = 0; str[e] != '\0' && str[e] != '\n'; j++, e++) {
            if (str[e] == 32 || str[e] == 9) {
                e++;
                str2[i][j] = '\0';
                break;
            }
            str2[i][j] = str[e]; }
    }
    str2[i - 1][j] = '\0';
    str2[i] = NULL;
    return (str2);
}