/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:03:20 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/20 11:05:53 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

sem_t		*init_sem(char *str, int i)
{
	sem_t *res;

	sem_unlink(str);
	res = sem_open(str, O_CREAT | O_EXCL, 0644, i);
	return (res);
}

int			init_gbl(int argc, char **argv, t_gbl *gbl)
{
	gbl->talk = init_sem("Sem_Talk", 1);
	gbl->wait = init_sem("Sem_Wait", 0);
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
	int		i;
	char	res[50];
	char	str[50];

	i = -1;
	gbl->philo = NULL;
	gbl->t_start = get_time(0);
	gbl->s_forks = init_sem("Sem_Fork", gbl->maxphilo);
	gbl->philo = ft_calloc(sizeof(t_philo), gbl->maxphilo);
	while (++i < gbl->maxphilo)
	{
		ft_bzero(&gbl->philo[i], sizeof(t_philo));
		ft_bzero(&res, sizeof(char) * 50);
		ft_bzero(&str, sizeof(char) * 50);
		res[ft_nb_to_char(res, str, i)] = '\0';
		gbl->philo[i].id = i;
		gbl->philo[i].gbl = gbl;
		gbl->philo[i].t_die = -1;
		gbl->philo[i].lock = init_sem(res, 1);
		res[0] = 'a';
		res[ft_nb_to_char(res + 1, str, i) + 1] = '\0';
		gbl->philo[i].max_eat = init_sem(res, 0);
	}
	return (1);
}

void		init_philo(t_gbl *gbl)
{
	pthread_t	thread;
	pid_t		pid[gbl->maxphilo];
	int			i;
	void		*philo;

	philo = (void*)gbl;
	if (pthread_create(&thread, NULL, monitor2, philo) != 0)
		return ;
	pthread_detach(thread);
	i = 0;
	while (i < gbl->maxphilo)
	{
		philo = (void *)&gbl->philo[i];
		if (!(pid[i] = fork()))
			ft_start(philo);
		osleep(1);
		i++;
	}
	sem_wait(gbl->wait);
	i = -1;
	while (++i < gbl->maxphilo)
		kill(pid[i], SIGKILL);
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
		free_all(&gbl);
	}
	else if (argc < 5)
		ft_putstr_fd("More arguments needed\n", 2);
	else
		ft_putstr_fd("Too much arguments\n", 2);
	return (1);
}
