/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esduman <esduman@student.42.istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:46:05 by esduman           #+#    #+#             */
/*   Updated: 2025/07/27 16:46:05 by esduman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex(unsigned int c, int mod)
{
    char	*hex;
    int		i;
	
	i = 0;
	if (mod)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if(c >= 16)
		i += ft_puthex(c / 16, mod);
	i += ft_putchar(hex[c % 16]);
	return (i);
}

static int	ft_putptr_rec(unsigned long n)
{
	char	*hex = "0123456789abcdef";
	int		i = 0;

	if (n >= 16)
		i += ft_putptr_rec(n / 16);
	i += ft_putchar(hex[n % 16]);
	return (i);
}

int ft_putptr(void *ptr)
{
	int	i;

	if (!ptr)
		return (ft_putstr("(nil)"));
	i = ft_putstr("0x");
	return (i + ft_putptr_rec((unsigned long)ptr));
}

