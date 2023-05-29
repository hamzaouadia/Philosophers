
#include  "Philosophers.h"

long long	ft_gettime(void)
{
	struct timeval	t;
	long long		ms;

	gettimeofday(&t, NULL);
	ms = t.tv_sec * 1000;
	ms += t.tv_usec / 1000;
	return (ms);
}

long long	gettimeofnow(t_philos *philos)
{
	return (ft_gettime() - philos->philo_info->init_time);
}

void	ft_usleeping(t_philos *philos, long long tto_sleep)
{
	long long	time;
	long long	h;

	h = gettimeofnow(philos);
	while (1)
	{
		time = gettimeofnow(philos);
		if (time >= h + tto_sleep)
			break ;
		usleep(500);
	}
}

void	printstatus(t_philos *philos, char *s)
{
	pthread_mutex_lock(&(philos->msg));
	printf("%lld %d %s", gettimeofnow(philos), philos->id + 1, s);
	pthread_mutex_unlock(&(philos->msg));
}
