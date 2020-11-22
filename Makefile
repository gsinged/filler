# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 19:16:10 by gsinged           #+#    #+#              #
#    Updated: 2020/11/18 19:16:14 by gsinged          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gsinged.filler

INCLUDES = -I$(INCDIR) -I$(FTDIR)/inc/ -I$(FTDIR)/ft_printf/inc/

CC = gcc
FLAGS = -Wall -Werror -Wextra


SRCDIR  = ./src/
INCDIR  = ./inc/
OBJDIR  = ./obj/
FTDIR   = ./libft/

FTNAME = libft.a

INC = filler.h

SRC =	filler.c  get_map.c init_fl.c init_map.c init_map_a.c manhattan.c \
		select_coordinates.c

OBJ	= $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT = $(FTDIR)$(FTNAME)

all: $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCDIR)$(INC) | obj
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(FTDIR)

clean:
	rm -rf $(OBJDIR)
	make -sC $(FTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -sC $(FTDIR) fclean

re: fclean all