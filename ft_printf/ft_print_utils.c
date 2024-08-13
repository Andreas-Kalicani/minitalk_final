/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:53:26 by akalican          #+#    #+#             */
/*   Updated: 2024/04/23 14:48:15 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int	t;

	t = n;
	if (t < 0)
	{
		t *= -1;
		ft_putchar_fd('-', fd);
	}
	if (t > 9)
	{
		ft_putnbr_fd((t / 10), fd);
		ft_putchar_fd((t % 10 + '0'), fd);
	}
	else
		ft_putchar_fd((t + '0'), fd);
}

int	ft_printnbr(int nb)
{
	int	len;
	int	n;

	n = nb;
	len = 1;
	if (n < 0 && n != -2147483648)
	{
		n = -nb;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	ft_putnbr_fd(nb, 1);
	if (nb == -2147483648)
		return (11);
	return (len);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
