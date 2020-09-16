/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:03:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/16 14:42:24 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		*monitor(void *args)
{
	int			i;
	t_philo		*philo;
	t_gbl 		*gbl;

	gbl = (t_gbl *)args;
	philo = gbl->philo;
	i = gbl->id_monitor * 10;
	while (gbl->is_dead == 0)
	{
		if ((get_time(philo[i].t_die) > gbl->time_to_die ||
		philo[i].t_die == gbl->max_eat) && philo[i].t_start != -1)
		{
			ft_messages(&philo[i], gbl, "\033[1;31mIS DEAD\033[0;0m");
			gbl->is_dead = 1;
			return (gbl);
		}
		i += 1;
		if (i >= (gbl->id_monitor * 10) + 9 || i >= gbl->maxphilo)
			i = gbl->id_monitor * 10;
	}
	return (gbl);
}

void		monitoring(t_gbl *gbl)
{
	pthread_t   monitors[gbl->maxphilo / 10];
	int i;

	i = 0;
	while (i < (gbl->maxphilo / 10))
	{
		gbl->id_monitor = i;
		if (pthread_create(&monitors[i], NULL, monitor, gbl) != 0)
			return ;
		pthread_detach(monitors[i]);
		osleep(3);
		i += 1;
	}
	while (gbl->is_dead == 0);
}