/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esduman <esduman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:16:35 by esduman           #+#    #+#             */
/*   Updated: 2025/08/20 23:16:35 by esduman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int calculator(char c, int count, ...)
{
	va_list	calc;
	int		res;
	int		i;
	int		new;

	va_start(calc, count);
	res = va_arg(calc, int);
	i = 1;
	while (i < count)
	{
		new = va_arg(calc, int);
		if (c == '+')
			res += new;
		else if (c == '-')
			res -= new;
		else if (c == '*')
			res *= new;
		else if (c == '/')
		{
			if (new == 0)
			{
				va_end(calc);
				return (res);
			}
			res /= new;
		}
		i++;
	}

	va_end(calc);
	return (res);
}

int	main(void)
{
	ft_printf("%d\n", calculator('-', 3, 10, 20, 30));
	return (0);
}
