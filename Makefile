CC=gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f 
SRCS = main.c extra.c
LIBS = -L ./libft -l ft
OBJS = $(SRCS:.c=.o)
NAME = pipex
LIBFT = libft/libft.a


all: ${NAME}

$(LIBFT):
	$(MAKE) -C ./libft
	$(MAKE) -C ./libft bonus

$(NAME): $(LIBFT) $(OBJS) 
	${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME} 
.PHONY: clean fclean all re
clean:
	-${RM} ${OBJS}
	$(MAKE) -C ./libft clean
fclean: clean
	${RM} ${NAME}
	$(MAKE) -C ./libft fclean

re: fclean all
