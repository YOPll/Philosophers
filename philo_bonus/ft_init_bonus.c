/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:11:55 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/06/03 22:58:30 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/philo_bonus.h"

void	init_philo(t_info *info, t_philo *philo)
{
	philo->philo_info = info;
	philo->ate = 0;
	philo->last_meal = info->created_at;
	philo->should_die = 0;
}

void	*check_mychild(void *args)
{
	t_philo	*phi;

	phi = args;
	while (1)
	{
		if ((phi->last_meal + phi->philo_info->t_die) < ft_current_time(phi))
		{
			phi->should_die = 1;
			sem_wait(phi->philo_info->pencil);
			printf("%lli\t%d\t%s\n", ft_current_time(phi), phi->id + 1, "died");
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}

void	action_control(t_philo *args)
{
	pthread_t	controller;

	if (args->id % 2 == 0)
		usleep((args->philo_info->t_eat / 2) * 1000);
	args->last_meal = ft_current_time(args);
	pthread_create(&controller, NULL, check_mychild, args);
	pthread_detach(controller);
	while (1)
	{
		grab_fork(args);
		grab_fork(args);
		philo_eating(args);
		forks_down(args);
		if (args->philo_info->nb_t_eat != -1 && \
			args->ate >= args->philo_info->nb_t_eat)
			exit(0);
		sleep_think(args);
	}
}

void	ft_creat_philos(t_info *philo)
{
	t_philo	*phi;
	int		i;
	int		id;

	i = 0;
	phi = ft_calloc(philo->nb_philos, sizeof(t_philo));
	(!phi) && ft_exit();
	philo->created_at = ft_get_time();
	while (i < philo->nb_philos)
	{
		id = fork();
		if (id == 0)
		{
			init_philo(philo, phi + i);
			phi[i].id = i;
			action_control(phi + i);
		}
		else
			philo->table[i] = id;
		i++;
		usleep(100);
	}
}

void	ft_init(t_info *philo)
{
	sem_unlink("/phi");
	sem_unlink("/pencil");
	philo->forks = sem_open("/phi", O_CREAT, 0644, philo->nb_philos);
	philo->pencil = sem_open("/pencil", O_CREAT, 0644, 1);
	if (philo->forks == SEM_FAILED || philo->pencil == SEM_FAILED)
	{
		sem_unlink("/pencil");
		sem_unlink("/phi");
		ft_puterr("semaphore error");
	}
	ft_creat_philos(philo);
}
