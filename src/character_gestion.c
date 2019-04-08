/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** character_gestion
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

static sfBool all_world_hitBox(obj_t *obj, house_t **house)
{
    for (int i = 0; house[i] != NULL; i++)
        if (pp_intersect(obj->sprite, house[i]->tab[HITBOX],
obj->image, house[i]->image) == 1)
            return (1);
    return (0);
}

void apply_controls_character(rpg_t *rpg, obj_t *obj, house_t **house)
{
    sfVector2f newPos = {0, 0};

    if (CONTROLS.bools[KEYUP] == 1)
        newPos.y -= 1;
    if (CONTROLS.bools[KEYDOWN] == 1)
        newPos.y += 1;
    sfSprite_move(obj->sprite, newPos);
    if (all_world_hitBox(obj, house) == 1)
        newPos.y *= -1;
    if (CONTROLS.bools[KEYLEFT] == 1)
        newPos.x -= 1;
    if (CONTROLS.bools[KEYRIGHT] == 1)
        newPos.x += 1;
    sfSprite_move(obj->sprite, newPos);
    newPos.y = 0;
    if (all_world_hitBox(obj, house) == 1)
        newPos.x *= -1;
    sfSprite_move(obj->sprite, newPos);
    obj->pos = sfSprite_getPosition(obj->sprite);
}

void character_control(rpg_t *rpg, obj_t *obj, house_t **house)
{
    if (CONTROLS.bools[KEYY] == 0)
        apply_controls_character(rpg, obj, house);
}

void follower(obj_t **obj, rpg_t *rpg)
{
    static sfVector2f oldpos = {0, 0};
    sfVector2f pos = sfSprite_getPosition(obj[0]->sprite);

    if (pos.x > oldpos.x || pos.x < oldpos.x || pos.y > oldpos.y ||
pos.y < oldpos.y) {
        sfSprite_setPosition(obj[2]->sprite,
*(sfVector2f*)GAME.follower->start->content);
        modif_list(GAME.follower, obj[0]);
        sfSprite_setPosition(obj[3]->sprite,
*(sfVector2f*)GAME.follower2->start->content);
        modif_list(GAME.follower2, obj[2]);
    }
    oldpos = sfSprite_getPosition(obj[0]->sprite);
}