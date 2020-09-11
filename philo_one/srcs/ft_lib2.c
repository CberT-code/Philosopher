/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:21:06 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/11 14:27:11 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	long int nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(((nbr % 10) + '0'), fd);
	}
	else
		ft_putchar_fd((nbr + '0'), fd);
}

t_philo		*ft_philosnew(int id, long int t_die)
{
	t_philo *philos;

	philos = ft_calloc(1, sizeof(t_philo));
	philos->id = id;
	philos->t_die = t_die;
	philos->next = NULL;
	return (philos);
}

t_philo		*ft_philoslast(t_philo *philos)
{
	if (!philos)
		return (NULL);
	while (philos->next)
		philos = philos->next;
	return (philos);
}

void		ft_philosadd_back(t_philo **aphilos, int id, long int t_die)
{
	if (*aphilos != NULL)
		ft_philoslast(*aphilos)->next = ft_philosnew(id, t_die);
	else
		*aphilos = ft_philosnew(id, t_die);
}

t_philo		*find_philo(int id, t_gbl *gbl)
{
	t_philo	*philo;

	philo = gbl->philo;
	while (id != philo->id)
	{
		philo = philo->next;
	}
	return (philo);
}