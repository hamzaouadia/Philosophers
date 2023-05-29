
#include  "Philosophers.h"

int	init_info(int argc, char **argv, t_info *philos)
{
	philos->nof_philosophers = ft_atoi(argv[1]);
	philos->tto_die = ft_atoi(argv[2]);
	philos->tto_eat = ft_atoi(argv[3]);
	philos->tto_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philos->number_must_eat = ft_atoi(argv[5]);
	else
		philos->number_must_eat = -1;
	if (philos->nof_philosophers <= 0 || philos->tto_die <= 0
		|| philos->tto_eat <= 0 || philos->tto_sleep <= 0)
		return (-1);
	if (argc == 6 && philos->number_must_eat <= 0)
		return (-1);
	return (1);
}

int	ft_azrael(t_philos *philos)
{
	long long	time;
	long long	last;

	pthread_mutex_lock(&(philos->mutex));
	time = ft_gettime();
	last = philos->last_meal;
	if (time - last > philos->philo_info->tto_die)
	{
		pthread_mutex_lock(&(philos->msg));
		printf("%lld %d %s", gettimeofnow(philos), philos->id + 1, "died\n");
		return (1);
	}
	pthread_mutex_unlock(&(philos->mutex));
	return (0);
}

int	ft_checkstatus(t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < philos->philo_info->nof_philosophers)
	{
		if (ft_azrael(&philos[i]) != 0)
			return (1);
	}
	i = 0;
	if (philos->philo_info->number_must_eat != -1)
	{
		while (i < philos->philo_info->nof_philosophers
			&& philos[i].nb_time_eat >= philos->philo_info->number_must_eat)
			i++;
		if (i == philos->philo_info->nof_philosophers)
			return (1);
	}
	return (-1);
}

int	main(int ac, char **av)
{
	t_philos		*philos;
	t_info			*philo_info;
	pthread_mutex_t	*forks;

	philo_info = malloc(sizeof(t_info));
	if (!philo_info)
		return (ft_reterror("ERROR : malloc failled\n", 2));
	if (ac < 5 || ac > 6 || init_info(ac, av, philo_info) == -1)
	{
		free(philo_info);
		return (ft_reterror("ERROR: wrong arguments\n", 2));
	}
	forks = creatforks(philo_info);
	if (!forks)
		return (ft_reterror("ERROR : malloc failled\n", 2));
	philos = creatphilos(philo_info, forks);
	if (!philos)
		return (ft_reterror("ERROR : malloc failled\n", 2));
	ft_creatthreads(philos, philo_info);
	while (1)
	{
		if (ft_checkstatus(philos) == 1)
			break ;
	}
}
