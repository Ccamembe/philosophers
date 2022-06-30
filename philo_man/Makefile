NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = philo.h

SRC = philo.c \
		utils.c\
		init_data.c\
		init_philos.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) $(INC) clean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)

re: fclean all
