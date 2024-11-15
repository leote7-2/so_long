# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 17:03:21 by jhenriq2          #+#    #+#              #
#    Updated: 2024/11/14 17:05:39 by jhenriq2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = change_sprite.c \
		check_exit.c \
		ft_error.c \
		ft_free.c \
		get_next_line.c \
		get_next_line_utils.c \
		key_press.c \
		print_map.c \
		read_map.c \
		so_long.c \

CC = @cc

CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L. -lXext -L. -lX11

LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a

MINILIBX_PATH = ./minilibx-linux
MINILIBX = $(MINILIBX_PATH)/libmlx.a

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	@echo " [ .. ] | Compiling libft.."
	@make -s -C $(LIBFT_PATH)
	@echo " [ OK ] | Libft ready!"

$(MINILIBX):
	@echo " [ .. ] | Compiling minilibx.."
	@make -s -C $(MINILIBX_PATH)
	@echo " [ OK ] | Minilibx ready!"

clean:
	@rm -f $(OBJS)
	@echo "object files removed."
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "all files created were removed."

re: fclean all

.PHONY:	all clean fclean re