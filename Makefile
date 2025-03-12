# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 12:42:38 by tiade-al          #+#    #+#              #
#    Updated: 2025/02/27 14:26:53 by joaoleote        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/main.c \
	src/get_next_line.c \
	src/get_next_line_utils.c \
	src/animation.c \
	src/background.c \
	src/checkers.c \
	src/helpers.c \
	src/img_resizer.c \
	src/initializer.c \
	src/map_setup.c \
	src/size.c

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