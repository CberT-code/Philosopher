/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:24:00 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/18 22:59:12 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	get_time(long int type)
{
	long int		time;
	struct timeval	te;

	gettimeofday(&te, NULL);
	if (type == 0)
		time = te.tv_sec * 1000LL + te.tv_usec / 1000;
	else
		time = (te.tv_sec * 1000LL + te.tv_usec / 1000) - type;
	return (time);
}

void		ft_msg_dead(t_philo *philo, long int time, t_gbl *gbl, char *msg)
{
	if (pthread_mutex_lock(&gbl->talk) == 0)
	{
		aff_msg(time, philo->id + 1, msg, 1);
		pthread_mutex_unlock(&philo->gbl->wait);
		pthread_mutex_lock(&gbl->talk);
	}
}

void		osleep(long int time)
{
	long int	start;

	start = get_time(0);
	while (get_time(start) < time)
		usleep(1);
}
