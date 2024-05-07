SRCS_DIR	:=		./srcs/
SOURCES		:=		$(shell find $(SRCS_DIR) -name '*.c')
OBJECTS		=		$(SOURCES:.c=.o)
HEADER		=		includes
LIBFT		=		libft
# FLAGS		=		-Wall -Wextra -Werror
NAME		=		libftprintf.a
RM			=		rm -f
CC			=		gcc
AR			=		ar rc

all:	${NAME} 

${NAME}: ${OBJECTS}
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ranlib $(NAME)

${NAME}: main.o
	${CC} ${FLAGS} main.o -o ${NAME} -L. -lftprintf -I${HEADER}

main.o: main.c
	${CC} ${FLAGS} -c main.c -o main.o -I${HEADER}

clean:
	${RM} ${OBJECTS}
	${RM} main.o
	@make clean -C $(LIBFT)

fclean: clean
	${RM} ${NAME}
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
