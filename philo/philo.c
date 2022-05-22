/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:58:08 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/22 16:30:17 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	main(int ac, char *av[])
{
	t_info	*args;

	if (ac != 5 && ac != 6)
		return (ft_puterr("Usage : ./philo <number_of_philosophers> "\
			"<time_to_die> <time_to_eat> <time_to_sleep> "\
			"[number_of_times_each_philosopher_must_eat]\n"));
	else
	{
		if (is_integer(ac, av) == 1)
			return (1);
		args = ft_calloc(1, sizeof(args));
		ft_get_args(args, ac, av);
		if (ft_check_args(args, ac) == 1)
			return (1);
		ft_init(args);
	}
	return (0);
}
