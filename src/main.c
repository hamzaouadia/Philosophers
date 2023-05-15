/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:06:16 by haouadia          #+#    #+#             */
/*   Updated: 2023/04/13 23:06:17 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int Azrael(t_philo *philo, int n_philo)
{
	int i;
	uint64_t died;

	i = 0;
	while (i < n_philo)
	{
        pthread_mutex_lock(&philo[i].philo_info->print);
		died = time_stamp() - philo[i].last_eat;
        pthread_mutex_unlock(&philo[i].philo_info->print);
		if (died >= philo[i].philo_info->tto_die)
        {
            pthread_mutex_lock(&philo[i].philo_info->print);
            printf("%lld %d died\n", time_stamp() - philo->start, philo->philo_num);
			exit (0);
        }
		i++;
	}
	return (0);
}

int must_eat(t_philo *philo, int n_philo)
{
    if (philo[n_philo - 1].nb_meal == philo->philo_info->notepm_eat)
        exit (0);
    return 0;
}

int data(t_info *info, t_philo *philo, pthread_mutex_t *mutex)
{
	int	i;

	i = -1;

    if (pthread_mutex_init(&info->print, NULL) != 0)
			return (ft_reterror("ERROR : pthread_mutex_init function\n", 2));
	while (++i < info->num_of_philo)
	{
		if (pthread_mutex_init(&mutex[i], NULL) != 0)
			return (ft_reterror("ERROR : pthread_mutex_init function\n", 2));
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		philo[i].philo_info = info;
		philo[i].philo_num = i + 1;
        philo[i].nb_meal = 0;
		philo[i].start = time_stamp();
		philo[i].l_fork = &mutex[(i + 1) % info->num_of_philo];
		philo[i].r_fork = &mutex[i % info->num_of_philo];
	}
	return (_SUCCESS);
}

int creat_philo(t_info *info, t_philo *philo)
{
	pthread_t	*tread;
	pthread_mutex_t	*mutex;
	int			i;

	tread = malloc(sizeof(pthread_t) * info->num_of_philo);
	mutex = malloc(sizeof(pthread_mutex_t) * info->num_of_philo);

	if (!tread || !mutex)
		return (ft_reterror("ERROR : failed to allocate memory\n", 2));
	if (data(info, philo, mutex))
		return (1);
	i = -1;
	while (++i < info->num_of_philo)
	{
		philo[i].last_eat = time_stamp();
        pthread_create(&tread[i], NULL, table, &philo[i]);
        usleep (50);
	}
	return (_SUCCESS);
}

int main(int ac, char **av)
{
	t_info	info;
    t_philo *philo;

	if (ac != 5 && ac != 6)
		return(ft_reterror("ERROR : wrong num of arguments\n", 2));
	if (fill_data(&info, ac, av))
		return (1);
	philo = malloc(sizeof(t_philo) * info.num_of_philo);
	if (!philo)
		return (ft_reterror("ERROR : failed to allocate memory\n", 2));
	if (creat_philo(&info, philo))
		return (1);
	while (1)
	{
		if (Azrael(philo, info.num_of_philo) == 1)
			return (0);
        if (must_eat(philo, info.num_of_philo) == 1)
			return (0);
	}
	return (0);	
}
