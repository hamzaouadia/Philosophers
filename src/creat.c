
#include  "Philosophers.h"

pthread_mutex_t	*creatforks(t_info *philo_info)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t)
			* philo_info->nof_philosophers);
	while (i < philo_info->nof_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

t_philos	*creatphilos(t_info *philo_info, pthread_mutex_t *forks)
{
	t_philos		*philos;
	pthread_t		*threads;
	long			i;

	philos = malloc(sizeof(t_philos) * philo_info->nof_philosophers);
	threads = malloc(sizeof(pthread_t) * philo_info->nof_philosophers);
	if (!philos || !threads)
		return (NULL);
	i = -1;
	pthread_mutex_init(&(philos->msg), NULL);
	pthread_mutex_init(&(philos->mutex), NULL);
	philo_info->init_time = ft_gettime();
	while (++i < philo_info->nof_philosophers)
	{
		philos[i].id = i;
		philos[i].nb_time_eat = 0;
		philos[i].threads = threads;
		philos[i].forks = forks;
		philos[i].philo_info = philo_info;
		philos[i].last_meal = ft_gettime();
	}
	return (philos);
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
