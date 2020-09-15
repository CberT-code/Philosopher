/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:03:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/15 08:53:06 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		monitoring(t_gbl *gbl)
{
	int i;

	i = 0;
	while (i < gbl->maxphilo && gbl->is_dead > 0)
	{
		if (get_time(gbl->philo[i].t_die) > gbl->time_to_die)
			return (gbl->philo[i].id);
		i++;
		if (i == gbl->maxphilo)
			i = 0;
	}
	return (0);
}
