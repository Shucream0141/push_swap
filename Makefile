NAME = plib.a
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
SRCS = ft_swap.c \
	ft_stack.c \
	ft_utils.c \
	ft_util.c \
	ft_split.c \
	main.c \
	ft_sort_three.c \
	ft_sort_five.c \
	ft_sort_four.c \
	ft_sort_six.c \
	ft_algorithm.c \
	ft_check_err.c \
	ft_deal_args.c \
	ft_algorithm_seven.c

LIB = printf/libftprintf.a \
	libft/libft.a

EXE = push_swap

OBJ = $(SRCS:.c=.o)


all: $(NAME) $(EXE)

$(EXE): $(NAME) $(LIB)
	$(CC) $(CFLAGS) $(NAME) $(LIB) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	make -C printf
	make -C libft
$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	make -C printf clean
	make -C libft clean

fclean: clean
	$(RM) $(NAME) $(EXE)
	make -C printf fclean
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re