NAME = philo_bonus
GCC = cc
FLAGS = -Wall -Werror -Wextra
HEADER_DIR = include
HEADER = include/philo_bonus.h
SRC = philo_bonus.c\
	utils_bonus.c\
	utils2_bonus.c\
	init_args_bonus.c\
	ft_init_bonus.c\
	ft_time_bonus.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -I$(HEADER_DIR) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -I$(HEADER_DIR) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJBS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus