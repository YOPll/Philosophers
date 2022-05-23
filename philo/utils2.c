/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:40:22 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/23 20:11:07 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

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

void	print_msg_mutex(char *msg, t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_info->finish_lock);
	if (!philo->philo_info->finished)
		printf("%lld\t%d\t%s\n", ft_get_time() - \
			philo->philo_info->created_at, philo->id + 1, msg);
	pthread_mutex_unlock(&philo->philo_info->finish_lock);
}
