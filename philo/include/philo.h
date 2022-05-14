/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <mrx.ga10@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:07:55 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/05 15:07:56 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define INT_MAX	2147483647
# define INT_MIN	-2147483648

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct timeval	t_time;

typedef struct s_args
{
	int	nb_philos;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nb_t_eat;
}	t_arg;

typedef struct s_info
{
	int				id;
	int				state;
	pthread_mutex_t	fork;
	int				should_die;
	long long		curr_time;
	t_arg			philo_info;
}	t_info;

void	ft_putstr_fd(char *str, int fd);
int		ft_puterr(char *str);
int		ft_atoi(const char *str);
void	ft_get_args(t_arg *args, int ac, char *av[]);
int		ft_check_args(t_arg args, int ac);
void	check_max_and_min(long x);
int		is_integer(int ac, char *av[]);
int		ft_init(t_info *info);

#endif
