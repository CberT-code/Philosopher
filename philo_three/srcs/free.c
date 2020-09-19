/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:03:20 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/19 21:13:33 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		free_all(t_gbl *gbl)
{
	int		i;
	char	res[50];
	char	str[50];

	i = 0;
	while (i < gbl->maxphilo)
	{
		res[ft_nb_to_char(res, str, i)] = '\0';
		sem_unlink(res);
		i++;
	}
	sem_unlink("Sem_Talk");
	sem_unlink("Sem_Wait");
	sem_unlink("Sem_Fork");
	free(gbl->philo);
	return (1);
}
