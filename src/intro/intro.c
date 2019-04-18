/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro
*/

#include "rpg.h"

static void intro_display(rpg_t *rpg, obj_t **obj, house_t **house, intro_t *i)
{
    if (MENU.menu_on == 2)
        return;
    sfRenderWindow_setView(WIND.wind, WIND.view);
    print_map(MAP.sprite, obj, rpg->wind);
    house_display(rpg, house);
    for (int i = 10; i > 0; i--)
        if (obj[i] != NULL && i != 4)
            sfRenderWindow_drawSprite(WIND.wind, obj[i]->sprite, NULL);
    print_map2(MAP.sprite, obj, rpg->wind);
    for (int i = 0; house[i] != NULL; i++) {
        if (house[i]->type == 2 && obj[9] == NULL && house[i]->display_house == 0) {
            obj[9] = create_object("assets/perso_blanc.png", (sfVector2f){9246, 1120}, (sfIntRect){0, 0, 32, 64}, sfTrue);
            obj[10] = create_object("assets/perso_vert.png", (sfVector2f){9460, 912}, (sfIntRect){0, 0, 32, 64}, sfTrue);
        }
        if (house[i]->display_house == 1)
            sfRenderWindow_drawSprite(WIND.wind, house[i]->tab[ROOF], NULL);
    }
    if (rpg->quest_status != 24)
        sfRenderWindow_drawText(WIND.wind, i->text, NULL);
    update_fondu_rect(i, rpg);
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

intro_t create_struct_intro(rpg_t *rpg, obj_t **obj)
{
    intro_t new;
    sfVector2f oui = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 0}, WIND.view);

    new.text = create_text(MENU_FONT, "", 13,
sfSprite_getPosition(obj[6]->sprite));
    new.fondu = create_rect(oui, (sfVector2f){1280, 720});
    return new;
}

int intro_game(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfVector2u windSize = sfRenderWindow_getSize(WIND.wind);
    intro_t intro = create_struct_intro(rpg, obj);

    sfClock_restart(obj[1]->clock);
    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            intro_event_management(rpg);
        if (MENU.menu_on == 0) {
            MENU.menu_on = 1;
            sfView_destroy(WIND.view);
            WIND.view =
sfView_createFromRect((sfFloatRect){0, 0, windSize.x, windSize.y});
            return 0;
        }
        if (MENU.menu_on == 2)
            return 1;
        intro_action(rpg, obj, house, &intro);
        intro_display(rpg, obj, house, &intro);
    }
    return 0;
}