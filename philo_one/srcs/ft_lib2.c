/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:21:06 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/15 14:04:42 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int			size_int(long int nb)
{
	int i;

	i = 0;
	while ((nb = nb / 10) > 0)
		i++;
	return (++i);
}

void		aff_msg(long int nb, char c, char *str2, int fd)
{
	int 	i;
	char 	res[50];
	char	str[50];

	i = size_int(nb);
	str[i] = '\0';
	while (i-- >= 0)
	{
		str[i] = i != 0 ? ((nb % 10) + '0') : nb + '0';
    	nb = (nb / 10);
	}
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = ' ';
	res[++i] = c;
	res[++i] = ' ';
	while (*str2)
		res[++i] = *str2++;
	res[++i] = '\n';
	res[++i] = '\0';
	write(fd, &res, ft_strlen(res));
}