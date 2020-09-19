/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:03:20 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/19 12:23:06 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		free_all(t_gbl *gbl)
{
	int	i;

	i = 0;
	while (i < gbl->maxphilo)
	{
		pthread_mutex_destroy(&gbl->m_forks[i]);
		i++;
	}
	pthread_mutex_destroy(&gbl->wait);
	pthread_mutex_destroy(&gbl->talk);
	free(gbl->m_forks);
	free(gbl->philo);
	return (1);
}
