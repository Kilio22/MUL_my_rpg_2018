/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_realloc_str
*/

#include "stdlib.h"
#include "my.h"

char *my_realloc_str(char *f, char *b)
{
    char *new = malloc(sizeof(char) * (my_strlen(f) + my_strlen(b) + 1));
    int nb = my_strlen(f);
    int len = my_strlen(b);
    int i = 0;

    if (new == NULL)
        return (NULL);
    for (i = 0; i < nb; i++)
        new[i] = f[i];
    if (b != NULL)
        for (int j = 0; j < len; j++) {
            new[i] = b[j];
            i++;
        }
    new[i] = '\0';
    return (new);
}