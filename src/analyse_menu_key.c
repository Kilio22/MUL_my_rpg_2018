/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** analyse_menu_key
*/

#include "rpg.h"

void analyse_menu_key_released(int code, rpg_t *rpg, obj_t **obj, house_t **h)
{
    if (code == sfKeyReturn) {
        MENU.buttons[MENU.highlight].status = 0;
        sfText_setColor(MENU.buttons[MENU.highlight].text, sfYellow);
        menu[MENU.highlight](rpg, obj, h);
    }
}

void analyse_menu_key_pressed(int code, rpg_t *rpg)
{
    if (code == sfKeyEscape)
        sfRenderWindow_close(WIND.wind);
    if (code == sfKeyF1)
        GAME.nb_save = 0;
    if (code == sfKeyF2)
        GAME.nb_save = 1;
    if (code == sfKeyF5)
        set_music(rpg);
    if (code == sfKeyDown && MENU.highlight < 5) {
        MENU.highlight++;
        sfText_setColor(MENU.buttons[MENU.highlight].text, sfYellow);
    }
    if (code == sfKeyUp && MENU.highlight > 0) {
        sfText_setColor(MENU.buttons[MENU.highlight].text, sfRed);
        MENU.highlight--;
        sfText_setColor(MENU.buttons[MENU.highlight].text, sfYellow);
    }
    if (code == sfKeyReturn) {
        MENU.buttons[MENU.highlight].status = 1;
        sfText_setColor(MENU.buttons[MENU.highlight].text, sfBlue);
    }
}