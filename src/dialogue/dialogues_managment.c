/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** dialogues_managment
*/

#include "rpg.h"

void dial_action(rpg_t *rpg, obj_t **obj, house_t **house, dialogue_t *dialogue)
{
    all_character_animation(obj);
    house_interaction(obj[HERO_HB], house, rpg);
    update_all_rect(obj, house);
    if (dialogue->quest_status_d != -1)
        update_dial_text(dialogue);
}

static int manage_enter(dialogue_t *dialogue, rpg_t *rpg)
{
    if (dialogue->high == 3)
        return 1;
    if (dialogue->high == 2 && dialogue->nb_pnj == 0)
        save(rpg);
    clock_text_intro(0);
    dialogue->quest_status_d = dialogue->high - 1;
    return 0;
}

static int manage_other_key_press(int code, dialogue_t *dialogue, rpg_t *rpg)
{
    if (dialogue->quest_status_d != -1)
        return 0;
    if (code == sfKeyLeft && dialogue->high > 1) {
        sfText_setColor(dialogue->text[dialogue->high], sfRed);
        dialogue->high--;
        sfText_setColor(dialogue->text[dialogue->high], sfBlue);
    }
    if (code == sfKeyRight && dialogue->high < 3) {
        sfText_setColor(dialogue->text[dialogue->high], sfRed);
        dialogue->high++;
        sfText_setColor(dialogue->text[dialogue->high], sfBlue);
    }
    if (code == sfKeyReturn)
        return manage_enter(dialogue, rpg);
    return 0;
}

int dial_event_management(rpg_t *rpg, dialogue_t *dialogue)
{
    if (WIND.event.type == sfEvtMouseMoved) {
        CONTROLS.mousePos.x = WIND.event.mouseMove.x;
        CONTROLS.mousePos.y = WIND.event.mouseMove.y;
    }
    if (WIND.event.type == sfEvtKeyPressed) {
        if (WIND.event.key.code == sfKeyF5)
            set_music(GAME.back_music);
        if (WIND.event.key.code == sfKeyEscape)
            pause_game(rpg);
        if (manage_other_key_press(WIND.event.key.code,
dialogue, rpg) == 1)
            return 1;
    }
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
    if (MENU.menu_on == 0)
        return 1;
    return 0;
}