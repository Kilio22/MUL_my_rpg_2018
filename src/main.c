/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

int main(int ac, char **av)
{
    rpg_t rpg;
    obj_t **obj = malloc(sizeof(obj_t *) * 11);
    house_t **house = malloc(sizeof(house_t *) * 6);
    sfVector2u windowSize;

    if (obj == NULL || house == NULL)
        return (84);
    rpg.debug = 0;
    rpg.error_code = 0;
    if (ac == 2) {
        if (my_strcmp(av[1], "-d") == 0)
            rpg.debug = 1;
        else
            return (84);
    }
    if (ac > 2)
        return 84;
    rpg.wind.wind = create_window("Nuck Fathan", 10);
    windowSize = sfRenderWindow_getSize(rpg.wind.wind);
    rpg.wind.view = sfView_createFromRect((sfFloatRect){0, 0, windowSize.x, windowSize.y});

    for (int i = 0; i < 11; i++)
        obj[i] = NULL;

    //check si les obj sont NULL -> malloc failed
    obj[0] = create_object("assets/hero_hitbox.png", (sfVector2f){10280, 2800}, (sfIntRect){0, 0, 32, 16}, sfTrue);
    if (obj[0] == NULL)
        return (84);
    obj[0]->rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(obj[0]->rectangle, V2F(32, 16));
    sfRectangleShape_setOrigin(obj[0]->rectangle, V2F(16, 8));
    obj[1] = create_object("assets/hero.png", (sfVector2f){10280, 2800}, (sfIntRect){0, 0, 32, 64}, sfFalse);
    if (obj[1] == NULL)
        return (84);
    obj[4] = create_object("assets/map_hitbox.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 11776, 2560}, sfFalse);
    if (obj[4] == NULL)
        return (84);
    obj[5] = create_object("assets/perso_blanc.png", (sfVector2f){10194, 1676}, (sfIntRect){0, 0, 32, 64}, sfTrue);
    if (obj[5] == NULL)
        return (84);
    obj[6] = create_object("assets/perso_blanc.png", (sfVector2f){10228, 1696}, (sfIntRect){0, 0, 32, 64}, sfTrue);
    if (obj[6] == NULL)
        return (84);
    obj[7] = create_object("assets/perso_blanc.png", (sfVector2f){10162, 1696}, (sfIntRect){0, 0, 32, 64}, sfTrue);
    if (obj[7] == NULL)
        return (84);
    obj[8] = create_object("assets/stupid_nathan.png", (sfVector2f){11128, 1076}, (sfIntRect){0, 0, 32, 64}, sfTrue);
    if (obj[8] == NULL)
        return (84);
    if (create_houses(house) == -1)
        return 84;
    rpg.house = house;
    sfSprite_setOrigin(obj[1]->sprite, (sfVector2f){16, 60});

    rpg.game.nb_save = 0;
    rpg.game.language = 0;
    rpg.controls.bools = malloc(sizeof(sfBool) * 9);
    if (rpg.controls.bools == NULL)
        return (84);
    for (int i = 0; i < 9; i++)
        rpg.controls.bools[i] = 0;
    create_music(&rpg);
    init_menu(&rpg, obj, house);
    if (rpg.error_code == 84)
        return (84);
    sfMusic_destroy(rpg.game.back_music);
    for (int i = 0; i < 5; i++)
        free_house(house[i]);
    for (int i = 0; i < 11; i++)
        free_obj(obj[i]);
    return (0);
}

/*#include "inventory.h"
#include "my_ini.h"

sfRenderWindow *init_window()
{
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "debug", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

int main()
{
    ini_file_t *file = ini_file_create_from_file("assets_data.ini");
    inventory_t *inv = inventory_create(init_window());
    item_t *item = item_create(0, file);
    item_t *item2 = item_create(1, file);

    inventory_add_item_to_stock(inv, item);
    inventory_add_item_to_stock(inv, item2);
    while (sfRenderWindow_isOpen(inv->window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(inv->window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(inv->window);
        }
        sfRenderWindow_clear(inv->window, sfBlack);
        inventory_compute(inv);
        sfRenderWindow_display(inv->window);
    }
    return 0;
}*/