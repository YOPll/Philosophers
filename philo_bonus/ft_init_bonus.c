/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:11:55 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/31 18:43:04 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/philo_bonus.h"

void    ft_creat_philos(t_info *philo , t_philo *args)
{
	int	i;
	int	id;
	
	i = 0;
	philo->created_at = ft_get_time();
	while (i < philo->nb_philos)
	{
		id = fork();
		if (id == 0)
		{
			args[i].id = i;
			//actions here
		}
		else
			philo->table[i] = id;
		i++;
		usleep(198);
	}
	free(args);
}

void    ft_init(t_info *philo)
{
	t_philo	*args;
	
	args = ft_calloc(philo->nb_philos, sizeof(t_philo));
	(!args) && ft_exit();
	args->philo_info = philo;
	printf("%lld",args->last_meal);
	sem_unlink("phi");
	philo->forks = sem_open("phi", O_CREAT , 0644, philo->nb_philos);
	if (philo->forks == SEM_FAILED)
	{
		ft_puterr("semaphore error");
		sem_unlink("phi");
	}
	//ft_creat_philos(philo);
}