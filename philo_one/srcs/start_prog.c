/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:27:38 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/10 13:29:10 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void        *ft_start(void *gbl)
{
	t_gbl *infos;

	infos = (t_gbl *)gbl;

	if (pthread_mutex_lock(&infos->talk) == 0)
	{
		printf("toto\n");
		sleep(1);
		pthread_mutex_unlock(&infos->talk);
	}
	return (gbl);
}