/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasgjertsenkalicani <andreasgjertse    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:34:11 by andreasgjer       #+#    #+#             */
/*   Updated: 2023/11/10 16:23:00 by andreasgjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

static int	size_str(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	tmp;
	char			*str;

	len = size_str(n);
	tmp = n;
	if (n < 0)
	{
		len++;
		tmp = -tmp;
	}
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		str[len - 1] = tmp % 10 + '0';
		tmp = tmp / 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
