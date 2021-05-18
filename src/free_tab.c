/*
** EPITECH PROJECT, 2021
** solo stumper
** File description:
** main
*/

#include "../include/my.h"

void free_tab(char **tab)
{
    int i = 0;
    while (tab[i] != NULL){
        free(tab[i]);
        i++;
    }
    free(tab);
}