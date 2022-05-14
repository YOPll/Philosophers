NAME = philo
GCC = cc
FLAGS = -Wall -Werror -Wextra
HEADER_DIR = include
HEADER = include/philo.h
SRC = philo.c\
	utils.c\
	init_args.c\
	ft_init.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -I$(HEADER_DIR) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -I$(HEADER_DIR) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJBS)

fclean: clean
	rm -rf $(NAME) $(NAME_CHECKER)

re: fclean all

.PHONY : all clean fclean re bonus