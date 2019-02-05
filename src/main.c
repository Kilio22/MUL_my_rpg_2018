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
    return (0);
}

void inside(control_t *control, obj_t **obj, house_t **house)
{
    sfVector2f newPos = {0, 0};

    if (control->keyUp == 1)
        newPos.y -= 1;
    if (control->keyDown == 1)
        newPos.y += 1;
    sfSprite_move(obj[1]->sprite, newPos);
    if (all_world_hitBox(obj, house) == 0)
        newPos.y *= -1;
    if (control->keyLeft == 1)
        newPos.x -= 1;
    if (control->keyRight == 1)
        newPos.x += 1;
    sfSprite_move(obj[1]->sprite, newPos);
    newPos.y = 0;
    if (all_world_hitBox(obj, house) == 0)
        newPos.x *= -1;
    sfSprite_move(obj[1]->sprite, newPos);
    obj[1]->pos = sfSprite_getPosition(obj[1]->sprite);
}

void outside(control_t *control, obj_t **obj, house_t **house)
{
    sfVector2f newPos = {0, 0};

    if (control->keyUp == 1)
        newPos.y -= 1;
    if (control->keyDown == 1)
        newPos.y += 1;
    sfSprite_move(obj[1]->sprite, newPos);
    if (all_world_hitBox(obj, house) == 1)
        newPos.y *= -1;
    if (control->keyLeft == 1)
        newPos.x -= 1;
    if (control->keyRight == 1)
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

void character_control(control_t *control, obj_t **obj, house_t **house)
{
    character_animation(obj[2]);
    outside(control, obj, house);
    // inside(control, obj, house);
}

void zoom_gestion(wind_t *wind, control_t *control)
{
    if (control->zoom == 1) {
        sfView_zoom(wind->view, 0.9);
        control->zoom = 0;
    }
    if (control->deZoom == 1) {
        sfView_zoom(wind->view, 1.1);
        control->deZoom = 0;
    }
}

void camera_control(wind_t *wind, control_t *control, sfVector2f pos)
{
    zoom_gestion(wind, control);
    if (control->keySpace == 1 || control->keyY == 1)
        sfView_setCenter(wind->view, pos);
    else {
        wind->windSize = sfRenderWindow_getSize(wind->wind);
        if (control->mousePos.x > wind->windSize.x - 10)
            sfView_move(wind->view, (sfVector2f){5, 0});
        if (control->mousePos.x < 10)
            sfView_move(wind->view, (sfVector2f){-5, 0});
        if (control->mousePos.y > wind->windSize.y - 10)
            sfView_move(wind->view, (sfVector2f){0, 5});
        if (control->mousePos.y < 10)
            sfView_move(wind->view, (sfVector2f){0, -5});
    }
}

void game_loop(wind_t *wind, control_t *control, obj_t **obj, house_t **house)
{
    character_control(control, obj, house);
    camera_control(wind, control, obj[1]->pos);
    sfSprite_setTextureRect(obj[2]->sprite, obj[2]->sprite_rect);
    sfSprite_setPosition(obj[2]->sprite, sfSprite_getPosition(obj[1]->sprite));
}

void init_game_loop(wind_t *wind, control_t *control, obj_t **obj, house_t **house)
{
    sfClock *main_clock = sfClock_create();
    sfTime main_time;
    float main_seconds;

    while (sfRenderWindow_isOpen(wind->wind))
    {
        main_time = sfClock_getElapsedTime(main_clock);
        main_seconds = main_time.microseconds / 10000;
        while (sfRenderWindow_pollEvent(wind->wind, &wind->event))
            event_management(wind, control);
        if (main_seconds > 0) {
            game_loop(wind, control, obj, house);
            sfClock_restart(main_clock);
        }
        display(wind, obj, house);
    }
}

int main(void)
{
    wind_t *wind = malloc(sizeof(wind_t));
    control_t *control = malloc(sizeof(control_t));
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

    control->keyUp = 0;
    control->keyDown = 0;
    control->keyLeft = 0;
    control->keyRight = 0;   
    control->keySpace = 0;
    control->keyY = 1;

    init_game_loop(wind, control, obj, house);
    return (0);
}