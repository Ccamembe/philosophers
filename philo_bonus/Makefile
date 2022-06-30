BONUS = philo_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCB = philo_bonus.h

SRCB = philo_bonus.c \
		utils_bonus.c\
		init_data_bonus.c\
		init_philos_bonus.c\



OBJB = $(SRCB:.c=.o)



bonus: $(BONUS)

$(BONUS):$(OBJB) $(INCB) clean
	$(CC) $(CFLAGS) $(SRCB) -o $(BONUS)

clean:
	@rm -rf $(OBJB)
fclean: clean
	@rm -rf $(BONUS)

re: fclean bonus
