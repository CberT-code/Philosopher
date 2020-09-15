/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:03:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/15 09:52:39 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		monitoring(t_gbl *gbl)
{
	int i;

	i = 0;
	while (gbl->is_dead == 0)
	{
		
		// printf("here philo -> %d\n", i);
		// printf("here we test t_die -> %ld\n", gbl->philo[i].t_die);
		if (get_time(gbl->philo[i].t_die) > gbl->time_to_die)
		{
			aff_msg(get_time(gbl->philo[i].t_start), gbl->philo[i].id + 48,
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
