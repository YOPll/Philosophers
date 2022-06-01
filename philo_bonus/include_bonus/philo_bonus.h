/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:12:03 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/06/01 16:34:56 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# define INT_MAX	2147483647
# define INT_MIN	-2147483648

# include <unistd.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct timeval	t_time;
typedef struct s_info	t_info;

typedef struct s_philo
{
	int				id;
	int				ate;
	int				should_die;
	int				last_eat;
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
	sem_t			*forks;
}	t_info;

void		is_integer(int ac, char *av[]);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_puterr(char *str);
void		ft_get_args(t_info *args, int ac, char *av[]);
void		ft_check_args(t_info *args, int ac);
int			ft_atoi(const char *str);
void		check_max_and_min(long x);
int			ft_exit(void);
long long	ft_get_time(void);
long long	ft_current_time(t_philo *philo);
void		ft_creat_philos(t_info *philo, t_philo *args);
void    	ft_init(t_info *philo);
void		print_msg(char *msg, t_philo *philo);
void		sleep_think(t_philo *philo);
void		philo_eating(t_philo *philo);
void		forks_down(t_philo *philo);
void		grab_fork(t_philo *philo);
void		action_control(t_philo *args);

#endif