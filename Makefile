NAME = push_swap

FLAGS = -Wall -Wextra -Werror

SRCS = \
main.c \
lists.c \
lds.c \
instructions.c \
parsing.c \
move.c

OBJ = $(SRCS:.c=.o)


all: ${NAME}

${NAME}: ${OBJ}
	make -C ./libft
	gcc ${FLAGS} ${OBJ} libft/libft.a -o ${NAME}

clean:
	@make clean -C ./libft
	@rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}

re: fclean all