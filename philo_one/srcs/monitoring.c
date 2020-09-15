/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:03:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/15 13:49:51 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		monitoring(t_gbl *gbl)
{
	int i;
	t_philo *philo;

	philo = gbl->philo;
	i = 0;
	while (gbl->is_dead == 0)
	{
		if (get_time(philo[i].t_die) > gbl->time_to_die ||
		philo[i].t_die == gbl->max_eat)
		{
			aff_msg(get_time(philo[i].t_start), philo[i].id + 48,
			"IS DEAD", 1);
			gbl->is_dead = 1;
			return ;
		}
		i++;
		if (i == gbl->maxphilo)
			i = 0;
	}
	return ;
}
