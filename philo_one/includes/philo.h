/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:23:34 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/10 13:19:47 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

typedef struct			s_philo
{
    int                 num;
	long int			time_die;
    long int            time_eat;
	long int			time_sleep;
	int					eat;
    struct s_philo      *next;
}						t_philo;

typedef struct			s_gbl
{
    int                 maxphilo;
    long int            time_die;
    long int            time_eat;
    long int            time_sleep;
    int                 max_eat;
    t_philo             *philo;
    pthread_mutex_t     talk;
}						t_gbl;

int                             ft_strlen(char *str);
void                            ft_putstr_fd(char *str, int fd);
unsigned long long              ft_atoi(const char *str);
void	                        ft_bzero(void *s, size_t n);

void                            *ft_start(void *gbl);

#endif