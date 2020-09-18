/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:03:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/18 19:24:31 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// MONITORING SANS THREAD //


// void		monitoring(t_gbl *gbl)
// {
// 	int			i;
// 	t_philo		*philo;

// 	philo = gbl->philo;
// 	while (gbl->is_dead == -1)
// 	{
// 		i = 0;
// 		while (i < gbl->maxphilo && gbl->is_dead == -1)
// 		{
// 			if ((get_time(philo[i].t_die) > gbl->time_to_die ||
// 			(gbl->max_eat != -1 && philo[i].eat == gbl->max_eat))
// 			&& philo[i].t_die != -1)
// 			{
// 				gbl->is_dead = i;
// 				ft_messages_dead(&philo[i], get_time(philo[i].t_start), gbl, "IS DEAD");
// 				//ft_messages(&philo[i], get_time(philo[i].t_start), gbl, "\033[1;31mIS DEAD\033[0;0m");
// 				return ;
// 			}
// 			i += 1;
// 		}
// 	}
// }


// void		*monitor(void *args)
// {
// 	int			i;
// 	int			start;
// 	t_philo		*philo;
// 	t_gbl 		*gbl;

// 	gbl = (t_gbl *)args;
// 	philo = gbl->philo;
// 	i = gbl->id_monitor * 20;
// 	start = i;
// 	while (gbl->is_dead == -1 && gbl->max_eat == -1 )
// 	{
// 		if ((get_time(philo[i].t_die) > gbl->time_to_die) && philo[i].t_start != -1)
// 		{
// 			gbl->dead_time = get_time(philo->t_start);
// 			gbl->is_dead = i;
// 			return (gbl);
// 		}
// 		i += i;
// 		if (i == start + 20 || i == gbl->maxphilo)
// 			i = start;
// 	}
// 	gbl->is_dead = -2;
// 	return (gbl);
// }

// void		monitoring(t_gbl *gbl)
// {
// 	pthread_t   monitors[gbl->maxphilo / 20];
// 	int i;

// 	i = 0;
// 	while (i < gbl->maxphilo / 20)
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
// 	if (gbl->is_dead != -2)
// 		ft_messages(&gbl->philo[gbl->is_dead], gbl->dead_time, gbl, "\033[1;31mIS DEAD\033[0;0m");
// }


void		*monitor(void *args)
{
	t_philo		*philo;

	philo = (t_philo*)args;
	while (philo->gbl->is_dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time(philo->t_die) > philo->gbl->t_to_die && philo->gbl->is_dead == 0)
		{
			ft_messages_dead(philo, get_time(philo->gbl->t_start), philo->gbl, "\033[1;31mIS DEAD\033[0;0m");
			philo->gbl->is_dead = 1;
			pthread_mutex_unlock(&philo->lock);
			pthread_mutex_unlock(&philo->gbl->wait);
			return (philo);
		}
		osleep(1);
	}
	return (philo);
}