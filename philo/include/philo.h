/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:07:55 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/06/03 20:58:17 by zyacoubi         ###   ########.fr       */
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
typedef struct s_info	t_info;

typedef struct s_philo
{
	int				id;
	int				ate;
	int				should_die;
	int				last_meal;
	int				last_eat;
	t_info			*philo_info;
	pthread_t		thread;
}	t_philo;

typedef struct s_info
{
	int				_return;
	int				nb_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_t_eat;
	int				all_ate;
	int				finished;
	long long		created_at;
	t_philo			*philo;
	pthread_mutex_t	finish_lock;
	pthread_mutex_t	*forks;
}	t_info;

void		ft_putstr_fd(char *str, int fd);
int			ft_puterr(char *str);
int			ft_atoi(const char *str, int j, t_info *args);
void		ft_get_args(t_info *args, int ac, char *av[]);
int			ft_check_args(t_info *args, int ac);
void		check_max_and_min(long x);
int			is_integer(int ac, char *av[]);
int			ft_init(t_info *info);
void		*routine(void *args);
long long	ft_current_time(t_philo *philo);
void		*ft_is_philo_hungry(void *args);
void		*ft_check_philos(void *args);
void		print_msg_mutex(char *msg, t_philo *philo);
void		forks_down(t_philo *philo, int id1, int id2);
void		grab_fork(t_philo *philo, int id, int i);
long long	ft_get_time(void);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		philo_eating(t_philo *philo);
void		sleep_think(t_philo *philo);
void		join_and_free(t_info *philo);

#endif