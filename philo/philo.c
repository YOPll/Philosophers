/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <mrx.ga10@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:58:08 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/05 14:58:11 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	main(int ac, char *av[])
{
	t_info	args;

	if (ac != 5 && ac != 6)
		return (ft_puterr("Usage : ./philo <number_of_philosophers> "\
			"<time_to_die> <time_to_eat> <time_to_sleep> "\
			"[number_of_times_each_philosopher_must_eat]\n"));
	else
	{
		if (is_integer(ac, av) == 1)
			return (1);
		memset(&args, 0, sizeof(t_arg));
		ft_get_args(&args.philo_info, ac, av);
		ft_check_args(args.philo_info, ac);
		ft_init(&args);
	}
	return (0);
}
