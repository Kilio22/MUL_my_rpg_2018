/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** list
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "rpg.h"

simple_vector_t *init_list(int x, int y)
{
    simple_vector_t *list = simple_vector_create();
    int max = x + 50;

    for (; x < max; x++) {
        sfVector2f *current = malloc(sizeof(sfVector2f));
        if (current == NULL)
            return NULL;
        current->x = x;
        current->y = y;
        simple_vector_push_back(list, current);
        x++;
    }
    return (list);
}

void modif_list(simple_vector_t *pos, obj_t *obj)
{
    sfVector2f *current = malloc(sizeof(sfVector2f));
    sfVector2f position = sfSprite_getPosition(obj->sprite);

    if (current == NULL)
        return;
    current->x = position.x;
    current->y = position.y;
    simple_vector_push_back(pos, current);
    free(pos->start->content);
    simple_vector_pop_top(pos);
}

//simple_vector_t *simple_vector_create(void); -> remplir
// pour ajouter a la fin de la liste (simple_vector_push_back)
// pour supprimer au debut de la liste (simple_vector_pop_top)

/*
    -----------------------------------

    while (list->start != 0) { //free all
        free(list->start->content);
        simple_vector_pop_top(list);
    }

    ------------------------------------

    free(list->end->content); //remove last sfVector2f in list
    simple_vector_pop_back(list);
*/