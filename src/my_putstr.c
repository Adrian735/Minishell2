/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** my_putstr
*/

#include "../include/my.h"

int  my_putstr(char  const *str)
{
    int nb = 0;
    int count = 0;
    char caractereActuel = 0;

    do
    {
        caractereActuel = str[nb];
        nb++;
    }
    while (caractereActuel != '\0');

    nb--;

    while ( nb > count )
    {
        my_putchar(str[count]);
        count++;
    }
}
