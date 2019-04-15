/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** globals
*/

#ifndef GLOBALS_H_
#define GLOBALS_H_

extern const char *save_path[3];
extern const char *house_path[4];
extern const sfIntRect house_rects[4];
extern const sfIntRect door_rects[4];
extern const sfVector2f door_pos[4];
extern const char *menu_path[2];
extern const char *menu_str[6];
extern const sfVector2f menu_pos[6];
extern void (* const menu[6])(rpg_t *, obj_t **, house_t **);

#endif /* !GLOBALS_H_ */
