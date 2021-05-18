/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "../include/my.h"

int my_put_nbr(int nbr)
{
    int b = -1;
    if (nbr < 0)
    {
        my_putchar('-');
        nbr = nbr * b;
    }
    if (nbr > 9)
    {

        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);

    }
    else

    {
        my_putchar(nbr + 48);
    }

}
