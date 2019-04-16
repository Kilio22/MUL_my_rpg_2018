/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** globals
*/

#include "rpg.h"

const char *key_str[] = {
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "ESC",
    "LCTRL",
    "LSHIFT",
    "LALT",
    "LSYSTEM",
    "RCTRL",
    "RSHIFT",
    "RALT",
    "RSYSTEM",
    "MENU",
    "[",
    "]",
    ";",
    ", ",
    ".",
    "'",
    "/",
    "\\",
    "~",
    " = ",
    "-",
    "SPACE",
    "ENTER",
    "BACKSPACE",
    "TAB",
    "PAGE_UP",
    "PAGE_DOWN",
    "END",
    "HOME",
    "INSERT",
    "DELETE",
    "+",
    "-",
    "*",
    "/",
    "L_ARROW",
    "R_ARROW",
    "UP_ARROW",
    "DOWN_ARROW",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "F1",
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "F11",
    "F12",
    "F13",
    "F14",
    "F15",
    "PAUSE"
};

const char *menu_path[2] = {
    "assets/background_menu.png",
    "assets/load.png"
};

const char *menu_str[6] = {
    " New Game ",
    " Load Game ",
    "   Settings ",
    "How To Play ",
    "   Credits ",
    "     Quit "
};

const char *menu_desc[6] = {
    "Start a new adventure !",
    "Load one of the saved adventure and continue it !",
    "Change your experience by selecting an other language, \nmodify the volume"
    " of the music, or by define \nyour propers controls !",
    "Learn how to play to this game !",
    "View the credits",
    "Go back to the deskdop"
};

const sfVector2f menu_pos[6] = {
    {110, 60},
    {100, 160},
    {100, 260},
    {100, 360},
    {115, 460},
    {90, 560}
};

const char *settings_fp[5] = {
    "assets/settings.png",
    "assets/up_vol.png",
    "assets/down_vol.png",
    "assets/fr.png",
    "assets/eng.png"
};

const sfVector2f settings_spr_pos[5] = {
    {0, 0},
    {500, 70},
    {780, 70},
    {520, 200},
    {720, 200}
};

const char *settings_str[4] = {
    "VOLUME",
    "NULL",
    "LANGUAGE",
    "CONTROLS"
};

const sfVector2f settings_pos[4] = {
    {110, 60},
    {640, 60},
    {65, 200},
    {400, 360},
};

const char *save_path[3] = {
    "saves/save1.txt",
    "saves/save2.txt",
    "saves/save3.txt"
};

const char *house_path[5] = {
    "assets/maison1.png",
    "assets/maison2.png",
    "assets/auberge.png",
    "assets/forge.png",
    "assets/church.png"
};

const sfIntRect house_rects[5] = {
    {0, 0, 160, 320},
    {0, 0, 224, 256},
    {0, 0, 320, 448},
    {0, 0, 192, 352},
    {0, 0, 384, 352}
};

const sfVector2f door_pos[5] = {
    {0, 256},
    {0, 192},
    {160, 352},
    {95, 160},
    {0, 270}
};

const sfIntRect door_rects[5] = {
    {0, 64, 96, 64},
    {0, 0, 96, 64},
    {0, 352, 96, 96},
    {0, 224, 96, 64},
    {0, 64, 96, 64}
};

void (* const menu[6])(rpg_t *, obj_t **, house_t **) = {
    menu_new_game,
    menu_load_game,
    menu_settings,
    menu_how_to_play,
    menu_credit,
    menu_close_window
};
