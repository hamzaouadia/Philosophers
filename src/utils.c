/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:06:40 by haouadia          #+#    #+#             */
/*   Updated: 2023/04/13 23:06:42 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	messages(char *str, t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->philo_info->print);
	time = time_stamp() - philo->start;
	printf("%lld %d %s\n", time_stamp() - philo->start, philo->philo_num, str);
	pthread_mutex_unlock(&philo->philo_info->print);
}

uint64_t time_stamp(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((((uint64_t) time.tv_sec) * 1000) + (time.tv_usec / 1000));
}

int	ft_reterror(char *str, int fd)
{
	char	*s;
	int		i;

	s = str;
	i = 0;
	while (*s++)
		i++;
	write(fd, str, i);
	return (_ERROR);
}

int	ft_atoi(char *str)
{
	int		i;
	int		signe;
	int	nbr;

	i = 0;
	signe = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * signe);
}
