/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:03:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/20 10:08:48 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		*monitor(void *args)
{
	t_philo		*philo;
	t_gbl		*gbl;

	philo = (t_philo*)args;
	gbl = philo->gbl;
	while (gbl->is_dead == 0)
	{
		sem_wait(philo->lock);
		if ((get_time(philo->t_die) > gbl->t_to_die ||
		gbl->nb_max_eat == gbl->maxphilo) &&
		gbl->is_dead == 0)
		{
			gbl->is_dead = 1;
			if (gbl->nb_max_eat != gbl->maxphilo)
				ft_msg_dead(philo, get_time(gbl->t_start), gbl, "died");
			sem_post(gbl->wait);
			return (philo);
		}
		sem_post(philo->lock);
		osleep(1);
	}
	return (philo);
}
