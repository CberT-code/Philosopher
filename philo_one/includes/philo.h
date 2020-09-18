/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:23:34 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/18 19:06:24 by cbertola         ###   ########.fr       */
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
    int                 id;
	long int			t_die;
	int					eat;
    struct s_gbl        *gbl;
    pthread_mutex_t     lock;

}						t_philo;

typedef struct			s_gbl
{
    int                 is_dead;
    int                 maxphilo;
    int                 thread;
    long int			t_start;
    long int            t_to_die;
    long int            t_to_eat;
    long int            t_to_sleep;
    long int            dead_time;
    int                 max_eat;
    t_philo             *philo;
    pthread_mutex_t     *m_forks;
    pthread_mutex_t     wait;
    pthread_mutex_t     talk;
}						t_gbl;

int                             ft_strlen(char *str);
void                            ft_putstr_fd(char *str, int fd);
unsigned long long              ft_atoi(const char *str);
void	                        ft_bzero(void *s, size_t n);
void                            *ft_calloc(size_t n, size_t size);
void		                    aff_msg(long int nb, int id, char *str2, int fd);

void                            *ft_start(void *gbl);
void                            ft_messages(t_philo *philo, long int time, t_gbl *gbl, char *message);
void                            ft_messages_dead(t_philo *philo, long int time, t_gbl *gbl, char *message);

long int                        get_time(long int type);
void                            osleep(long int time);


t_philo		                    *find_philo(int id, t_gbl *gbl);

void		                    monitoring(t_gbl *gbl);

int                             free_all(t_gbl *gbl);

void		                    *monitor(void *args);
#endif