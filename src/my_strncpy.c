/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** my_strncpy
*/

#include "../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int s;
    dest = malloc(my_strlen(src) + 1);

    for (s = 0; src[s] != '\0' && s < n; s++)
    {
        dest[s] = src[s];
    }
    dest[s] = '\0';
    return (dest);
}

