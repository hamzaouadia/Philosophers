/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:07:02 by haouadia          #+#    #+#             */
/*   Updated: 2023/04/13 23:07:05 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void     parsing_arg(t_info *info, int ac, char **av)
{
	info->num_of_philo = ft_atoi(av[1]);
	info->tto_die = ft_atoi(av[2]);
	info->tto_eat = ft_atoi(av[3]);
	info->tto_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->notepm_eat = ft_atoi(av[5]);
    else
		info->notepm_eat = -1;

}

int	check_info(t_info *info, int ac)
{
	if (ac == 6 && info->notepm_eat <= 0)
		return (ft_reterror("ERROR: wrong num of must eat\n", 2));
	if (info->num_of_philo < 0)
		return (ft_reterror("ERROR: wrong num of philo\n", 2));
	if (info->tto_die < 0)
		return (ft_reterror("ERROR: wrong time to die\n", 2));
	if (info->tto_eat < 0)
		return (ft_reterror("ERROR: wrong time to eat\n", 2));
	if (info->tto_sleep < 0)
		return (ft_reterror("ERROR: wrong time to sleep\n", 2));
	return (_SUCCESS);
}

int     fill_data(t_info *info, int ac, char **av)
{
	parsing_arg(info, ac, av);
	if (check_info(info, ac))
		return (_ERROR);
	return (_SUCCESS);
}