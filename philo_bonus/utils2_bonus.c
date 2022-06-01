/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:11:55 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/06/01 16:34:11 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/philo_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*save;

	save = malloc(size * count);
	if (!save)
		return (NULL);
	ft_bzero(save, count * size);
	return (save);
}

int	ft_exit(void)
{
	exit(1);
	return (1);
}

void	print_msg(char *msg, t_philo *philo)
{
	if (!philo->should_die)
		printf("%lld\t%d\t%s\n", ft_get_time() - \
			philo->philo_info->created_at, philo->id + 1, msg);
}