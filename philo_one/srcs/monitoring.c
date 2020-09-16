/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:03:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/16 17:34:21 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// MONITORING SANS THREAD //


void		monitoring(t_gbl *gbl)
{
	int			i;
	t_philo		*philo;

	philo = gbl->philo;
	i = 0;
	while (gbl->is_dead == -1)
	{
		if ((get_time(philo[i].t_die) > gbl->time_to_die ||
		philo[i].t_die == gbl->max_eat) && philo[i].t_start != -1)
		{
			gbl->is_dead = i;
			if (pthread_mutex_lock(&gbl->m_isdead) == 0)
				ft_messages_dead(&philo[i], get_time(philo[i].t_die), gbl, "\033[1;31mIS DEAD\033[0;0m");
			return ;
		}
		i += 1;
		if (i >= gbl->maxphilo)
			i = 0;
	}
	return ;
}

// void		*monitor(void *args)
// {
// 	int			i;
// 	t_philo		*philo;
// 	t_gbl 		*gbl;

// 	gbl = (t_gbl *)args;
// 	philo = gbl->philo;
// 	i = gbl->id_monitor * 20;
// 	while (gbl->is_dead == -1)
// 	{
// 		if ((get_time(philo[i].t_die) > gbl->time_to_die ||
// 		philo[i].t_die == gbl->max_eat) && philo[i].t_start != -1)
// 		{
// 			gbl->dead_time = get_time(philo[i].t_die);
// 			gbl->is_dead = i;
// 			return (gbl);
// 		}
// 		i += 1;
// 		if (i >= (gbl->id_monitor * 20) + 19 || i >= gbl->maxphilo)
// 			i = gbl->id_monitor * 20;
// 	}
// 	return (gbl);
// }

// void		monitoring(t_gbl *gbl)
// {
// 	pthread_t   monitors[gbl->maxphilo / 20];
// 	int i;

// 	i = 0;
// 	while (i < (gbl->maxphilo / 20))
// 	{
// 		gbl->id_monitor = i;
// 		if (pthread_create(&monitors[i], NULL, monitor, gbl) != 0)
// 			return ;
// 		pthread_detach(monitors[i]);
// 		osleep(3);
// 		i += 1;
// 	}
// 	while (gbl->is_dead == -1)
// 	{}
// 	ft_messages_dead(&gbl->philo[gbl->is_dead], gbl->dead_time, gbl, "\033[1;31mIS DEAD\033[0;0m");

// }