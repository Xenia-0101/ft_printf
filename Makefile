
SOURCES		:=		$(shell find . -maxdepth 1 -name '*.c' )
# SOURCES		= \
# ft_printf.c \

OBJECTS		=		$(SOURCES:.c=.o)
HEADER		=		includes
LIBFT		=		libft
FLAGS		=		-Wall -Wextra -Werror -g
NAME		=		libftprintf.a
RM			=		rm -f
CC			=		gcc
AR			=		ar rc

all:	${NAME}

bonus: all

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

lib:
	make -C $(LIBFT)
	cp libft/libft.a ./
	mv libft.a $(NAME)

.PHONY: all clean fclean re
