# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:09:28 by gsinged           #+#    #+#              #
#    Updated: 2020/01/08 02:46:13 by denser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra

INCLUDES = -I$(H_DIR) -I$(H_PRINTF_DIR)

C_DIR = ./src/
O_DIR = ./obj/
H_DIR = ./inc/

C_PRINTF_DIR = ./ft_printf/src/
H_PRINTF_DIR = ./ft_printf/inc/
O_PRINTF_DIR = ./ft_printf/obj/

ALL_H = get_next_line.h libft.h

ALL_C = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
        ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
        ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
        ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
        ft_putchar.c ft_putstr.c ft_putnbr.c ft_isalpha.c ft_isdigit.c \
        ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
        ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
        ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
        ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_putendl.c \
        ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
        ft_strsplit.c ft_itoa.c ft_strarrdel.c ft_lstnew.c ft_lstdelone.c \
        ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strchrint.c \
        ft_strndup.c ft_lstdelcontent.c ft_strclr2star.c get_next_line.c

ALL_O = $(patsubst %.c, %.o, $(ALL_C))

SRC = $(patsubst %, $(C_DIR)%, $(ALL_C))
OBJ = $(patsubst %, $(O_DIR)%, $(ALL_O))

PRINTF_C = ft_printf.c ft_frmt_spec.c ft_spec_parser.c ft_specifier.c \
		ft_tp1_process.c ft_tp5_process.c ft_tp1_assist.c ft_tp2_process.c \
		ft_fnum.c ft_part_integer.c ft_bigint.c ft_bigint_multi.c \
		ft_part_fraction.c ft_tp2_rounding.c \
		ft_tp2_print.c ft_tp3_4_process.c ft_general.c ft_tp2_assist.c \
		ft_tp2_frc_print.c ft_frc_add.c ft_bigint_multi_a.c ft_spec_parser_a.c

PRINTF_H = floatnumber.h libftprintf.h

PRINTF_O = $(patsubst %.c, %.o, $(PRINTF_C))

PRINTF_OBJ = $(patsubst %, $(O_PRINTF_DIR)%, $(PRINTF_O))

all: $(NAME)

o_dir:
	@mkdir -p $(O_DIR)

printf_dir:
	@mkdir -p $(O_PRINTF_DIR)

$(NAME): $(OBJ) $(PRINTF_OBJ)
	ar rc $(NAME) $(OBJ) $(PRINTF_OBJ)
	ranlib $(NAME)

$(O_DIR)%.o: $(C_DIR)%.c | o_dir
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<
#	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES);

$(O_PRINTF_DIR)%.o: $(C_PRINTF_DIR)%.c | printf_dir
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES);

clean:
	@rm -rf $(O_DIR) $(O_PRINTF_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

echo_n:
	@echo $(ALL_O)
