/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamembe <ccamembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:09:49 by ccamembe          #+#    #+#             */
/*   Updated: 2022/06/02 20:09:49 by ccamembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->mutex);
	while (++i < data->nbp)
	{
		pthread_mutex_destroy(&data->forks[i]);
	}
	return ;
}

void	*check_death(t_philo *philo)
{
	while (1)
	{
		if (get_time() - philo->data->last_eat[philo->num - 1] \
		>= philo->data->tdie)
		{
			if (philo->data->die != 2)
				ft_printstatus(philo, "died", 0);
			philo->data->die = 1;
			break ;
		}
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	data;

	check_args(ac, av);
	get_args(ac, av, &data);
	init_data(&data);
	ft_init_philo(&data);
	ft_free(&data);
	free(data.philos);
	free(data.forks);
	free(data.last_eat);
}
