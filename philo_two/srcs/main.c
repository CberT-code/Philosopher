/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:03:20 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/18 22:49:45 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int			init_gbl(int argc, char **argv, t_gbl *gbl)
{
	pthread_mutex_init(&gbl->talk, NULL);
	pthread_mutex_init(&gbl->wait, NULL);
	pthread_mutex_unlock(&gbl->talk);
	pthread_mutex_lock(&gbl->wait);
	gbl->max_eat = -1;
	gbl->nb_max_eat = 0;
	gbl->is_dead = 0;
	if ((gbl->maxphilo = ft_atoi(argv[1])) == 0 ||
	(gbl->t_to_die = ft_atoi(argv[2])) == 0 ||
	(gbl->t_to_eat = ft_atoi(argv[3])) == 0 ||
	(gbl->t_to_sleep = ft_atoi(argv[4])) == 0 ||
	(argc == 6 && (gbl->max_eat = ft_atoi(argv[5])) == 0))
	{
		ft_putstr_fd("WRONG ARGUMENT\n", 2);
		return (0);
	}
	return (1);
}

int			init_mutex(t_gbl *gbl)
{
	int	i;

	gbl->philo = NULL;
	i = 0;
	gbl->t_start = get_time(0);
	gbl->m_forks = ft_calloc(sizeof(pthread_mutex_t), gbl->maxphilo + 1);
	gbl->philo = ft_calloc(sizeof(t_philo), gbl->maxphilo);
	while (i < gbl->maxphilo)
	{
		pthread_mutex_init(&gbl->m_forks[i], NULL);
		pthread_mutex_unlock(&gbl->m_forks[i]);
		ft_bzero(&gbl->philo[i], sizeof(t_philo));
		gbl->philo[i].id = i;
		gbl->philo[i].gbl = gbl;
		gbl->philo[i].t_die = -1;
		i++;
	}
	return (1);
}

void		init_philo(t_gbl *gbl)
{
	pthread_t	thread[gbl->maxphilo];
	int			i;
	void		*philo;

	i = 0;
	while (i < gbl->maxphilo)
	{
		philo = (void *)&gbl->philo[i];
		if (pthread_create(&thread[i], NULL, ft_start, philo) != 0)
			return ;
		pthread_detach(thread[i]);
		osleep(1);
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_gbl	gbl;

	if (argc == 5 || argc == 6)
	{
		if (init_gbl(argc, argv, &gbl) == 0)
			return (0);
		init_mutex(&gbl);
		init_philo(&gbl);
		pthread_mutex_lock(&gbl.wait);
		free_all(&gbl);
	}
	else if (argc < 5)
		ft_putstr_fd("More arguments needed\n", 2);
	else
		ft_putstr_fd("Too much arguments\n", 2);
	return (1);
}
