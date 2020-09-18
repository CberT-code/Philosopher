/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:27:38 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/18 19:27:57 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    ft_messages_dead(t_philo *philo, long int time, t_gbl *gbl, char *message)
{
    if (pthread_mutex_lock(&gbl->talk) == 0)
    {
        aff_msg(time, philo->id, message, 1);
    }
}

void    ft_messages2(t_philo *philo, long int time, t_gbl *gbl, char *message)
{
    if (pthread_mutex_lock(&gbl->talk) == 0)
    {
        aff_msg(time, philo->id, "has taken a fork", 1);
        aff_msg(time, philo->id, message, 1);
    }
        pthread_mutex_unlock(&gbl->talk);
}

void    ft_messages(t_philo *philo, long int time, t_gbl *gbl, char *message)
{
    if (pthread_mutex_lock(&gbl->talk) == 0)
    {
        aff_msg(time, philo->id + 1, message, 1);
    }
        pthread_mutex_unlock(&gbl->talk);
}

void    ft_eat(t_philo *philo, t_gbl *gbl, char *message)
{
    int i;

    i = (philo->id == 0) ? gbl->maxphilo - 1 : -1 ;
    if (pthread_mutex_lock(&gbl->m_forks[philo->id + i]) == 0)
    {
        ft_messages(philo, get_time(gbl->t_start), gbl, "has taken a fork");
        if (pthread_mutex_lock(&gbl->m_forks[philo->id]) == 0)
        {
            pthread_mutex_lock(&philo->lock);
            ft_messages2(philo, get_time(gbl->t_start), gbl, message);
            philo->t_die = get_time(0);
            philo->eat += 1;
            osleep(gbl->t_to_eat);
            pthread_mutex_unlock(&gbl->m_forks[philo->id]);
            pthread_mutex_unlock(&gbl->m_forks[philo->id + i]);
            pthread_mutex_unlock(&philo->lock);
        }
    }
}

void    ft_sleep(t_philo *philo, t_gbl *gbl, char *message)
{
        ft_messages(philo, get_time(gbl->t_start), gbl, message);
        osleep(gbl->t_to_sleep);
}

void        *ft_start(void *args)
{
    t_philo     *philo;
    pthread_t   t_monitor;
    t_gbl       *gbl;

	philo = (t_philo *)args;
    gbl = philo->gbl;
	philo->t_die = get_time(0);
    if (pthread_create(&t_monitor, NULL, &monitor, philo) != 0)
		return ((void*)1);
	pthread_detach(t_monitor);
	ft_messages(philo, get_time(gbl->t_start), philo->gbl, "was created");
	while (philo->gbl->is_dead == 0)
	{
		ft_eat(philo, gbl, "is eating");
		ft_sleep(philo, gbl, "is sleeping");
        ft_messages(philo, get_time(gbl->t_start), gbl, "is thinking");
	}
	return (gbl);
}