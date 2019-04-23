/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_other_utils
*/

#include "rpg.h"

char *my_ftoa(float value)
{
    int ent = value;
    int decimals = value * 100 - (ent * 100);
    char *string = my_itoa(ent, "");

    if (decimals != 0) {
        string = my_strncat(string, ".", -1);
        string = my_strncat(string, my_itoa(decimals, ""), -1);
    }
    return (string);
}

sfSound *create_sound(char const *path)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(path);

    sfSound_setVolume(sound, 200);
    sfSound_setBuffer(sound, buffer);
    return sound;
}