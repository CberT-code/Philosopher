/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:23:34 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/10 17:36:28 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

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
    int                 thread;
    long int            time_die;
    long int            time_eat;
    long int            time_sleep;
    int                 max_eat;
    t_philo             *philo;
    pthread_mutex_t     mutex;
}						t_gbl;

int                             ft_strlen(char *str);
void                            ft_putstr_fd(char *str, int fd);
unsigned long long              ft_atoi(const char *str);
void	                        ft_bzero(void *s, size_t n);
void	                        ft_putnbr_fd(int n, int fd);

void                            *ft_start(void *gbl);

long int                        get_time(long int type);

#endif