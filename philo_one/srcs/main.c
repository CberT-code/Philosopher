/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:03:20 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/10 18:27:00 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int        init_gbl(int argc, char **argv, t_gbl *gbl)
{
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
    // pthread_mutex_t     mutex[gbl->maxphilo];
    // int                 i;

    // gbl->mutex = mutex;
    // i = 0;
    // while (i < gbl->maxphilo)
    // {
        pthread_mutex_init(&gbl->mutex, NULL);
	    pthread_mutex_unlock(&gbl->mutex);
    //     i++;
    // }
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
        gbl->thread += 1;
        usleep(200);
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
        while(1);
    }
    else if (argc < 5)
        ft_putstr_fd("More arguments needed\n", 2);
    else
        ft_putstr_fd("Too much arguments\n", 2);
    return (1);
}