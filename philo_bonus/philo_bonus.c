/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:11:55 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/24 21:18:16 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/philo_bonus.h"

int	main(int ac, char *av[])
{
	t_info	*args;

	if (ac != 5 && ac != 6)
		return (ft_puterr("Usage : ./philo <number_of_philosophers> "\
			"<time_to_die> <time_to_eat> <time_to_sleep> "\
			"[number_of_times_each_philosopher_must_eat]\n"));
	else
	{
		is_integer(ac, av);
		args = ft_calloc(1, sizeof(args));
		ft_get_args(args, ac, av);
		ft_check_args(args, ac);
	}
	return (0);
}
