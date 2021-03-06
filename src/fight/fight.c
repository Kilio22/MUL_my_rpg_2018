/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight
*/

#include "rpg.h"

void fight_camera_control(rpg_t *rpg, sfVector2f pos, obj_t **obj)
{
    if (CONTROLS.bools[KEYY] == 0)
        sfView_setCenter(WIND.view, pos);
    else {
        if (CONTROLS.bools[KEYRIGHT] == 1)
            sfView_move(WIND.view, (sfVector2f){10, 0});
        if (CONTROLS.bools[KEYLEFT] == 1)
            sfView_move(WIND.view, (sfVector2f){-10, 0});
        if (CONTROLS.bools[KEYDOWN] == 1)
            sfView_move(WIND.view, (sfVector2f){0, 10});
        if (CONTROLS.bools[KEYUP] == 1)
            sfView_move(WIND.view, (sfVector2f){0, -10});
    }
    if (CONTROLS.bools[KEYSPACE] == 1)
        sfSprite_setPosition(obj[HERO_HB]->sprite,
sfView_getCenter(WIND.view));
}

static void text_display_fight(rpg_t *rpg, fight_t *fight)
{
    if (fight->old_i == fight->nb_fight || fight->quest_status == 9) {
        sfRenderWindow_drawSprite(WIND.wind, fight->parch, NULL);
        sfRenderWindow_drawText(WIND.wind, fight->text, NULL);
    }
    if (fight->quest_status > 2 && fight->life[0] > 0 && fight->life[1] > 0) {
        for (int i = 3; i < 5; i++)
            sfRenderWindow_drawText(WIND.wind, fight->attacks[i], NULL);
    }
    if (fight->quest_status > 2 && fight->fight_status == 0 && fight->turn < 6
&& fight->life[0] > 0 && fight->life[1] > 0) {
        sfRenderWindow_drawSprite(WIND.wind, fight->parch, NULL);
        sfRenderWindow_drawText(WIND.wind, fight->turn_n, NULL);
        for (int i = 0; i < 3; i++)
            sfRenderWindow_drawText(WIND.wind, fight->attacks[i], NULL);
    }
}

static void fight_display(rpg_t *rpg, obj_t **obj,
house_t **house, fight_t *fight)
{
    sfRenderWindow_clear(WIND.wind, sfBlack);
    if (MENU.menu_on == 2)
        return;
    sfRenderWindow_setView(WIND.wind, WIND.view);
    print_map(MAP.sprite, obj, rpg->wind);
    house_display(rpg, house);
    check_obj_display(obj, rpg);
    print_map2(MAP.sprite, obj, rpg->wind);
    display_framebuffer(rpg);
    check_pnj_display(house, obj, rpg);
    text_display_fight(rpg, fight);
    sfRenderWindow_drawRectangleShape(WIND.wind, fight->fondu, NULL);
    sfRenderWindow_display(WIND.wind);
}

static void fight_music(rpg_t *rpg)
{
    sfSoundStatus status = sfMusic_getStatus(GAME.back_music);

    if (status == sfPlaying) {
        set_music(GAME.back_music);
        sfMusic_play(rpg->music.fight_music);
    }
}

void fight(obj_t **obj, rpg_t *rpg, int i, house_t **house)
{
    fight_t fight = create_fight(i, rpg, obj);
    int ret_val = 0;
    size_t frames;

    sfClock_restart(obj[1]->clock);
    fight_music(rpg);
    fight_text_intro(0);
    choose_fighter(obj, &fight, rpg, 2);
    while (sfRenderWindow_isOpen(WIND.wind)) {
        rpg->frame = update_time(&frames);
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            ret_val += fight_event_management(rpg, &fight);
        if (ret_val > 0 || fight.quest_status == 10) {
            delete_fight(&fight, obj, rpg);
            return;
        }
        fight_action(rpg, obj, house, &fight);
        fight_display(rpg, obj, house, &fight);
    }
}