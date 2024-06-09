NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SRC = src/ft_check_dup.c\
	  src/ft_check_sorted.c\
	  src/ft_check_args.c\
	  src/ft_error.c\
	  src/ft_free.c\
	  src/ft_rotate_a.c\
	  src/ft_rotate_b.c\
	  src/ft_sort_3.c\
	  src/ft_sort.c\
	  src/ft_split.c\
	  src/ft_utilis.c\
	  src/init_node_a.c\
	  src/init_node_b.c\
	  src/prep_for_push.c\
	  src/lst_utilis.c\
	  src/push_swap.c\
	  src/rules1.c\
	  src/rules2.c\

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