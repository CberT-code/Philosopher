/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:21:06 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/18 22:34:27 by cbertola         ###   ########.fr       */
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

int			ft_nb_to_char(char *dst, char *src, long int nb)
{
	int i;

	i = size_int(nb);
	src[i] = '\0';
	while (--i >= 0)
	{
		src[i] = i != 0 ? ((nb % 10) + '0') : nb + '0';
		nb = (nb / 10);
	}
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	return (i);
}

void		aff_msg(long int nb, int id, char *str2, int fd)
{
	int 	i;
	char 	res[50];
	char	str[50];

	i = ft_nb_to_char(res, str, nb);
	res[i++] = ' ';
	i += ft_nb_to_char(res + i, str, id);
	res[i++] = ' ';
	while (*str2)
		res[i++] = *str2++;
	res[i++] = '\n';
	res[i] = '\0';
	write(fd, &res, ft_strlen(res));
}