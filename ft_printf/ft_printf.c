/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:51:16 by akalican          #+#    #+#             */
/*   Updated: 2023/11/16 18:31:51 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_convert(va_list args, const char format)
{
	int				length_print;
	unsigned int	hex;

	length_print = 0;
	if (format == 'c')
		length_print += ft_putchar(va_arg(args, int));
	else if (format == 's')
		length_print += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		length_print += ft_printnbr(va_arg(args, int));
	else if (format == 'p')
		length_print += ft_ptr_print(va_arg(args, unsigned long long));
	else if (format == 'x' || format == 'X')
	{
		hex = va_arg(args, unsigned int);
		length_print += ft_print_hex(hex, format);
	}
	else if (format == 'u')
		length_print += print_unsigned(va_arg(args, unsigned int));
	else if (format == '%')
		length_print += ft_print_precentage();
	return (length_print);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len += ft_convert(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/*
int	main(void)
{
	unsigned int	nb;
	int				num;
	char			*str;
	int				ptr;
	int				*point;

	str = "";
	num = 23398734;
	nb = 15123123;
	ptr = 23398734;
	point = &ptr;
	// printf("return value is : %d\n", ft_printf("%d\n", 19));
	ft_printf("%p \n", 16);
	printf("%p\n", 16);
}
*/