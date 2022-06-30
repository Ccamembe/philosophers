/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamembe <ccamembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:09:53 by ccamembe          #+#    #+#             */
/*   Updated: 2022/06/02 20:09:53 by ccamembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct philo
{
	struct s_data	*data;
	int				is_eat;
	int				is_die;
	int				num;
	pthread_t		ph;
}t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	ful;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
	int				nbp;
	int				tdie;
	int				teat;
	int				tsleep;
	int				nfe;
	long long		currnt;
	long long		*last_eat;
	int				die;
}t_data;

long long	get_time(void);
void		ft_usleep(int time);
int			ft_atoi(const char *str);
void		check_args(int ac, char **av);
void		get_args(int ac, char **av, t_data *data);
void		init_data(t_data *data);
void		*ft_init_philo(t_data *data);
void		ft_printstatus(t_philo *philo, char *s, int b);
void		*check_death(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_thinking(t_philo *philo);
void		ft_free(t_data *data);
#endif
