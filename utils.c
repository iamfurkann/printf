/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esduman <esduman@student.42.istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:37:16 by esduman           #+#    #+#             */
/*   Updated: 2025/07/27 16:37:16 by esduman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *c)
{
	int	i;

	if (!c)
		return (write(1, "(null)", 6));
	i = 0;
	while (*c)
		i += write(1, c++, 1);
	return (i);
}

int	ft_putnbr(int c)
{
	int		i;
	long	nb;

	i = 0;
	nb = c;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		i += ft_putnbr(nb / 10);
	i += ft_putchar((nb % 10) + '0');
	return (i);
}

int	ft_putnbru(unsigned int c)
{
	int	i;

	i = 0;
	if (c >= 10)
		i += ft_putnbru(c / 10);
	i += ft_putchar((c % 10) + '0');
	return (i);
}
