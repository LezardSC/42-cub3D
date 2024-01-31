# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 18:09:10 by lezard            #+#    #+#              #
#    Updated: 2024/01/31 13:56:28 by jrenault         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY:     			all clear mkbuild lib mlx clean fclean re

NAME					= cub3d

BUILD_DIR				= build/
	
HEADER_DIR				= header/
HEADER_FILE				= cub3d.h
HEADERS_WITH_PATH		= $(addprefix $(HEADER_DIR),$(HEADER_FILE))

DIR						= src/
SRC			 			= 	main.c \
							init_param.c \
							free_param.c \
							cub3d_utils.c \
							parsing/map_parsing.c \
							parsing/map_parsing_bis.c \
							parsing/infos_parsing.c \
							parsing/fill_infos.c \
							parsing/check_error.c \
							exec/close_win.c \
							exec/deal_key.c \
							exec/minimap.c \
							exec/move_player.c \
							exec/draw_pixels.c \

OBJECTS			    	= ${addprefix ${BUILD_DIR},${SRC:.c=.o}}

LIBFT					= libft.a
LIB_DIR					= libft/

GCC						= cc
CFLAGS					= -Wall -Wextra -Werror -g3 -pthread

RM 						= rm -rf
CLEAR					= clear

MINILIB					= libmlx.a

MINILIB_DIR				= mlx/
LINUX					= -Lmlx -lmlx -Imlx -lXext -lX11 -lm

$(BUILD_DIR)%.o:		$(DIR)%.c ${HEADERS_WITH_PATH} Makefile
						mkdir -p $(@D)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(MINILIB_DIR) -c $< -o $@

all: 					mkbuild lib minilibx $(HEADER_DIR)
						$(MAKE) $(NAME)

mkbuild:
						mkdir -p build

clear:
						$(CLEAR)

$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) -L$(MINILIB_DIR) $(LINUX) -lmlx		

lib:
						make -C $(LIB_DIR)

minilibx:
						make -C $(MINILIB_DIR)

clean:					
						${RM} $(OBJECTS)
						make clean -C $(LIB_DIR)
						make clean -C $(MINILIB_DIR)
						${RM} $(BUILD_DIR)

fclean:					clean
						${RM} ${NAME}
						make clean -C $(LIB_DIR)
						make clean -C $(MINILIB_DIR)


re:						fclean
						$(MAKE) all