/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:03:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/11 15:03:20 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		monitoring(t_gbl *gbl)
{
	t_philo		*philo;

	philo = gbl->philo;
	while (philo && philo->t_die > 0)
	{
		printf("here we test -> %d\n", philo->id);
		printf("here we test -> %ld\n", get_time(philo->t_die));
		if (get_time(philo->t_die) > gbl->time_to_die)
			return (philo->id);
		philo = philo->next;
		if (philo == NULL)
			philo = gbl->philo;
	}
	return (0);
}
