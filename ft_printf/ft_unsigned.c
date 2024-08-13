/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:11:05 by akalican          #+#    #+#             */
/*   Updated: 2023/11/15 12:12:42 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_unsigned_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void	ft_print_u(unsigned int nb)
{
	if (nb > 9)
		print_unsigned(nb / 10);
	if (nb <= 9)
	{
		ft_putchar_fd(nb + 48, 1);
		return ;
	}
	ft_putchar_fd((nb % 10) + 48, 1);
}

int	print_unsigned(unsigned int nb)
{
	unsigned int	i;

	ft_print_u(nb);
	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_print_precentage(void)
{
	write(1, "%", 1);
	return (1);
}
