/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:03:20 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/16 13:05:59 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int        init_gbl(int argc, char **argv, t_gbl *gbl)
{
    pthread_mutex_init(&gbl->talk, NULL);
    pthread_mutex_unlock(&gbl->talk);
    gbl->is_dead = 0;
    if ((gbl->maxphilo = ft_atoi(argv[1])) == 0 ||
    (gbl->time_to_die = ft_atoi(argv[2])) == 0 ||
    (gbl->time_to_eat = ft_atoi(argv[3])) == 0 ||
    (gbl->time_to_sleep = ft_atoi(argv[4])) == 0 ||
    (argc == 6 && (gbl->max_eat = ft_atoi(argv[5])) == 0))
    {
        ft_putstr_fd("WRONG ARGUMENT\n", 2);
        return (0);
    }
    return (1);
}

int        init_mutex(t_gbl *gbl)
{  
    int                 i;

    gbl->philo = NULL;
    i = 0;

    gbl->m_philo = ft_calloc(sizeof(pthread_mutex_t ), gbl->maxphilo);
    gbl->m_forks = ft_calloc(sizeof(pthread_mutex_t ), gbl->maxphilo);
    gbl->philo = ft_calloc(sizeof(t_philo), gbl->maxphilo);
    while (i < gbl->maxphilo)
    {
        pthread_mutex_init(&gbl->m_philo[i], NULL);
        pthread_mutex_init(&gbl->m_forks[i], NULL);
        if (i == 0)
            pthread_mutex_unlock(&gbl->m_philo[i]);
        if (i != 0)
	        pthread_mutex_lock(&gbl->m_philo[i]);
	    pthread_mutex_unlock(&gbl->m_forks[i]);
        ft_bzero(&gbl->m_philo[i], sizeof(t_philo));
        gbl->philo[i].id = i;
        gbl->philo[i].t_start = -1;
        i++;
    }
    return (1);
}

void        init_philo(t_gbl *gbl)
{
    pthread_t   thread[gbl->maxphilo];

    gbl->thread = 0;
    while (gbl->thread < gbl->maxphilo)
    {
        if (pthread_create(&thread[gbl->thread], NULL, ft_start, gbl) != 0)
            return ;
        pthread_detach(thread[gbl->thread]);
        osleep(1);
        gbl->thread += 1;
    }
}

int         main(int argc, char **argv)
{
    t_gbl   gbl;
    
    if (argc == 5 || argc == 6)
    {
        if (init_gbl(argc, argv, &gbl) == 0)
            return (0);
        init_mutex(&gbl);
        init_philo(&gbl);
        monitoring(&gbl);
    }
    else if (argc < 5)
        ft_putstr_fd("More arguments needed\n", 2);
    else
        ft_putstr_fd("Too much arguments\n", 2);
    return (1);
}