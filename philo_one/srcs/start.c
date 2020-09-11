/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:27:38 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/11 13:01:52 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    ft_messages(int id, long int timestamp, t_gbl *gbl, char *message)
{
    if (pthread_mutex_lock(&gbl->talk) == 0)
    {
        ft_putnbr_fd(timestamp, 1);
        ft_putstr_fd(" ", 1);
        ft_putnbr_fd(id, 1);
        ft_putstr_fd(" ", 1);
        ft_putstr_fd(message, 1);
        ft_putstr_fd("\n", 1);
        pthread_mutex_unlock(&gbl->talk);
    }
}

void    ft_eat(int id, long int timestamp, t_gbl *gbl, char *message)
{
    int i;

    i = 0;
    i = (id == 0) ? gbl->maxphilo - 1 : -1 ;
    if (pthread_mutex_lock(&gbl->m_forks[id]) == 0 &&
    pthread_mutex_lock(&gbl->m_forks[id + i]) == 0)
    {
        ft_messages(id, timestamp, gbl, message);
        osleep(gbl->time_eat);
        pthread_mutex_unlock(&gbl->m_forks[id]);
        pthread_mutex_unlock(&gbl->m_forks[id + i]);
    }
}

void    ft_sleep(int id, long int timestamp, t_gbl *gbl, char *message)
{
        ft_messages(id, timestamp, gbl, message);
        osleep(gbl->time_sleep);
}

void        *ft_start(void *args)
{
	t_gbl 		*gbl;
	long int    stime;
    int         id;

	gbl = (t_gbl *)args;
    id = gbl->thread;
	ft_messages(id, 0, gbl, "was created");
	stime = get_time(0);
	while (1)
	{
		ft_eat(id, get_time(stime), gbl, "IS EATING");
		ft_sleep(id, get_time(stime), gbl, "IS SLEEPING");
        ft_messages(id, 0, gbl, "IS THINKING");
        osleep(100);
	}
	return (gbl);
}