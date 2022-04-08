/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:37:43 by mmanouze          #+#    #+#             */
/*   Updated: 2022/04/08 16:00:33 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnchar(char c)
{
	write(1, &c, 1);
}

void	print_num(const char *c, va_list ap)
{
	long int	d;

	if (*c == 'd')
	{
		d = va_arg(ap, int);
		ft_putnbr(d);
	}
}

void	ft_putnbr(long int n)
{
	int	x;

	x = 1;
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putnchar('-');
			n *= -1;
		}
		while (x <= (n / 10))
		{
			x *= 10;
		}
		while (x > 0)
		{
			ft_putnchar(((n / x) + '0'));
			n = n % x;
			x /= 10;
		}
	}
}

void	check_after(const char *c, va_list ap)
{
	if (*c == 'd')
		print_num(c, ap);
}

void	ft_printf(const char *c, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, c);
	while (c[i])
	{
		if (c[i] == '%')
		{
			if (c[i + 1] == 0)
				break ;
			check_after(&c[++i], ap);
		}
		else
			ft_putnchar(c[i]);
		i++;
	}
	va_end(ap);
}
