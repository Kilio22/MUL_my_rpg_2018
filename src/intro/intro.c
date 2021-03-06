/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro
*/

#include "rpg.h"

static void check_pnj_intro(obj_t **obj, house_t **house, rpg_t *rpg)
{
    for (int i = 0; house[i] != NULL; i++) {
        if (house[i]->type == 2 && obj[9] == NULL && !house[i]->display_house) {
            obj[9] = create_object(obj_path[5],
(sfVector2f){9886, 1440}, RECT_OBJ, sfTrue);
            obj[10] = create_object(obj_path[6],
(sfVector2f){10100, 1232}, RECT_OBJ, sfTrue);
        }
        if (house[i]->display_house == 1)
            sfRenderWindow_drawSprite(WIND.wind, house[i]->tab[ROOF], NULL);
    }
}

static void intro_display(rpg_t *rpg, obj_t **obj, house_t **house, intro_t *i)
{
    sfRenderWindow_clear(WIND.wind, sfBlack);
    if (MENU.menu_on == 2)
        return;
    sfRenderWindow_setView(WIND.wind, WIND.view);
    print_map(MAP.sprite, obj, rpg->wind);
    house_display(rpg, house);
    display_char(rpg, obj);
    print_map2(MAP.sprite, obj, rpg->wind);
    check_pnj_intro(obj, house, rpg);
    if (my_strcmp(sfText_getString(i->text), " ")
&& i->opt >= 3 && rpg->quest_status < 24)
        sfRenderWindow_drawSprite(WIND.wind, i->sprite, NULL);
    if (rpg->quest_status != 24)
        sfRenderWindow_drawText(WIND.wind, i->text, NULL);
    update_fondu_rect(i, rpg);
    sfRenderWindow_display(WIND.wind);
}

static intro_t create_struct_intro(rpg_t *rpg, obj_t **obj)
{
    intro_t new;
    sfVector2f vect = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 0}, WIND.view);
    sfTexture *text = sfTexture_createFromFile("assets/parchemin.png", NULL);

    new.text = create_text(menu_font, " ", 19,
sfSprite_getPosition(obj[6]->sprite));
    new.fondu = create_rect(vect, (sfVector2f){1280, 720});
    new.sprite = sfSprite_create();
    sfSprite_setTexture(new.sprite, text, sfTrue);
    sfSprite_setScale(new.sprite, V2F(0.6, 0.6));
    return new;
}

int return_to_game(rpg_t *rpg, obj_t **obj)
{
    sfVector2u windSize = sfRenderWindow_getSize(WIND.wind);

    if (MENU.menu_on == 0) {
        MENU.menu_on = 1;
        sfView_destroy(WIND.view);
        WIND.view =
sfView_createFromRect((sfFloatRect){0, 0, windSize.x, windSize.y});
        intro_fcts(rpg, obj, NULL, NULL);
        free_map(MAP);
        free_objs(obj);
        return 0;
    }
    if (MENU.menu_on == 2) {
        intro_fcts(rpg, obj, NULL, NULL);
        return 1;
    }
    return (2);
}

int intro_game(rpg_t *rpg, obj_t **obj, house_t **house)
{
    intro_t intro = create_struct_intro(rpg, obj);
    size_t frames;

    sfClock_restart(obj[1]->clock);
    while (sfRenderWindow_isOpen(WIND.wind)) {
        rpg->frame = update_time(&frames);
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            intro_event_management(rpg, obj, house);
        if (MENU.menu_on == 0 || MENU.menu_on == 2)
            return return_to_game(rpg, obj);
        intro_action(rpg, obj, house, &intro);
        intro_display(rpg, obj, house, &intro);
    }
    return 0;
}