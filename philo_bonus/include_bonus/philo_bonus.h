/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:12:03 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/24 21:27:17 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				ate;
	int				should_die;
	long long		last_meal;
	t_info			*philo_info;
}	t_philo;

typedef struct s_info
{
	int				nb_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_t_eat;
	int				*table;
	long long		created_at;
	t_philo			*philo;
	sem_t			*forks;
}	t_info;

void	is_integer(int ac, char *av[]);

#endif