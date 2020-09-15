/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:27:38 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/15 05:06:56 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    ft_messages(t_philo *philo, long int timestamp, t_gbl *gbl, char *message)
{
    if (pthread_mutex_lock(&gbl->talk) == 0)
    {
        ft_putnbr_fd(timestamp, 1);
        ft_putstr_fd(" ", 1);
        ft_putnbr_fd(philo->id, 1);
        ft_putstr_fd(" ", 1);
        ft_putstr_fd(message, 1);
        ft_putstr_fd("\n", 1);
        pthread_mutex_unlock(&gbl->talk);
    }
}

void    ft_eat(t_philo *philo, long int timestamp, t_gbl *gbl, char *message)
{
    int i;

    i = 0;
    i = (philo->id == 0) ? gbl->maxphilo - 1 : -1 ;
    if (pthread_mutex_lock(&gbl->m_forks[philo->id]) == 0 &&
    pthread_mutex_lock(&gbl->m_forks[philo->id + i]) == 0)
    {
        philo->t_die = get_time(0);
        ft_messages(philo, timestamp, gbl, message);
        osleep(gbl->time_to_eat);
        pthread_mutex_unlock(&gbl->m_forks[philo->id]);
        pthread_mutex_unlock(&gbl->m_forks[philo->id + i]);
    }
}

void    ft_sleep(t_philo *philo, long int timestamp, t_gbl *gbl, char *message)
{
        ft_messages(philo, timestamp, gbl, message);
        osleep(gbl->time_to_sleep);
}

void        *ft_start(void *args)
{
	t_gbl 		*gbl;
    t_philo     *philo;
	long int    stime;
    int         id;

	gbl = (t_gbl *)args;
    id = gbl->thread;
    philo = find_philo(id, gbl);
	ft_messages(philo, 0, gbl, "was created");
	stime = get_time(0);
	while (philo->is_dead == 0)
	{
		ft_eat(philo, get_time(stime), gbl, "IS EATING");
		ft_sleep(philo, get_time(stime), gbl, "IS SLEEPING");
        ft_messages(philo, 0, gbl, "IS THINKING");
        philo->t_die += gbl->time_to_eat + gbl->time_to_sleep;
	}
	return (gbl);
}