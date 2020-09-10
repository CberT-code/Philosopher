/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:27:38 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/10 18:28:37 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    ft_messages(int id, long int timestamp, t_gbl *gbl, char *message)
{
    if (pthread_mutex_lock(&gbl->mutex) == 0)
    {
        ft_putnbr_fd(timestamp, 1);
        ft_putstr_fd(" ", 1);
        ft_putnbr_fd(id, 1);
        ft_putstr_fd(" ", 1);
        ft_putstr_fd(message, 1);
        ft_putstr_fd("\n", 1);
        pthread_mutex_unlock(&gbl->mutex);
    }
}

void        *ft_start(void *args)
{
	t_gbl 		*gbl;
	long int    stime;
    int         id;

	gbl = (t_gbl *)args;
    id = gbl->thread;
	ft_messages(id, 0, gbl, "was launch");
	stime = get_time(0);
	while (1)
	{
		ft_messages(id, get_time(stime), gbl, "CHECK !!");
        usleep(100);
	}
	return (gbl);
}