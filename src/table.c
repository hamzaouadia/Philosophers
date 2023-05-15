/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:06:27 by haouadia          #+#    #+#             */
/*   Updated: 2023/04/13 23:06:29 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_left_a_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	messages("has taken a fork", philo);
    pthread_mutex_lock(philo->l_fork);
	messages("has taken a fork", philo);
}

void	philo_is_eating(t_philo *philo)
{

	philo_left_a_fork(philo);	
	messages("is eating", philo);
    philo->nb_meal++;;
	philo->last_eat = time_stamp();
	pthread_mutex_unlock(&philo->philo_info->print);
	while(time_stamp() - philo->last_eat <= philo->philo_info->tto_eat)
        usleep(philo->philo_info->tto_eat / 10);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	
}

void	philo_is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_info->print);
    philo->now = time_stamp();

	printf("%lld %d is sleeping\n", time_stamp() - philo->start, philo->philo_num);
	pthread_mutex_unlock(&philo->philo_info->print);
	while(time_stamp() - philo->now <= philo->philo_info->tto_sleep)
        usleep(philo->philo_info->tto_sleep / 10);
}

void	philo_is_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_info->print);
	printf("%lld %d is thinking\n", time_stamp() - philo->start, philo->philo_num);
	pthread_mutex_unlock(&philo->philo_info->print);
	
}

void	*table(void	*param)
{
    t_philo			 *philo;

	philo = (t_philo *)param;
    if (philo->philo_num % 2 == 0)
        usleep(500);
	while (1)
	{
		philo_is_eating(philo);
		philo_is_sleeping(philo);
		philo_is_thinking(philo);
	}
	return (NULL);
}
