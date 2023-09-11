NAME = plib.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_swap.c \
	ft_stack.c \
	ft_utils.c \
	main.c \
	ft_sort_three.c \
	ft_sort_five.c

EXE = exe

OBJ = $(SRCS:.c=.o)

all: $(NAME) $(EXE)

$(EXE): $(NAME)
	$(CC) $(CFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re