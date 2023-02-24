# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorcery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 17:25:40 by clorcery          #+#    #+#              #
#    Updated: 2022/07/04 18:25:53 by clorcery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
YELLOW:="\033[1;33m"
BLUE:="\033[1;34m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# /* ~~~~~~~~~~~~~~ */

SRCS = 	./Mandatory/main.c \
	   	./Mandatory/check_args/ft_error.c \
		./Mandatory/check_args/check_args.c \
		./Mandatory/check_args/recup_map.c \
		./Mandatory/check_args/check_argc.c \
		./Mandatory/check_args/check_args_2.c \
		./Mandatory/window/open_window.c \
		./Mandatory/window/close_window.c \
		./Mandatory/window/key_hook.c \
		./Mandatory/display/init_img.c \
		./Mandatory/display/put_sprites.c \
		./Mandatory/display/put_sprites2.c \
		./Mandatory/player/player.c \
		./Mandatory/player/check_for_player.c

SRCS_BONUS = ./Bonus/main_bonus.c \
	   		./Bonus/check_args/ft_error_bonus.c \
			./Bonus/check_args/check_args_bonus.c \
			./Bonus/check_args/recup_map_bonus.c \
			./Bonus/check_args/check_argc_bonus.c \
			./Bonus/check_args/check_args_2_bonus.c \
			./Bonus/window/open_window_bonus.c \
			./Bonus/window/close_window_bonus.c \
			./Bonus/window/key_hook_bonus.c \
			./Bonus/display/init_img_bonus.c \
			./Bonus/display/put_sprites_bonus.c \
			./Bonus/display/put_sprites2_bonus.c \
			./Bonus/player/player_bonus.c \
			./Bonus/player/move_player_bonus.c \
			./Bonus/player/check_for_player_bonus.c \
			./Bonus/bubbles/move_bubbles_bonus.c \
			./Bonus/bubbles/init_bubbles_bonus.c \
			./Bonus/bubbles/check_collision_bonus.c


OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

NAME = so_long

NAME_BONUS = so_long_bonus

LIBFT = ./libft/libft.a

MLX = ./minilibx/libmlx.a

RM = rm -rf

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

FLAGSMLX = -L. -lXext -lX11 -lm

all:	${NAME}

${LIBFT}:
		@make -C ./libft --no-print-directory

${MLX}:
		@make -C ./minilibx --no-print-directory -s

.c.o:
		@${CC} ${FLAGS} -c $< -o $@

${NAME}:	${OBJS} ${LIBFT} ${MLX}
		@${CC} ${FLAGS} ${OBJS} ${LIBFT} ${MLX} ${FLAGSMLX} -o ${NAME} 
		@echo ${GREEN}"compilation complete"${EOC}
clean:
		@make -C ./libft/ clean --no-print-directory
		@make -C ./minilibx/ clean --no-print-directory -s
		@${RM} ${OBJS}
		@${RM} ${OBJS_BONUS}
		@echo ${YELLOW}"clean ok"
		
fclean: clean
		@${RM} ${LIBFT} 
		@${RM} ${NAME}
		@${RM} ${NAME_BONUS}
		@echo "fclean ok"${EOC}

re: fclean all

$(NAME_BONUS):  ${OBJS_BONUS} ${LIBFT} ${MLX} 
				@${CC} ${FLAGS} ${OBJS_BONUS} ${LIBFT} ${MLX} ${FLAGSMLX} -o ${NAME_BONUS} 
				@echo ${GREEN}"compilation bonus complete"${EOC}

bonus:	$(NAME_BONUS)	

.PHONY: all clean fclean re bonus
