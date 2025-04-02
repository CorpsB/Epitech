##
## EPITECH PROJECT, 2023
## MAKEFILE MAIN
## File description:
## A program that do simple operation.
##

SRC	=	src/main.c	\
		src/event.c	\
		src/window.c	\
		src/gui.c	\
		src/animation/player.c	\
		src/events/collision.c	\
		src/events/button_state.c	\
		src/objects/data_lists.c	\
		src/objects/pannels.c	\
		src/objects/scenes.c	\
		src/objects/abstract/sprite.c	\
		src/objects/abstract/button.c	\
		src/objects/abstract/text.c	\
		src/objects/abstract/battler.c	\
		src/objects/abstract/event.c	\
		src/objects/abstract/classes.c	\
		src/objects/abstract/pannels/event_pannel.c	\
		src/objects/abstract/pannels/map_pannel.c	\
		src/scenes/controls/pannels/button_pannel.c	\
		src/scenes/controls/buttons/btn_action1.c	\
		src/scenes/controls/buttons/btn_action2.c	\
		src/scenes/controls/buttons/btn_backward.c	\
		src/scenes/controls/buttons/btn_forward.c	\
		src/scenes/controls/buttons/btn_interaction.c	\
		src/scenes/controls/buttons/btn_left.c	\
		src/scenes/controls/buttons/btn_right.c	\
		src/scenes/controls/controls.c	\
		src/scenes/inventory/inventory.c	\
		src/scenes/inventory/pannels/button_pannel.c	\
		src/scenes/game_scene/pannels/map_pannel.c	\
		src/scenes/game_scene/pannels/button_pannel.c	\
		src/scenes/game_scene/pannels/entity_pannel.c	\
		src/scenes/game_scene/pannels/event_pannel.c	\
		src/scenes/game_scene/game_scene.c	\
		src/scenes/game_scene/buttons/btn_menu.c	\
		src/scenes/game_scene/buttons/btn_inventory.c	\
		src/scenes/game_scene/buttons/btn_game.c	\
		src/scenes/game_scene/buttons/btn_save.c	\
		src/scenes/game_scene/events/story_tell.c	\
		src/scenes/game_scene/events/history_1.c	\
		src/scenes/game_scene/events/history_2.c	\
		src/scenes/game_scene/events/history_3.c	\
		src/scenes/game_scene/events/teleporter.c	\
		src/scenes/game_scene/events/player_move.c	\
		src/scenes/game_scene/events/player_tp_up.c	\
		src/scenes/game_scene/events/player_tp_down.c	\
		src/scenes/game_scene/events/player_npc_1.c	\
		src/scenes/game_scene/events/player_npc_2.c	\
		src/scenes/game_scene/events/player_npc_3.c	\
		src/scenes/game_scene/events/player_npc_4.c	\
		src/scenes/game_scene/events/player_npc_5.c	\
		src/scenes/main_menu/pannels/button_pannel.c	\
		src/scenes/main_menu/main_menu.c	\
		src/scenes/settings/pannels/button_pannel.c	\
		src/scenes/main_menu/buttons/btn_play.c    \
		src/scenes/main_menu/buttons/btn_exit.c    \
		src/scenes/main_menu/buttons/btn_settings.c	\
		src/scenes/main_menu/buttons/btn_load.c	\
		src/scenes/settings/buttons/btn_more.c	\
		src/scenes/settings/buttons/btn_less.c	\
		src/scenes/settings/buttons/btn_controls.c	\
		src/scenes/settings/buttons/btn_fullscreen.c	\
		src/scenes/settings/buttons/btn_resolution1.c	\
		src/scenes/settings/buttons/btn_resolution2.c	\
		src/scenes/settings/settings.c	\
		src/scenes/fight/buttons/moves.c	\
		src/scenes/fight/pannels/button_pannel.c	\
		src/scenes/fight/fight.c	\
		src/inventory.c	\
        lib/my/others/a_sort_int.c	\
		lib/my/others/n_convert_s.c	\
		lib/my/others/n_prime.c	\
		lib/my/others/n_isprime.c	\
		lib/my/others/n_power.c	\
		lib/my/others/n_revbase.c	\
		lib/my/others/n_size.c	\
		lib/my/others/my_stracmp.c	\
		lib/my/others/my_strcmp.c	\
		lib/my/others/s_copy.c	\
		lib/my/others/s_lower.c	\
		lib/my/others/s_upper.c	\
		lib/my/others/my_strncmp.c	\
    	lib/my/others/my_strscmp.c	\
		lib/my/others/s_ncopy.c	\
		lib/my/others/my_strstr.c	\
		lib/my/others/s_reverse.c	\
		lib/my/others/s_search.c	\
		lib/my/others/my_strlen.c	\
		lib/my/others/s_count.c	\
		lib/my/others/a_size.c	\
		lib/my/stdlib/l_add.c	\
		lib/my/stdlib/l_convert_a.c	\
		lib/my/stdlib/l_display.c	\
		lib/my/stdlib/l_free.c	\
		lib/my/stdlib/l_merge.c	\
		lib/my/stdlib/l_size.c	\
		lib/my/stdlib/l_remove.c	\
		lib/my/stdlib/l_reverse.c	\
		lib/my/stdlib/l_sort.c	\
		lib/my/stdlib/n_base.c	\
		lib/my/stdlib/s_convert_f.c	\
		lib/my/stdlib/s_convert_n.c	\
		lib/my/stdlib/my_strdup.c	\
		lib/my/stdlib/my_substr.c	\
		lib/my/stdlib/my_strcat.c	\
		lib/my/stdlib/s_remove.c	\
		lib/my/stdlib/a_free.c	\
		lib/my/stdlib/a_convert_s.c	\
		lib/my/stdlib/a_dup.c	\
		lib/my/stdlib/my_getline.c	\
		lib/my/stdlib/my_strtok.c	\
		lib/my/unistd/a_display_n.c	\
		lib/my/unistd/a_display_s.c	\
		lib/my/unistd/my_putchar.c	\
		lib/my/unistd/my_putstr.c	\
		lib/my/unistd/my_putnbr.c	\
		lib/my/stdarg/my_printf.c	\
		lib/my/fcntl/my_readfile.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME)	\
	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
