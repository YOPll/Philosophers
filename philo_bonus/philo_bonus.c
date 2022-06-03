/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:11:55 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/06/03 23:48:10 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/philo_bonus.h"

void	free_and_close(t_info *philo)
{
	int	i;
	int	x;
	int	j;

	i = -1;
	j = 0;
	while (++i < philo->nb_philos)
	{
		waitpid(-1, &x, 0);
		if (WIFEXITED(x) && WEXITSTATUS(x) == EXIT_SUCCESS)
			continue ;
		else
		{
			while (j < philo->nb_philos)
				kill(philo->table[j++], SIGTERM);
			break ;
		}
	}
	sem_close(philo->forks);
	sem_close(philo->pencil);
}

int	main(int ac, char *av[])
{
	t_info	*args;

	if (!(ac != 5 && ac != 6))
	{
		is_integer(ac, av);
		args = ft_calloc(1, sizeof(*args));
		ft_get_args(args, ac, av);
		ft_check_args(args, ac);
		args->table = ft_calloc(args->nb_philos, sizeof(int));
		(!args->table) && ft_exit();
		ft_init(args);
		free_and_close(args);
	}	
	else
	{
		return (ft_puterr("Usage : ./philo <number_of_philosophers> "\
			"<time_to_die> <time_to_eat> <time_to_sleep> "\
			"[number_of_times_each_philosopher_must_eat]\n"));
	}
	return (0);
}
