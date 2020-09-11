/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:21:06 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/11 13:23:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
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

t_philos	*ft_philosnew(int id, long int t_die)
{
	t_philos *philos;

	philos = calloc(1, sizeof(t_philos));
	philos->next = NULL;
	return (philos);
}

t_philos	*ft_philoslast(t_philos *philos)
{
	if (!philos)
		return (NULL);
	while (philos->next)
		philos = philos->next;
	return (philos);
}

void	ft_philosadd_back(t_philos **aphilos, int id, long int t_die)
{
	if (*aphilos != NULL)
		ft_philoslast(*aphilos)->next = ft_philosnew(id, t_die);
	else
		*aphilos = ft_philosnew(id, t_die);
}

