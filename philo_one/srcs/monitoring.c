/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:03:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/18 13:27:34 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// MONITORING SANS THREAD //


void		*monitoring(void *args)
{
	t_philo		*philo;
	long int 	toto;

	philo = (t_philo *)args;
	while (1)
	{
		if (((toto = get_time(philo->t_die)) > philo->gbl->time_to_die)
		&& philo->gbl->is_dead == -1 )
		{
			philo->gbl->is_dead = philo->id;
			pthread_mutex_lock(&philo->gbl->talk);
			// pthread_mutex_destroy(&philo->gbl->talk);
			ft_messages_dead(philo, get_time(philo->gbl->t_start), philo->gbl, "\033[1;31mIS DEAD\033[0;0m");
			pthread_mutex_unlock(&philo->gbl->m_isdead);

			return (philo);
		}
		osleep(1);
	}
	return (philo);
}