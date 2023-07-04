/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:56:06 by haouadia          #+#    #+#             */
/*   Updated: 2023/05/30 23:56:12 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define _ERROR		1
# define _SUCCESS	0

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info
{
	int				nof_philosophers;
	int				tto_die;
	int				tto_eat;
	int				tto_sleep;
	int				number_must_eat;
	long long		init_time;
	int				death;
}					t_info;
typedef struct s_philo
{
	pthread_mutex_t	mutex;
	t_info			*philo_info;
	int				id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	pthread_t		*threads;
	long long		last_meal;
	int				nb_time_eat;
}					t_philos;

int					ft_atoi(const char *str);
long long			ft_gettime(void);
long long			gettimeofnow(t_philos *philos);
void				ft_usleeping(t_philos *philos, long long tto_sleep);
void				printstatus(t_philos *philos, char *s);
pthread_mutex_t		*creatforks(t_info *philo_info);
t_philos			*creatphilos(t_info *philo_info,
						pthread_mutex_t *forks);
void				ft_thinking(t_philos *philos);
void				ft_sleeping(t_philos *philos);
void				ft_eating(t_philos *philos);
void				*threadstatus(void *arg);
void				ft_creatthreads(t_philos *philos, t_info *philo_info);
int					ft_reterror(char *str, int fd);
#endif
