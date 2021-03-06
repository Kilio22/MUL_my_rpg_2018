##
## EPITECH PROJECT, 2018
## Fairefichier
## File description:
## This is a fairefichier, made by HeyShafty
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LIGHT_GREY	=	"\e[37m"
DARK_GREY	=	"\e[90m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

COLOR_THEME	=	$(BLUE_C)
DEBUG_THEME	=	$(CYAN_C)
TESTS_THEME	=	$(RED_C)

NAME	=	my_rpg
ROOT_PATH	=	./
SRC_NAME	=	src
TESTS_NAME	=	tests
INCL_NAME	=	include
SRC_PATH	=	$(ROOT_PATH)$(SRC_NAME)
INCL_PATH	=	$(ROOT_PATH)$(INCL_NAME)
TESTS_PATH	=	$(ROOT_PATH)$(TESTS_NAME)
MENU_PATH	=	menu/
SETTINGS_PATH	=	settings/
INTRO_PATH	=	intro/
FIGHT_PATH	=	fight/
DIALOGUE_PATH	=	dialogue/
END_GAME_PATH	=	end_game/
GAME_PATH	=	game/
CHAR_PATH	=	characters/
MAP_PATH	=	map/
INVENTORY_PATH	=	inventory/

SRC	=	$(CHAR_PATH)character_gestion.c	\
		$(CHAR_PATH)characters_animation.c	\
		$(CHAR_PATH)characters_interaction.c	\
		$(CHAR_PATH)follower.c	\
		$(CHAR_PATH)pnj_moves.c	\
		$(DIALOGUE_PATH)aubergiste.c	\
		$(DIALOGUE_PATH)create_dialogue.c	\
		$(DIALOGUE_PATH)destroy_dialogue.c	\
		$(DIALOGUE_PATH)dialogues_managment.c	\
		$(DIALOGUE_PATH)dialogue_text.c	\
		$(DIALOGUE_PATH)globals_dialogue.c	\
		$(END_GAME_PATH)check_end_game.c	\
		$(END_GAME_PATH)end_game_init.c	\
		$(END_GAME_PATH)end_game_text.c	\
		$(END_GAME_PATH)end_game_updates.c	\
		$(INTRO_PATH)intro.c	\
		$(INTRO_PATH)intro_animation.c	\
		$(INTRO_PATH)intro_event.c	\
		$(INTRO_PATH)intro_move.c	\
		$(INTRO_PATH)intro_text.c	\
		$(INTRO_PATH)intro_steps.c	\
		$(INTRO_PATH)intro_steps_2.c	\
		$(INTRO_PATH)intro_display.c 	\
		$(INTRO_PATH)intro_steps_3.c	\
		$(INTRO_PATH)intro_steps_4.c	\
		$(INTRO_PATH)intro_steps_5.c	\
		$(INTRO_PATH)intro_steps_6.c	\
		$(INTRO_PATH)dialogue.c	\
		$(FIGHT_PATH)attaques.c	\
		$(FIGHT_PATH)create_fight.c	\
		$(FIGHT_PATH)delete_fight.c	\
		$(FIGHT_PATH)fight.c	\
		$(FIGHT_PATH)fight_actions.c	\
		$(FIGHT_PATH)fight_text.c	\
		$(FIGHT_PATH)fight_events.c	\
		$(FIGHT_PATH)fight_updates.c	\
		$(FIGHT_PATH)fight_order.c	\
		$(FIGHT_PATH)manage_fight.c	\
		$(FIGHT_PATH)apply_attacks.c	\
		$(FIGHT_PATH)sort.c	\
		$(GAME_PATH)analyse_game_key.c	\
		$(GAME_PATH)check_obj_display.c	\
		$(GAME_PATH)display_utils.c	\
		$(GAME_PATH)framebuffer.c	\
		$(GAME_PATH)game_create.c	\
		$(GAME_PATH)game_display.c	\
		$(GAME_PATH)game_event.c	\
		$(GAME_PATH)game_init.c	\
		$(GAME_PATH)globals.c	\
		$(GAME_PATH)house_display.c	\
		$(GAME_PATH)pause.c	\
		$(MAP_PATH)fill_map.c	\
		$(MAP_PATH)layout_init.c	\
		$(MAP_PATH)map_init.c	\
		$(MAP_PATH)print_map.c	\
		$(MENU_PATH)analyse_menu_key.c	\
		$(MENU_PATH)analyse_menu_mouse.c	\
		$(MENU_PATH)check_save_status.c	\
		$(MENU_PATH)destroy_menu.c	\
		$(MENU_PATH)how_to_play.c	\
		$(MENU_PATH)init_load.c 	\
		$(MENU_PATH)load_game.c	\
		$(MENU_PATH)load_game_event.c	\
		$(MENU_PATH)menu_display.c	\
		$(MENU_PATH)menu_event.c 	\
		$(MENU_PATH)menu_fcts.c	\
		$(MENU_PATH)credits.c	\
		$(MENU_PATH)credits_event.c	\
		$(MENU_PATH)menu_init.c	\
		$(MENU_PATH)new_game.c	\
		$(MENU_PATH)new_game_event.c	\
		$(SETTINGS_PATH)controls_events.c	\
		$(SETTINGS_PATH)controls_init.c	\
		$(SETTINGS_PATH)settings_events.c	\
		$(SETTINGS_PATH)settings_init.c	\
		$(SETTINGS_PATH)settings_menu.c	\
		$(SETTINGS_PATH)settings_utils.c	\
		$(INVENTORY_PATH)inventory_core.c \
		$(INVENTORY_PATH)inventory.c \
		$(INVENTORY_PATH)inventory_draw.c \
		$(INVENTORY_PATH)inventory_data.c \
		$(INVENTORY_PATH)inventory_compute_stats.c \
		$(INVENTORY_PATH)inventory_event.c \
		$(INVENTORY_PATH)inventory_common.c \
		$(INVENTORY_PATH)inventory_compute.c \
		$(INVENTORY_PATH)inventory_files_save.c \
		$(INVENTORY_PATH)inventory_file_load.c \
		$(INVENTORY_PATH)inventory_stats.c \
		$(INVENTORY_PATH)inventory_update_stats.c \
		check_files.c	\
		camera_gestion.c	\
		create_house.c	\
		create_obj.c	\
		free.c 	\
		init_save.c	\
		list.c 	\
		music.c \
		my_utils.c	\
		put_pixel.c \
		time_gestion.c \
		item/item.c \
		screenshot.c \
		my_other_utils.c \
		save/save_core.c \
		save/open_core.c

