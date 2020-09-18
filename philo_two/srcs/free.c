/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:03:20 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/18 21:53:11 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int        free_all(t_gbl *gbl)
{
    int                 i;

    i = 0;

    // pthread_mutex_destroy(&gbl->talk);
    // pthread_mutex_destroy(&gbl->m_isdead);
    while (i < gbl->maxphilo)
    {
        pthread_mutex_destroy(&gbl->m_forks[i]);
        i++;
    }
        free(gbl->m_forks);
        free(gbl->philo);
        //free(&gbl->m_philo[i]);
        //free(&gbl->m_forks[i]);
    return (1);
}