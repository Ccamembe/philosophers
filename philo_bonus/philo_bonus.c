/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamembe <ccamembe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:10:10 by ccamembe          #+#    #+#             */
/*   Updated: 2022/06/02 20:10:10 by ccamembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	*ft_init_philo(t_data *data)
{
	int	i;
	int	*pids;
	int	pid;

	pids = (int *)malloc(sizeof(int) * data->nbp);
	i = -1;
	while (++i < data->nbp)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_ll(&data->philo[i]);
			exit(0);
		}
		else
			pids[i] = pid;
	}
	return (pids);
}

void	kill_p(t_data *data, int *pid)
{
	int	i;

	i = 0;
	waitpid(-1, NULL, 0);
	while (i < data->nbp)
	{
		kill(pid[i], SIGKILL);
		i++;
	}
	free(data->philo->ph);
	free(pid);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		*pid;

	check_args(ac, av);
	get_args(ac, av, &data);
	init_data(&data);
	sem_unlink("sem");
	sem_unlink("print");
	pid = ft_init_philo(&data);
	sem_close(data.philo->print);
	sem_close(data.philo->sem);
	kill_p(&data, pid);
}
