/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:03:20 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/11 13:03:32 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int        init_gbl(int argc, char **argv, t_gbl *gbl)
{
    pthread_mutex_init(&gbl->talk, NULL);
    pthread_mutex_unlock(&gbl->talk);
    if ((gbl->maxphilo = ft_atoi(argv[1])) == 0 ||
    (gbl->time_die = ft_atoi(argv[2])) == 0 ||
    (gbl->time_eat = ft_atoi(argv[3])) == 0 ||
    (gbl->time_sleep = ft_atoi(argv[4])) == 0 ||
    (argc == 6 && (gbl->max_eat = ft_atoi(argv[5])) == 0))
    {
        ft_putstr_fd("WRONG ARGUMENT\n", 2);
        return (0);
    }
    return (1);
}

int        init_mutex(t_gbl *gbl)
{
    pthread_mutex_t     *philo;
    pthread_mutex_t     *forks;
    int                 i;

    philo = ft_calloc(gbl->maxphilo + 1, sizeof(pthread_mutex_t));
    forks = ft_calloc(gbl->maxphilo + 1, sizeof(pthread_mutex_t));
    i = 0;
    while (i < gbl->maxphilo)
    {
        pthread_mutex_init(&philo[i], NULL);
        pthread_mutex_init(&forks[i], NULL);
        if (i == 0)
            pthread_mutex_unlock(&philo[i]);
        if (i != 0)
	        pthread_mutex_lock(&philo[i]);
	    pthread_mutex_unlock(&forks[i]);
        i++;
    }
    gbl->m_philo = philo;
    gbl->m_forks = forks;
    return (1);
}

void        init_philo(t_gbl *gbl)
{
    pthread_t   thread;

    gbl->thread = 0;
    while (gbl->thread < gbl->maxphilo)
    {
        if (pthread_create(&thread, NULL, ft_start, gbl) != 0)
            return ;
        pthread_detach(thread);
        osleep(10);
        gbl->thread += 1;
    }
}

int         main(int argc, char **argv)
{
    t_gbl gbl;
    
    if (argc == 5 || argc == 6)
    {
        if (init_gbl(argc, argv, &gbl) == 0)
            return (0);
        init_mutex(&gbl);
        init_philo(&gbl);
        monitoring(&gbl);
        while (1);
    }
    else if (argc < 5)
        ft_putstr_fd("More arguments needed\n", 2);
    else
        ft_putstr_fd("Too much arguments\n", 2);
    return (1);
}