/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** delete_fight
*/

#include "inventory.h"
#include "rpg.h"

static void add_item(rpg_t *rpg, fight_t *fight)
{
    item_t *item;
    ini_file_t *ini = ini_file_create_from_file("assets_data.ini");

    item = item_create(0, ini);
    inventory_add_item(GAME.inv, item);
}

static void reinit_pos(obj_t **obj, fight_t *fight, rpg_t *rpg)
{
    if (fight->win == 1) {
        sfSprite_setPosition(obj[fight->nb_fight + 6]->sprite,
fight->old_pos[3]);
        obj[fight->nb_fight + 6]->pos =
sfSprite_getPosition(obj[fight->nb_fight + 6]->sprite);
    } else if (fight->win == 2) {
        free_obj(obj[fight->nb_fight + 6]);
        obj[fight->nb_fight + 6] = NULL;
        add_item(rpg, fight);
    } else {
        sfSprite_setPosition(obj[HERO_HB]->sprite, fight->old_pos[0]);
        sfSprite_setPosition(obj[2]->sprite, fight->old_pos[1]);
        sfSprite_setPosition(obj[3]->sprite, fight->old_pos[2]);
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        sfSprite_setPosition(obj[fight->nb_fight + 6]->sprite,
fight->old_pos[3]);
        obj[fight->nb_fight + 6]->pos =
sfSprite_getPosition(obj[fight->nb_fight + 6]->sprite);
    }
}

void delete_fight(fight_t *fight, obj_t **obj, rpg_t *rpg)
{
    sfRectangleShape_destroy(fight->fondu);
    sfFont_destroy((sfFont *)sfText_getFont(fight->text));
    sfText_destroy(fight->text);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(fight->parch));
    sfSprite_destroy(fight->parch);
    update_fondu_rect_fight(fight, rpg, 1);
    update_fight_text(fight, 1, rpg);
    reinit_pos(obj, fight, rpg);
    for (int i = 0; i < 5; i++) {
        sfFont_destroy((sfFont *)sfText_getFont(fight->attacks[i]));
        sfText_destroy(fight->attacks[i]);
    }
    choose_fighter(NULL, NULL, NULL, 0);
    fight_turn(NULL, NULL, 1);
}