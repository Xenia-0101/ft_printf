
# SOURCES		:=		$(shell find . -name '*.c')
SOURCES		= \
ft_printf.c \

OBJECTS		=		$(SOURCES:.c=.o)
HEADER		=		includes
LIBFT		=		libft
FLAGS		=		-Wall -Wextra -Werror
NAME		=		libftprintf.a
RM			=		rm -f
CC			=		gcc
AR			=		ar rc

all:	${NAME}

${NAME}: ${OBJECTS}
	make -C $(LIBFT)
	cp libft/libft.a ./
	mv libft.a $(NAME)
	${AR} ${NAME} ${OBJECTS}
	echo ${OBJECTS}

.c.o:
	${CC} ${FLAGS} -c $< -o $@

clean:
	make clean -C $(LIBFT)
	${RM} ${OBJECTS}

fclean: clean
	make fclean -C $(LIBFT)
	${RM} ${NAME}

re: fclean all clean
	make clean -C $(LIBFT)

.PHONY: all clean fclean re
