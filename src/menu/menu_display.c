/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu
*/

#include "rpg.h"

static void update_rectangle(rpg_t *rpg, int *move, float frame)
{
    sfVector2f pos = sfRectangleShape_getPosition(MENU.rect);
    sfVector2f text_pos = sfText_getPosition(MENU.buttons[MENU.highlight].text);

    if (pos.y == text_pos.y) {
        *move = -1;
        return;
    }
    if (*move == -1)
        return;
    for (int i = 0; i < frame; i++) {
        if (pos.y < text_pos.y)
            pos.y += 10;
        else
            pos.y -= 10;
    }
    sfRectangleShape_setPosition(MENU.rect, pos);
}

static void change_text(char **to_print,
int *print_index, int index, rpg_t *rpg)
{
    for (size_t i = 0; (i < rpg->frame || i <= 1) &&
*print_index < my_strlen(menu_desc[GAME.language][index]); i++) {
        (*to_print)[*print_index] =
menu_desc[GAME.language][index][*print_index];
        (*print_index)++;
        (*to_print)[*print_index] = '\0';
    }
}

static void update_text(rpg_t *rpg)
{
    static int print_index = 0;
    static int index = 0;
    static int lang = 0;
    static char *to_print = NULL;

    if (index != MENU.highlight || lang != GAME.language) {
        lang = GAME.language;
        index = MENU.highlight;
        print_index = 0;
        free(to_print);
        to_print = my_strdup("");
    }
    if (my_strlen(to_print) == 0)
        to_print = malloc(sizeof(char) *
(my_strlen(menu_desc[GAME.language][index]) + 1));
    change_text(&to_print, &print_index, index, rpg);
    sfText_setString(MENU.descr_text, to_print);
}

static void display_menu(rpg_t *rpg)
{
    if (!sfRenderWindow_isOpen(WIND.wind))
        return;
    sfRenderWindow_drawSprite(WIND.wind, MENU.menu_sprite[BACK], NULL);
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawText(WIND.wind, MENU.buttons[i].text, NULL);
    sfRenderWindow_drawRectangleShape(WIND.wind, MENU.rect, NULL);
    sfRenderWindow_drawText(WIND.wind, MENU.descr_text, NULL);
    sfRenderWindow_setView(WIND.wind, WIND.view);
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

void menu_loop(rpg_t *rpg, obj_t **obj, house_t **house)
{
    int move_rect = -1;
    size_t frames;

    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            menu_event_management(rpg, obj, house, &move_rect);
        rpg->frame = update_time(&frames);
        update_rectangle(rpg, &move_rect, frames);
        update_text(rpg);
        display_menu(rpg);
    }
}
