/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:05:55 by haouadia          #+#    #+#             */
/*   Updated: 2023/04/13 23:05:57 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define _ERROR               1
# define _SUCCESS             0

typedef struct s_info
{
    int             num_of_philo;
	int			    notepm_eat;
	u_int64_t	    tto_die;
	u_int64_t	    tto_eat;
	u_int64_t	    tto_sleep;
	u_int64_t	    last_meal;
    pthread_mutex_t print;
}	t_info;

typedef struct s_philo
{
    int             philo_num;
    int             nb_meal;
    uint64_t        start;
    u_int64_t       now;
    uint64_t        last_eat;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *r_fork;
	t_info			*philo_info;
}	t_philo;

void        parsing_arg(t_info *info, int ac, char **av);
int	        check_info(t_info *info, int ac);
int         fill_data(t_info *info, int ac, char **av);
int         Azrael(t_philo *philo, int n_philo);
int         data(t_info *info, t_philo *philo, pthread_mutex_t *mutex);
int         creat_philo(t_info *info, t_philo *philo);
void	    messages(char *str, t_philo *philo);
uint64_t	time_stamp(void);
int	        ft_reterror(char *str, int fd);
int	        ft_atoi(char *str);
void	    philo_left_a_fork(t_philo *philo);
void	    philo_is_eating(t_philo *philo);
void	    philo_is_sleeping(t_philo *philo);
void	    philo_is_thinking(t_philo *philo);
void	    *table(void	*param);

#endif
