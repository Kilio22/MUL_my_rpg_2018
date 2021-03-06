/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** text_intro
*/

#include "rpg.h"

int fight_text_intro(int i)
{
    static sfClock *clock = NULL;
    sfTime time;
    float seconds;

    if (!clock)
        clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 3 && i == 1) {
        sfClock_restart(clock);
        return 1;
    }
    if (seconds >= 0.1 && i == 0) {
        sfClock_restart(clock);
        return 1;
    }
    return 0;
}

void update_choices(fight_t *fight, int turn, rpg_t *rpg)
{
    if (turn == 0) {
        for (int i = 0; i < 5; i++) {
            sfText_setString(fight->attacks[i], attaques_names[0][i]);
            update_attacks_pos(fight, rpg, i);
        }
    } else {
        for (int i = 0; i < 5; i++) {
            sfText_setString(fight->attacks[i], attaques_names[turn - 1][i]);
            update_attacks_pos(fight, rpg, i);
        }
    }
}

int fight_text_index(const char *str, char **to_print, int flag, int *p_ind)
{
    if (my_strlen(*to_print) == 0) {
        *to_print = malloc(sizeof(char) * (my_strlen(str) + 1));
        if (*to_print == NULL)
            return -1;
    }
    if (flag == 1) {
        free(*to_print);
        *to_print = NULL;
        *p_ind = 0;
        return -1;
    }
    return 0;
}

int update_fight_text(fight_t *fight, int flag, rpg_t *rpg)
{
    static int print_index = 0;
    static char *print = NULL;

    if (fight_text_index(ENTXT1, &print, flag, &print_index) == -1)
        return -1;
    for (size_t i = 0; (i < update_time(NULL) || i <= 1) &&
print_index < my_strlen(ENTXT1); i++) {
        print[print_index] =
ennemi_text[fight->text_index][GAME.language][print_index];
        print_index++;
        print[print_index] = '\0';
    }
    sfText_setString(fight->text, print);
    if (fight_text_intro(1) == 1 && my_strlen(print) == my_strlen(ENTXT1)) {
        fight->old_i++;
        fight->quest_status++;
    }
    if (my_strlen(print) != my_strlen(ENTXT1))
        fight_text_intro(0);
    return 0;
}