SRC_LIB	=	inimy \
			g 	\
			graphmy \
			filemy \
			chainmy \
			stringmy \
			dispmy \
			my \
			graphic \
			csfml-graphics \
			csfml-window \
			csfml-system \
			csfml-audio	\
			m

LIB_PATHS	=	lib/lib_my \
				lib/lib_graphic \
				lib/graphmy_lib \
				lib/stringmy_lib \
				lib/chainmy_lib \
				lib/inimy_lib \
				lib/filemy_lib \
				lib/dispmy_lib

SRCS	=	$(SRC:%=$(SRC_PATH)/%) $(SRC_PATH)/main.c
OBJ	=	$(SRCS:.c=.o)
LIBRARIES	=	$(SRC_LIB:%=-l%)
LIB_PATHS_FLAG	=	$(LIB_PATHS:%=-L$(ROOT_PATH)%)

CFLAGS	=	-Wall -Wextra -Werror -I $(INCL_PATH)
LDFLAGS	=	$(LIB_PATHS_FLAG) $(LIBRARIES)
DEBUG_FLAGS	=	-g3 -gdwarf-4

MAKE_RULE	=	all
CLEAN_RULE	=	clean

all:	build_libs message $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" _     _____   ____  _____ ____ _____   ____  ____   ____ "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |   | ____| | __ )| ____/ ___|_   _| |  _ \|  _ \ / ___|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |   |  _|   |  _ \|  _| \___ \ | |   | |_) | |_) | |  _ "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |___| |___  | |_) | |___ ___) || |   |  _ <|  __/| |_| |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|_____|_____| |____/|_____|____/ |_|   |_| \_\_|    \____|"$(DEFAULT)
	@$(LINE_RETURN)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

build_libs: $(LIB_PATHS)
	@for MAKE_PATH in $(LIB_PATHS) ; do \
		make -C $$MAKE_PATH $(MAKE_RULE) -s ; \
	done

clean_libs: $(LIB_PATHS)
	@for MAKE_PATH in $(LIB_PATHS) ; do \
		make $(CLEAN_RULE) -C $$MAKE_PATH -s ; \
	done
	@make $(CLEAN_RULE) -C $(TESTS_PATH) -s SRC="$(SRC)" COLOR_THEME="$(RED_C)"

clean: clean_libs
	@$(RM) $(OBJ)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"$(NAME)'s object files"$(DEFAULT)
	@$(RM) vgcore.*
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Valgrind files"$(DEFAULT)

fclean: CLEAN_RULE=fclean
fclean:	clean
	@$(RM) $(NAME)
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary $(NAME)"$(DEFAULT)

re:		fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: COLOR_THEME = $(DEBUG_THEME)
debug: MAKE_RULE = debug
debug: re
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"⚠ DEBUG MODE ACTIVATED ⚠\n"$(DEFAULT)

tests_run: build_libs
	@make -C $(TESTS_PATH) -s \
		SRC="$(SRC)" \
		COLOR_THEME="$(TESTS_THEME)" \
		LIB_PATHS="$(LIB_PATHS)" \
		LIBRARIES="$(LIBRARIES)"
	@$(ECHO) $(TESTS_THEME)""
	@gcovr --exclude "tests/" --sort-uncovered --branches
	@$(ECHO) $(BOLD_T)""
	@gcovr --exclude "tests/" --sort-uncovered --print-summary
	@$(ECHO) $(DEFAULT)

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all $(NAME) build_libs message clean_libs clean fclean re debug tests_run
