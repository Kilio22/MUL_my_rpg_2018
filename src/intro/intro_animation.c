/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_animation
*/

#include "rpg.h"

static void character_orientation_intro(obj_t *obj)
{
    if (obj->oldPos.x < obj->pos.x) {
        obj->sprite_rect.top = 64;
        return;
    }
    if (obj->oldPos.x > obj->pos.x) {
        obj->sprite_rect.top = 0;
        return;
    }
    if (obj->oldPos.y > obj->pos.y) {
        obj->sprite_rect.top = 128;
        if (obj->sprite_rect.left >= 128)
            obj->sprite_rect.left = 0;
    }
    else if (obj->oldPos.y < obj->pos.y) {
        obj->sprite_rect.top = 192;
        if (obj->sprite_rect.left >= 128)
            obj->sprite_rect.left = 0;
    }
    else
        obj->sprite_rect.left = 0;
}

static void character_animation_intro(obj_t *obj)
{
    if (obj->frame_animation > 8) {
        animation(&obj->sprite_rect, 32, 32, 160);
        obj->frame_animation = 0;
    }
    obj->frame_animation += update_time(NULL);
    obj->oldPos = sfSprite_getPosition(obj->sprite);
    character_orientation_intro(obj);
    obj->pos = sfSprite_getPosition(obj->sprite);
}

void all_character_animation_intro(rpg_t *rpg, obj_t **obj)
{
    for (int i = 1; i < 12; i++) {
        if (i == 9 && rpg->quest_status < 3)
            continue;
        if (obj[i] != NULL)
            character_animation_intro(obj[i]);
    }
}
