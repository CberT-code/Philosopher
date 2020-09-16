/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:03:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/16 19:02:42 by cbertola         ###   ########.fr       */
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
		philo[i].t_die == gbl->max_eat) && philo[i].t_die != -1)
		{
			gbl->is_dead = i;
			pthread_mutex_lock(&gbl->m_isdead);
			pthread_mutex_destroy(&gbl->talk);
			ft_messages_dead(&philo[i], get_time(philo[i].t_start), gbl, "\033[1;31mIS DEAD\033[0;0m");
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
// 	i = gbl->id_monitor;
// 	while (gbl->is_dead == -1)
// 	{
// 		if ((get_time(philo[i].t_die) > gbl->time_to_die ||
// 		philo[i].t_die == gbl->max_eat) && philo[i].t_start != -1)
// 		{
// 			pthread_mutex_destroy(&gbl->talk);
// 			gbl->dead_time = get_time(philo[i].t_die);
// 			gbl->is_dead = i;
// 			return (gbl);
// 		}
// 	}
// 	return (gbl);
// }

// void		monitoring(t_gbl *gbl)
// {
// 	pthread_t   monitors[gbl->maxphilo / 20];
// 	int i;

// 	i = 0;
// 	while (i < gbl->maxphilo)
// 	{
// 		gbl->id_monitor = i;
// 		if (pthread_create(&monitors[i], NULL, monitor, gbl) != 0)
// 			return ;
// 		pthread_detach(monitors[i]);
// 		osleep(6);
// 		i += 1;
// 	}
// 	while (gbl->is_dead == -1)
// 	{}
// 	ft_messages_dead(&gbl->philo[gbl->is_dead], gbl->dead_time, gbl, "\033[1;31mIS DEAD\033[0;0m");

// }