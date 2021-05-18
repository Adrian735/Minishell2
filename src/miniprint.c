/*
** EPITECH PROJECT, 2021
** miniprint
** File description:
** miniprint
*/

#include <stdarg.h>
#include "../include/my.h"

void my_print_d_i(va_list *list)
{
    int d = va_arg(*list, int);
    my_put_nbr(d);
}

void my_print_c(va_list *list)
{
    char c = va_arg(*list, int);
    my_putchar(c);
}

void  my_print_s(va_list *list)
{
    char *str = va_arg(*list, char *);
    my_putstr(str);
}

int array(char c)
{
    char tab[3] = {'c', 's', 'd'};
    int i = 0;
    while (i < 3)
    {
        if (c == tab[i])
            return (i);
        i++;
    }
    return (84);
}

int miniprint(char const *format, ...)
{
    void (*tabFunc[3])(va_list *) = {my_print_c, my_print_s,
    my_print_d_i};
    int i = 0;
    int d;
    va_list list;
    va_start(list, format);
    for (i = 0; format[i] != '\0'; i++){
        if (i != 0 && format[i-1] == '%'){
            d = array(format[i]);
            (*tabFunc[d])(&list);
        }
        else if (format[i] != '%')
            write(1, &format[i], 1);
    }
    va_end(list);
    return (0);
}