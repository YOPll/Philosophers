/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:11:55 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/26 22:40:21 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/philo_bonus.h"

void    ft_creat_philos(t_info *philo)
{
	int	i;
	int	id;
	t_philo	*args;

	args = ft_calloc(philo->nb_philos, sizeof(t_philo));
	(!args) && ft_exit();
	i = 0;
	philo->created_at = ft_get_time();
	printf("xoxo");
}

void    ft_init(t_info *philo)
{
	sem_unlink("phi");
	philo->forks = sem_open("phi", O_CREAT | O_EXCL, 0644, philo->nb_philos);
	if (philo->forks == SEM_FAILED)
	{
		ft_puterr("semaphore error");
		sem_unlink("phi");
	}
}