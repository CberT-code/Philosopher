/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:03:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/18 22:09:23 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		*monitor(void *args)
{
	t_philo		*philo;

	philo = (t_philo*)args;
	while (philo->gbl->is_dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if ((get_time(philo->t_die) > philo->gbl->t_to_die || 
		philo->gbl->nb_max_eat == philo->gbl->maxphilo) && philo->gbl->is_dead == 0)
		{
			philo->gbl->is_dead = 1;
			if (philo->gbl->nb_max_eat != philo->gbl->maxphilo)
				ft_messages_dead(philo, get_time(philo->gbl->t_start), philo->gbl, "IS DEAD");
			return (philo);
		}
		pthread_mutex_unlock(&philo->lock);
		osleep(1);
	}
	return (philo);
}