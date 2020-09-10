/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:21:06 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/10 15:23:18 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int                             ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (fd < 0 || !str)
		return ;
        write(fd, str, ft_strlen(str));

}

unsigned long long              ft_atoi(const char *str)
{
        unsigned long long result;

        result = 0;
        while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' ||
                        *str == '\r' || *str == 32)
                str++;
        while (*str >= 48 && *str <= 57)
        {
                result *= 10;
                result += (*str - 48);
                str++;
        }
        return (result);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *i;

	i = (unsigned char *)s;
	while (n-- > 0)
	{
		*i = '\0';
		i++;
	}
}

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
