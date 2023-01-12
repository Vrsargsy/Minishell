NAME = minishell
SRCS = $(wildcard srcs/*.c) \
	   $(wildcard srcs/builtins/*.c) \
	   $(wildcard srcs/parse/*.c) \
	   $(wildcard srcs/env/*.c) \
	   $(wildcard srcs/heredoc/*.c) \
	   $(wildcard utils/*.c)
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror 

LDFLAGS = -L./readline-arbaboom/lib
CPPFLAGS = -I./readline-arbaboom/include
RD= $(shell find $(HOME) -name readline-arbaboom 2>/dev/null)
Include = -lreadline ${LDFLAGS} ${CPPFLAGS}

RM = rm -rf



all: ${NAME}
${NAME}:${OBJS}
	@${MAKE} -C ./libft/
	@${CC} ${CFLAGS} ${OBJS} ${Include} ./libft/libft.a -o ${NAME} 	

install:
	cd readline-master && ./configure --prefix=$(RD) && make && make install

clean:
	@${MAKE} clean -C ./libft/
	@${RM} ${OBJS}

fclean:
	@make fclean -C ./libft/
	@${RM} ${OBJS}
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
