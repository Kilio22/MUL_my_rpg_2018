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

sfBool all_world_hitBox(obj_t *obj, house_t **house)
{
    for (int i = 0; house[i] != NULL; i++)
        if (pp_intersect(obj->sprite, house[i]->interior, obj->image, house[i]->image) == 1)
            return (1);
    return (0);
}

void outside(controls_t *control, obj_t *obj, house_t **house)
{
    sfVector2f newPos = {0, 0};

    if (control->bools[KEYUP] == 1)
        newPos.y -= 1;
    if (control->bools[KEYDOWN] == 1)
        newPos.y += 1;
    sfSprite_move(obj->sprite, newPos);
    if (all_world_hitBox(obj, house) == 1)
        newPos.y *= -1;
    if (control->bools[KEYLEFT] == 1)
        newPos.x -= 1;
    if (control->bools[KEYRIGHT] == 1)
        newPos.x += 1;
    sfSprite_move(obj->sprite, newPos);
    newPos.y = 0;
    if (all_world_hitBox(obj, house) == 1)
        newPos.x *= -1;
    sfSprite_move(obj->sprite, newPos);
    obj->pos = sfSprite_getPosition(obj->sprite);
}

void character_control(controls_t *control, obj_t *obj, house_t **house)
{
    if (control->bools[KEYY] == 0)
        outside(control, obj, house);
}

void game_loop(wind_t *wind, controls_t *control, obj_t **obj, house_t **house)
{
    if (control->bools[KEYSPACE] == 1)          // setPosition of the character on camera
        sfSprite_setPosition(obj[1]->sprite, sfView_getCenter(wind->view));
    character_control(control, obj[1], house);
    all_character_animation(obj);
    house_interaction(obj[1], control, house);
    sfSprite_setPosition(obj[2]->sprite, sfSprite_getPosition(obj[1]->sprite));
    camera_control(wind, control, obj[1]->pos);
    update_all_rect(obj);
}

void init_game_loop(wind_t *wind, controls_t *control, obj_t **obj, house_t **house)
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
    controls_t *control = malloc(sizeof(controls_t));
    obj_t **obj = malloc(sizeof(obj_t *) * 10);
    house_t **house = malloc(sizeof(house_t *) * 10);

    wind->wind = create_window("test window", 10);
    sfVector2u windowSize = sfRenderWindow_getSize(wind->wind);
    wind->view = sfView_createFromRect((sfFloatRect){0, 0, windowSize.x, windowSize.y});

    obj[0] = create_object("assets/demo_map.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 620, 620}, sfFalse);
    obj[1] = create_object("assets/hero_hitbox.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 32, 16}, sfTrue);
    obj[2] = create_object("assets/hero.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 32, 64}, sfFalse);
    obj[3] = create_object("assets/stupid_nathan.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 32, 64}, sfFalse);
    house[0] = create_house(1, (sfVector2f){0, 0});
    house[1] = create_house(2, (sfVector2f){200, 0});
    house[2] = create_house(1, (sfVector2f){500, 0});
    house[3] = create_house(2, (sfVector2f){0, 300});
    house[4] = create_house(1, (sfVector2f){300, 300});

    sfSprite_setOrigin(obj[2]->sprite, (sfVector2f){16, 60});
    sfSprite_setOrigin(obj[3]->sprite, (sfVector2f){16, 60});

    control->bools = malloc(sizeof(sfBool) * 9);
    for (int i = 0; i < 9; i++)
        control->bools[i] = 0;
    init_controls(control);
    init_game_loop(wind, control, obj, house);
    return (0);
}