/*
** EPITECH PROJECT, 2018
** main
** File description:
** description
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "pp_hitbox.h"
#include "proto.h"
#include "struct.h"

sfRenderWindow *create_window(char *title, float scale)
{
    sfVideoMode mode = {256 * scale, 144 * scale, 32};
    sfRenderWindow *wind = sfRenderWindow_create(
    mode, title, sfDefaultStyle, NULL);
    sfRenderWindow_setVerticalSyncEnabled(wind, sfTrue);
    sfRenderWindow_setFramerateLimit(wind, 60);
    sfRenderWindow_setPosition(wind, (sfVector2i){0, 0});
    sfRenderWindow_setMouseCursorGrabbed(wind, sfTrue);
    return (wind);
}

void house_creation(house_t *house, char *path, sfVector2f pos, sfIntRect rect)
{
    house->image = sfImage_createFromFile(path);
    house->houseTexture = sfTexture_createFromFile(path, NULL);
    house->interior = sfSprite_create();
    house->wall = sfSprite_create();
    house->roof = sfSprite_create();
    sfSprite_setTexture(house->interior, house->houseTexture, sfTrue);
    sfSprite_setTexture(house->wall, house->houseTexture, sfTrue);
    sfSprite_setTexture(house->roof, house->houseTexture, sfTrue);
    sfSprite_setTextureRect(house->interior, rect);
    rect.left += rect.width;
    sfSprite_setTextureRect(house->roof, rect);
    rect.left += rect.width;
    sfSprite_setTextureRect(house->wall, rect);
    sfSprite_setPosition(house->interior, pos);
    sfSprite_setPosition(house->wall, pos);
    sfSprite_setPosition(house->roof, pos);
}

void door_creation(house_t *house, char *path, sfVector2f pos, sfIntRect rect)
{
    house->door = sfSprite_create();
    house->doorTexture = sfTexture_createFromFile(path, NULL);
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

obj_t *create_object(char *Path, sfVector2f pos, sfIntRect intrect, sfBool centered)
{
    obj_t *obj = malloc(sizeof(obj_t));
    sfFloatRect rect;

    obj->image = sfImage_createFromFile(Path);
    obj->texture = sfTexture_createFromFile(Path, NULL);
    obj->sprite = sfSprite_create();
    obj->pos = pos;
    obj->sprite_rect = intrect;
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, intrect);
    sfSprite_setPosition(obj->sprite, pos);
    if (centered == 1) {
        rect = sfSprite_getGlobalBounds(obj->sprite);
        sfSprite_setOrigin(obj->sprite, (sfVector2f)
        {rect.width / 2, rect.height / 2});
    }
    return (obj);
}

void display(wind_t *wind, obj_t **obj, house_t **house)
{
        
    sfRenderWindow_setView(wind->wind, wind->view);
    sfRenderWindow_drawSprite(wind->wind, obj[0]->sprite, NULL);
    // sfRenderWindow_drawSprite(wind->wind, obj[1]->sprite, NULL);
    for (int i = 0; house[i] != NULL; i++)
        sfRenderWindow_drawSprite(wind->wind, house[i]->interior, NULL);
    for (int i = 0; house[i] != NULL; i++)
        sfRenderWindow_drawSprite(wind->wind, house[i]->wall, NULL);
    for (int i = 0; house[i] != NULL; i++)
        sfRenderWindow_drawSprite(wind->wind, house[i]->door, NULL);
    sfRenderWindow_drawSprite(wind->wind, obj[2]->sprite, NULL);
    for (int i = 0; house[i] != NULL; i++)
        sfRenderWindow_drawSprite(wind->wind, house[i]->roof, NULL);
    sfRenderWindow_display(wind->wind);
    sfRenderWindow_clear(wind->wind, sfBlack);
}

sfBool all_world_hitBox(obj_t **obj, house_t **house)
{
    for (int i = 0; house[i] != NULL; i++)
        if (pp_intersect(obj[1]->sprite, house[i]->interior, obj[1]->image, house[i]->image) == 1)
            return (1);
}

void inside(myBool_t *myBool, obj_t **obj, house_t **house)
{
    sfVector2f newPos = {0, 0};

    if (myBool->keyUp == 1)
        newPos.y -= 1;
    if (myBool->keyDown == 1)
        newPos.y += 1;
    sfSprite_move(obj[1]->sprite, newPos);
    if (all_world_hitBox(obj, house) == 0)
        newPos.y *= -1;
    if (myBool->keyLeft == 1)
        newPos.x -= 1;
    if (myBool->keyRight == 1)
        newPos.x += 1;
    sfSprite_move(obj[1]->sprite, newPos);
    newPos.y = 0;
    if (all_world_hitBox(obj, house) == 0)
        newPos.x *= -1;
    sfSprite_move(obj[1]->sprite, newPos);
    obj[1]->pos = sfSprite_getPosition(obj[1]->sprite);
}

void outside(myBool_t *myBool, obj_t **obj, house_t **house)
{
    sfVector2f newPos = {0, 0};

    if (myBool->keyUp == 1)
        newPos.y -= 1;
    if (myBool->keyDown == 1)
        newPos.y += 1;
    sfSprite_move(obj[1]->sprite, newPos);
    if (all_world_hitBox(obj, house) == 1)
        newPos.y *= -1;
    if (myBool->keyLeft == 1)
        newPos.x -= 1;
    if (myBool->keyRight == 1)
        newPos.x += 1;
    sfSprite_move(obj[1]->sprite, newPos);
    newPos.y = 0;
    if (all_world_hitBox(obj, house) == 1)
        newPos.x *= -1;
    sfSprite_move(obj[1]->sprite, newPos);
    obj[1]->pos = sfSprite_getPosition(obj[1]->sprite);
}

void character_orientation(obj_t *obj, sfVector2f oldPos, sfVector2f newPos)
{
    if (oldPos.x < newPos.x)
        obj->sprite_rect.top = 64;
    else if (oldPos.x > newPos.x)
        obj->sprite_rect.top = 0;
    else if (oldPos.y > newPos.y) {
        obj->sprite_rect.top = 128;
        if (obj->sprite_rect.left >= 128)
            obj->sprite_rect.left = 0;
    }
    else if (oldPos.y < newPos.y) {
        obj->sprite_rect.top = 192;
        if (obj->sprite_rect.left >= 128)
            obj->sprite_rect.left = 0;
    }
    else
        obj->sprite_rect.left = 0;
}

void character_animation(obj_t *obj)
{
    static int i = 0;
    static sfVector2f newPos = {0, 0};
    sfVector2f oldPos = sfSprite_getPosition(obj->sprite);

    if (i == 8) {
        animation(&obj->sprite_rect, 32, 32, 160);
        i = 0;
    }
    character_orientation(obj, oldPos, newPos);
    i++;
    newPos = sfSprite_getPosition(obj->sprite);
}

void character_control(myBool_t *myBool, obj_t **obj, house_t **house)
{
    character_animation(obj[2]);
    outside(myBool, obj, house);
    // inside(myBool, obj, house);
}

void zoom_gestion(wind_t *wind, myBool_t *myBool)
{
    if (myBool->zoom == 1) {
        sfView_zoom(wind->view, 0.9);
        myBool->zoom = 0;
    }
    if (myBool->deZoom == 1) {
        sfView_zoom(wind->view, 1.1);
        myBool->deZoom = 0;
    }
}

void camera_control(wind_t *wind, myBool_t *myBool, sfVector2f pos)
{
    zoom_gestion(wind, myBool);
    if (myBool->keySpace == 1 || myBool->keyY == 1)
        sfView_setCenter(wind->view, pos);
    else {
        wind->windSize = sfRenderWindow_getSize(wind->wind);
        if (myBool->mousePos.x > wind->windSize.x - 10)
            sfView_move(wind->view, (sfVector2f){5, 0});
        if (myBool->mousePos.x < 10)
            sfView_move(wind->view, (sfVector2f){-5, 0});
        if (myBool->mousePos.y > wind->windSize.y - 10)
            sfView_move(wind->view, (sfVector2f){0, 5});
        if (myBool->mousePos.y < 10)
            sfView_move(wind->view, (sfVector2f){0, -5});
    }
}

void game_loop(wind_t *wind, myBool_t *myBool, obj_t **obj, house_t **house)
{
    character_control(myBool, obj, house);
    camera_control(wind, myBool, obj[1]->pos);
    sfSprite_setTextureRect(obj[2]->sprite, obj[2]->sprite_rect);
    sfSprite_setPosition(obj[2]->sprite, sfSprite_getPosition(obj[1]->sprite));
}

void init_game_loop(wind_t *wind, myBool_t *myBool, obj_t **obj, house_t **house)
{
    sfClock *main_clock = sfClock_create();
    sfTime main_time;
    float main_seconds;

    while (sfRenderWindow_isOpen(wind->wind))
    {
        main_time = sfClock_getElapsedTime(main_clock);
        main_seconds = main_time.microseconds / 10000;
        while (sfRenderWindow_pollEvent(wind->wind, &wind->event))
            event_management(wind, myBool);
        if (main_seconds > 0) {
            game_loop(wind, myBool, obj, house);
            sfClock_restart(main_clock);
        }
        display(wind, obj, house);
    }
}

int main(void)
{
    wind_t *wind = malloc(sizeof(wind_t));
    myBool_t *myBool = malloc(sizeof(myBool_t));
    obj_t **obj = malloc(sizeof(obj_t *) * 10);
    house_t **house = malloc(sizeof(house_t *) * 10);

    wind->wind = create_window("test window", 7);
    sfVector2u windowSize = sfRenderWindow_getSize(wind->wind);
    wind->view = sfView_createFromRect((sfFloatRect){0, 0, windowSize.x, windowSize.y});

    obj[0] = create_object("assets/demo_map.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 620, 620}, sfFalse);
    obj[1] = create_object("assets/hero_hitbox.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 32, 16}, sfTrue);
    obj[2] = create_object("assets/hero.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 32, 64}, sfFalse);
    house[0] = create_house(1, (sfVector2f){0, 0});
    house[1] = create_house(2, (sfVector2f){200, 0});
    house[2] = create_house(1, (sfVector2f){500, 0});
    house[3] = create_house(2, (sfVector2f){0, 300});
    house[4] = create_house(1, (sfVector2f){300, 300});

    sfSprite_setOrigin(obj[2]->sprite, (sfVector2f){16, 60});

    myBool->keyUp = 0;
    myBool->keyDown = 0;
    myBool->keyLeft = 0;
    myBool->keyRight = 0;   
    myBool->keySpace = 0;
    myBool->keyY = 1;

    init_game_loop(wind, myBool, obj, house);
    return (0);
}