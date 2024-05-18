NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = src/ft_check_dup.c\
	  src/ft_check_sorted.c\
	  src/ft_error.c\
	  src/ft_free.c\
	  src/ft_sort_3.c\
	  src/ft_split.c\
	  src/ft_utilis.c\
	  src/lst_utilis.c\
	  src/push_swap.c\
	  src/rules.c\

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME):$(OBJ)
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}
	
clean :
		rm -rf ${OBJ}
	
fclean: clean
		rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re