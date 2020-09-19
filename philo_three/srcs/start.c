/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:27:38 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/19 21:11:39 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_msg2(t_philo *philo, long int time, t_gbl *gbl, char *message)
{
	if (sem_wait(gbl->talk) == 0)
	{
		aff_msg(time, philo->id + 1, "has taken a fork", 1);
		aff_msg(time, philo->id + 1, "has taken a fork", 1);
		aff_msg(time, philo->id + 1, message, 1);
	}
	sem_post(gbl->talk);
}

void	ft_msg(t_philo *philo, long int time, t_gbl *gbl, char *message)
{
	if (sem_wait(gbl->talk) == 0)
		aff_msg(time, philo->id + 1, message, 1);
	sem_post(gbl->talk);
}

void	ft_eat(t_philo *philo, t_gbl *gbl, char *message)
{
	int i;

	i = (philo->id == 0) ? gbl->maxphilo - 1 : -1;
	if (sem_wait(gbl->s_forks) == 0 && sem_wait(gbl->s_forks) == 0)
	{
		sem_wait(philo->lock);
		philo->t_die = get_time(0);
		ft_msg2(philo, get_time(gbl->t_start), gbl, message);
		philo->eat += 1;
		if (philo->eat == gbl->max_eat)
			gbl->nb_max_eat++;
		osleep(gbl->t_to_eat);
		sem_post(gbl->s_forks);
		sem_post(gbl->s_forks);
		sem_post(philo->lock);
	}
}

void	ft_sleep(t_philo *philo, t_gbl *gbl, char *message)
{
	ft_msg(philo, get_time(gbl->t_start), gbl, message);
	osleep(gbl->t_to_sleep);
}

void	*ft_start(void *args)
{
	t_philo		*philo;
	pthread_t	t_monitor;
	t_gbl		*gbl;

	philo = (t_philo *)args;
	gbl = philo->gbl;
	philo->t_die = get_time(0);
	if (pthread_create(&t_monitor, NULL, &monitor, philo) != 0)
		return (gbl);
	pthread_detach(t_monitor);
	while (philo->gbl->is_dead == 0)
	{
		ft_eat(philo, gbl, "is eating");
		ft_sleep(philo, gbl, "is sleeping");
		ft_msg(philo, get_time(gbl->t_start), gbl, "is thinking");
	}
	return (gbl);
}
