/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:23:34 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/19 21:13:45 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <time.h>
# include <sys/time.h>
# include <stdlib.h>
# include <semaphore.h>
# include <errno.h>
# include <string.h>

typedef struct					s_philo
{
	int							id;
	long int					t_die;
	int							eat;
	sem_t						*lock;
	struct s_gbl				*gbl;
}								t_philo;

typedef struct					s_gbl
{
	int							is_dead;
	int							maxphilo;
	int							thread;
	int							max_eat;
	int							nb_max_eat;
	long int					t_start;
	long int					t_to_die;
	long int					t_to_eat;
	long int					t_to_sleep;
	long int					dead_time;
	t_philo						*philo;
	sem_t						*s_forks;
	sem_t						*wait;
	sem_t						*talk;
}								t_gbl;

int								ft_strlen(char *str);
void							ft_putstr_fd(char *str, int fd);
unsigned long long				ft_atoi(const char *str);
int								ft_nb_to_char(char *dst, char *src,
long int nb);
void							ft_bzero(void *s, size_t n);
void							*ft_calloc(size_t n, size_t size);
void							aff_msg(long int nb, int id, char *str2,
int fd);
void							*ft_start(void *gbl);
void							ft_msg(t_philo *philo, long int time,
t_gbl *gbl, char *message);
void							ft_msg_dead(t_philo *philo, long int time,
t_gbl *gbl, char *msg);
long int						get_time(long int type);
void							osleep(long int time);
t_philo							*find_philo(int id, t_gbl *gbl);
void							monitoring(t_gbl *gbl);
int								free_all(t_gbl *gbl);
void							*monitor(void *args);
#endif
