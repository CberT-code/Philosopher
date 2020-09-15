/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:21:06 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/15 08:25:41 by cbertola         ###   ########.fr       */
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
char		*nbr_to_char_fd(long int n)
{
	int 	i;
	char	*str;

	str = ft_calloc(size_int(n), sizeof(char));
	i = size_int(n);
	str[size_int(n)] = '\0';
	while (i-- >= 0)
	{
		str[i] = i != 0 ? ((n % 10) + '0') : n + '0';
    	n = (n / 10);
	}
	return (str);
}

void		aff_msg(long int nb, char c, char *str2, int fd)
{
	int 	i;
	char 	res[size_int(nb) + 3 + ft_strlen(str2)];
	char	str[size_int(nb)];

	i = size_int(nb);
	str[size_int(nb)] = '\0';
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