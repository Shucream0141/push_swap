NAME = plib.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = plib/ft_atoi.c \
	plib/ft_lstnew.c \
	plib/ft_lstadd_front.c \
	plib/ft_lstsize.c \
	plib/ft_lstlast.c \
	plib/ft_lstadd_back.c \
	plib/ft_lstdelone.c \
	plib/ft_lstclear.c \
	plib/ft_lstiter.c \
	plib/ft_lstmap.c \

OBJ = $(SRCS:.c=.o)

all: $(NAME)

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