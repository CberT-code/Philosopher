/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:24:00 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/19 15:47:53 by cbertola         ###   ########.fr       */
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
	if (sem_wait(gbl->talk) == 0)
	{
		aff_msg(time, philo->id + 1, msg, 1);
		sem_post(gbl->wait);
	}
}

void		osleep(long int time)
{
	long int	start;

	start = get_time(0);
	while (get_time(start) < time)
		usleep(1);
}
