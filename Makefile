# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guillaume <guillaume@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 18:16:39 by gmajstru          #+#    #+#              #
#    Updated: 2018/09/26 15:15:22 by guillaume        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# for debugging
DEBUG = no

#colors
NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m

OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
SUCCESS_STRING=$(OK_COLOR)[FDF SUCCESSFULLY BUILDED]$(NO_COLOR)
ERROR_STRING=$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING=$(WARN_COLOR)[WARNINGS]$(NO_COLOR)

# src
SRC  = main.c \
		colors.c \
		init.c \
		keyboard_manager.c \
		line_tools.c \
		map.c \
		moves.c \
		transform.c \
		zooms.c \
		checks.c

 # directories
 SRCDIR = ./src/
 INCDIR = ./includes/
 OBJDIR = ./obj/

# obj files
OBJ  = $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC  = gcc

ifeq ($(DEBUG),yes)
	CFLAGS = -Wall -Wextra -Werror -Wunused -g
else
	CFLAGS = -Wall -Wextra -Werror -Wunused
endif

# mlx library
MLX  = ./mlx
 MLX_LIB = $(addprefix $(MLX),mlx.a)
 MLX_INC = -I ./mlx
 MLX_LNK = -L ./mlx -l mlx -framework OpenGL -framework AppKit

# ft library
 FT  = ./libft/
 FT_LIB = $(addprefix $(FT),libft.a)
 FT_INC = -I ./libft
 FT_LNK = -L ./libft -l ft

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	@echo "$(OK_STRING)"

$(FT_LIB):
	$(MAKE) -C $(FT)

$(MLX_LIB):
	$(MAKE) -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
	@echo "$(SUCCESS_STRING)"

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(FT) clean
	$(MAKE) -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(FT) fclean

re: fclean all
