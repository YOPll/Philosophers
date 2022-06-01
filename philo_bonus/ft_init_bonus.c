/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:11:55 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/06/01 18:42:52 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/philo_bonus.h"

void	*check_mychild(void *args)
{
	t_philo *philo;
	
	philo = args;
	while (1)
	{
		if ((philo->last_meal + philo->philo_info->t_die) <= ft_get_time() - \
				philo->philo_info->created_at)
		{
			print_msg("died", args);
			exit(0);
		}
		usleep(489);	
	}
	return (NULL);
}

void	action_control(t_philo *args)
{
	pthread_t	controller;

	pthread_create(&controller, NULL, check_mychild, args);
	while (1)
	{
		grab_fork(args);
		grab_fork(args);
		philo_eating(args);
		forks_down(args);
		sleep_think(args);
	}
	pthread_detach(controller);
}

void    ft_creat_philos(t_info *philo , t_philo *args)
{
	int	i;
	int	id;
	long long x;
	
	i = 0;
	x = ft_get_time();
	printf("%lld\n", ft_get_time());
	philo->created_at = x;
	printf("%lld\n", philo->created_at);
	printf("%lld\n", philo->created_at - x);
	while (i < philo->nb_philos)
	{
		id = fork();
		if (id == 0)
		{
			args[i].id = i;
			//action_control(args + i);
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
	sem_unlink("phi");
	philo->forks = sem_open("phi", O_CREAT , 0644, philo->nb_philos);
	if (philo->forks == SEM_FAILED)
	{
		ft_puterr("semaphore error");
		sem_unlink("phi");
	}
	ft_creat_philos(philo, args);
}