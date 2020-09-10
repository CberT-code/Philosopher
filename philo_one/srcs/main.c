/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:03:20 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/10 13:26:59 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int        init_gbl(int argc, char **argv, t_gbl *gbl)
{
    ft_bzero(&gbl, sizeof(t_gbl));
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

void        start_prog(t_gbl *gbl)
{
    int         i;
    pthread_t   pid;

    i = 0;
    while (i < gbl->maxphilo)
    {
        // if (pthread_mutex_lock(&gbl->talk) == 0)
        // {
            pthread_create(&pid, NULL, &ft_start, gbl);
        //     sleep(20);
        //     pthread_mutex_unlock(&gbl->talk);
        // }
        i++;
    }
}

int         main(int argc, char **argv)
{
    t_gbl gbl;
    
    if (argc == 5 || argc == 6)
    {
        if (init_gbl(argc, argv, &gbl) == 0)
            return (0);
        start_prog(&gbl);
    }
    else if (argc < 5)
        ft_putstr_fd("More arguments needed\n", 2);
    else
        ft_putstr_fd("Too much arguments\n", 2);
    return (1);
}