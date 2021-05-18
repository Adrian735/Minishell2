/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{

    while (*s1 != '\0' && (*s1 == *s2))
    {
        s1 = s1 + 1;
        s2 = s2 + 1;
    }

    return (s1 == s2) ? 0 : (*(unsigned char *)s1 - *(unsigned char *)s2);
}
