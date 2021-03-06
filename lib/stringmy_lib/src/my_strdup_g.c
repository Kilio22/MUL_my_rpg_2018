/*
** EPITECH PROJECT, 2018
** mg_strdup
** File description:
** mg_strdup
*/

#include "mg_str.h"

char *mg_strdup(char const *src)
{
    char *new_str = malloc(sizeof(char) * (mg_strlen(src) + 1));

    if (!new_str)
        return (NULL);
    mg_strcpy(new_str, src);
    new_str[mg_strlen(src)] = '\0';
    return (new_str);
}

char *mg_strndup(char const *src, int n)
{
    int size = (mg_strlen(src) < n) ? mg_strlen(src) : n;
    char *new_str = malloc(sizeof(char) * (size + 1));

    if (!new_str)
        return (NULL);
    mg_strncpy(new_str, src, n);
    return (new_str);
}