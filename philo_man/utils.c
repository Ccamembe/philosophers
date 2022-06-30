/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamembe <ccamembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:09:57 by ccamembe          #+#    #+#             */
/*   Updated: 2022/06/02 20:09:57 by ccamembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printstatus(t_philo *philo, char *s, int b)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (s)
		printf("%lld %d %s\n", get_time() - philo->data->currnt, philo->num, s);
	if (b)
		pthread_mutex_unlock(&philo->data->mutex);
}

void	ft_usleep(int time)
{
	long long	t;

	t = get_time();
	while (get_time() - t < time)
		usleep(1);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_atoi(const char *str)
{
	long int	num;
	int			sign;

	num = 0;
	sign = 1;
	while ((*str == '\n' || *str == '\f' || *str == '\v' || *str == '\t'
			|| *str == '\r' || *str == ' ') && *str)
		str++;
	if ((*str == '+' || *str == '-') && *str)
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		num = (num * 10) + ((int)*str - '0');
		str++;
	}
	return (num * sign);
}
