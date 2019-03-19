/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** camera_gestion
*/

#include "rpg.h"

static void zoom_gestion(rpg_t *rpg)
{
    if (CONTROLS.bools[ZOOM] == 1) {
        sfView_zoom(WIND.view, 0.9);
        CONTROLS.bools[ZOOM] = 0;
    }
    if (CONTROLS.bools[DEZOOM] == 1) {
        sfView_zoom(WIND.view, 1.1);
        CONTROLS.bools[DEZOOM] = 0;
    }
}

void camera_control(rpg_t *rpg, sfVector2f pos)
{
    zoom_gestion(rpg);
    if (CONTROLS.bools[KEYY] == 0)
        sfView_setCenter(WIND.view, pos);
    else {
        if (CONTROLS.bools[KEYRIGHT] == 1)
            sfView_move(WIND.view, (sfVector2f){10, 0});
        if (CONTROLS.bools[KEYLEFT] == 1)
            sfView_move(WIND.view, (sfVector2f){-10, 0});
        if (CONTROLS.bools[KEYDOWN] == 1)
            sfView_move(WIND.view, (sfVector2f){0, 10});
        if (CONTROLS.bools[KEYUP] == 1)
            sfView_move(WIND.view, (sfVector2f){0, -10});
    }
}