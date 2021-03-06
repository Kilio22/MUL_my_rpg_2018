/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_event
*/

#include "inventory.h"

void inventory_event_stock(inventory_t *inv)
{
    inventory_event_select(inv);
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (!inv->stock[i])
            continue;
        dragndrop_event(inv->stock[i]->display, inv->window);
    }
}

void inventory_event_stuff(inventory_t *inv)
{
    for (int i = 0; i < 6; i++) {
        if (!inv->stuff[inv->state][i])
            continue;
        dragndrop_event(inv->stuff[inv->state][i]->display, inv->window);
    }
}

static int is_under_dragging(inventory_t *inv)
{
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inv->stock[i] == NULL)
            continue;
        if (dragndrop_isunderdragging(inv->stock[i]->display))
            return (TRUE);
    }
    for (int i = 0; i < 6; i++) {
        if (inv->stuff[inv->state][i] == NULL)
            continue;
        if (dragndrop_isunderdragging(inv->stuff[inv->state][i]->display))
            return (TRUE);
    }
    return (FALSE);
}

void inventory_event_select(inventory_t *inv)
{
    sfVector2i p = sfMouse_getPositionRenderWindow(inv->window);

    if (is_under_dragging(inv))
        return;
    if (!sfMouse_isButtonPressed(sfMouseLeft))
        return;
    if (p.x > 300 && p.x < 370 && p.y > 80 && p.y < 135)
        inv->state = 0;
    if (p.x > 300 && p.x < 370 && p.y > 160 && p.y < 200)
        inv->state = 1;
    if (p.x > 300 && p.x < 370 && p.y > 230 && p.y < 290)
        inv->state = 2;
}