NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

H_DIR = includes
LIBH_DIR = libft/includes

C_DIR = srcs
O_DIR = objs

ALL_C = ft_printf.c ft_frmt_spec.c ft_spec_parser.c ft_specifier.c \
		ft_tp1_process.c ft_tp5_process.c ft_tp1_assist.c ft_tp2_process.c \
		ft_fnum.c ft_part_integer.c ft_bigint.c ft_bigint_multi.c \
		ft_part_fraction.c ft_tp2_rounding.c \
		ft_tp2_print.c ft_tp3_4_process.c ft_general.c ft_tp2_assist.c \
		ft_tp2_frc_print.c ft_frc_add.c ft_bigint_multi_a.c ft_spec_parser_a.c

ALL_O = $(patsubst %.c, %.o, $(ALL_C))

SRCS = $(patsubst %, $(C_DIR)/%, $(ALL_C))
OBJS = $(patsubst %, $(O_DIR)/%, $(ALL_O))

LIBFT_DIR = libft
LIBFT_O = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o ft_putchar.o ft_putstr.o ft_putnbr.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_putendl.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_strsplit.o ft_itoa.o ft_strarrdel.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_strchrint.o ft_strndup.o ft_lstdelcontent.o ft_strclr2star.o
LIBFT_O_DIR = $(patsubst %, $(LIBFT_DIR)/objs/%, $(LIBFT_O))

all: $(NAME)

libft.a:
	@make -C $(LIBFT_DIR)

$(NAME): libft.a o_dir $(OBJS)
	@ar rc $(NAME) $(LIBFT_O_DIR) $(OBJS);
	@ranlib $(NAME);

o_dir:
	@if ! [ -d $(O_DIR) ]; then mkdir $(O_DIR); fi;

$(O_DIR)/%.o: $(C_DIR)/%.c
	@make o_dir
	@gcc $(FLAGS) -c $< -o $@ -I./$(H_DIR) -I$(LIBH_DIR);

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(O_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all