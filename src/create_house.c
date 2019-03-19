/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create_house
*/

#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

void house_interaction(obj_t *obj, house_t **house, rpg_t *rpg)
{
    for (int i = 0; house[i] != NULL; i++) {
        if (pp_intersect(obj->sprite, house[i]->door, obj->image, house[i]->door_image) == 1 && CONTROLS.bools[KEYINTER] == 1) {
            if (house[i]->display_house == 1) {
                if (house[i]->frame_animation > 8 && house[i]->door_rect.left < 384 - 96) {
                    animation(&house[i]->door_rect, 0, 96, 384);
                    house[i]->frame_animation = 0;
                }
                house[i]->frame_animation ++;
                if (house[i]->door_rect.left > 384 - 97) {
                    sfSprite_move(obj->sprite, (sfVector2f){0, -1});
                    if (pp_intersect(obj->sprite, house[i]->hitbox, obj->image, house[i]->image) == 0) {
                        house[i]->door_rect.left = 0;
                        house[i]->display_house = 0;
                        CONTROLS.bools[KEYINTER] = 0;
                    }
                }
            }
            else {
                if (house[i]->display_house == 0)
                    sfSprite_move(obj->sprite, (sfVector2f){0, 1});
                if (pp_intersect(obj->sprite, house[i]->hitbox, obj->image, house[i]->image) == 0) {
                    house[i]->display_house = 1;
                    CONTROLS.bools[KEYINTER] = 0;
                }
            }
        }
    }
}

void house_creation(house_t *house, char *path, sfVector2f pos, sfIntRect rect)
{
    house->image = sfImage_createFromFile(path);
    house->houseTexture = sfTexture_createFromFile(path, NULL);
    house->hitbox = sfSprite_create();
    house->interior = sfSprite_create();
    house->wall = sfSprite_create();
    house->roof = sfSprite_create();
    house->display_house = 1;

    sfSprite_setTexture(house->hitbox, house->houseTexture, sfTrue);
    sfSprite_setTexture(house->interior, house->houseTexture, sfTrue);
    sfSprite_setTexture(house->wall, house->houseTexture, sfTrue);
    sfSprite_setTexture(house->roof, house->houseTexture, sfTrue);

    sfSprite_setTextureRect(house->hitbox, rect);
    rect.left += rect.width;
    sfSprite_setTextureRect(house->interior, rect);
    rect.left += rect.width;
    sfSprite_setTextureRect(house->wall, rect);
    rect.left += rect.width;
    sfSprite_setTextureRect(house->roof, rect);

    sfSprite_setPosition(house->hitbox, pos);
    sfSprite_setPosition(house->interior, pos);
    sfSprite_setPosition(house->wall, pos);
    sfSprite_setPosition(house->roof, pos);
}

void door_creation(house_t *house, char *path, sfVector2f pos, sfIntRect rect)
{
    house->door = sfSprite_create();
    house->door_image = sfImage_createFromFile(path);
    house->doorTexture = sfTexture_createFromFile(path, NULL);
    house->door_rect = rect;
    house->frame_animation = 0;
    sfSprite_setTexture(house->door, house->doorTexture, sfTrue);
    sfSprite_setPosition(house->door, pos);
    sfSprite_setTextureRect(house->door, rect);
}

house_t *create_house(int type, sfVector2f housePos)
{
    house_t *house = malloc(sizeof(house_t));
    char *housePath;
    char *doorPath;
    sfIntRect houseRect;
    sfIntRect doorRect;
    sfVector2f doorPos;

    if (type == 1) {
        housePath = "assets/maison 1.png";
        doorPath = "assets/door1.png";
        houseRect = (sfIntRect){0, 0, 192, 320};
        doorRect = (sfIntRect){0, 0, 96, 96};
        doorPos = (sfVector2f){housePos.x + 0, housePos.y + 256};
    }
    else if (type == 2) {
        housePath = "assets/maison 2.png";
        doorPath = "assets/door1.png";
        houseRect = (sfIntRect){0, 0, 256, 256};
        doorRect = (sfIntRect){0, 0, 96, 96};
        doorPos = (sfVector2f){housePos.x + 0, housePos.y + 192};
    }
    house_creation(house, housePath, housePos, houseRect);
    door_creation(house, doorPath, doorPos, doorRect);
    return (house);
}