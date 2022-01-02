NAME = push_swap

SRCS = main.c \
		list/list_operations.c \
		list/list_utils.c \
		list/list_utils2.c \
		utils.c \
		ft_split.c \
		args.c \
		free_tab.c \
		push_swap_operations.c \
		rotate_operations.c \
		reverse_rotate_operations.c \
		algo_utils.c \
		algo_utils2.c \
		algo.c

OBJS = $(addprefix src/,$(SRCS:.c=.o))

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[32m[ ./push_swap created ]\033[37m"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re