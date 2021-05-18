/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** my_strlen
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int x = 0;
    int y = 0;
    while (str[x] != '\0')
    {
        y++;
        x++;
    }
    return (y);
}
