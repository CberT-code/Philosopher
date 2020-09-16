/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:03:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/16 13:34:51 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		monitoring_pair(t_gbl *gbl)
{
	int		i;
	t_philo *philo;
	
	philo = gbl->philo;
	i = 0;
	while (gbl->is_dead == 0)
	{
		if ((get_time(philo[i].t_die) > gbl->time_to_die ||
		philo[i].t_die == gbl->max_eat) && philo[i].t_start != -1)
		{
			ft_messages(&philo[i], gbl, "IS DEAD");
			gbl->is_dead = 1;
			return ;
		}
		i += 2;
		if (i >= gbl->maxphilo)
			i = 0;
	}
	return ;
}

void		*monitoring_impair(void *args)
{
	int			i;
	t_philo		*philo;
	t_gbl 		*gbl;

	gbl = (t_gbl *)args;
	philo = gbl->philo;
	i = 1;
	while (gbl->is_dead == 0)
	{
		if ((get_time(philo[i].t_die) > gbl->time_to_die ||
		philo[i].t_die == gbl->max_eat) && philo[i].t_start != -1)
		{
			ft_messages(&philo[i], gbl, "IS DEAD");
			gbl->is_dead = 1;
			return (gbl);
		}
		i += 2;
		if (i >= gbl->maxphilo)
			i = 1;
	}
	return (gbl);
}

void		monitoring(t_gbl *gbl)
{
	pthread_t   monitor_pair;

	if (pthread_create(&monitor_pair, NULL, monitoring_impair, gbl) != 0)
        return ;
    pthread_detach(monitor_pair);
	monitoring_pair(gbl);
}