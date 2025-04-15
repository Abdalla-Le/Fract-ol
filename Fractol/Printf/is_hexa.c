/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:43:17 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/25 12:00:29 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	houses_hexa(unsigned int nb)
{
	int	houses;

	houses = 0;
	while (nb > 0)
	{
		nb /= 16;
		houses++;
	}
	return (houses);
}

void	ft_putnbrhexa_upper(unsigned int nb)
{
	if (nb < 10)
	{
		nb += '0';
		write(1, &nb, 1);
	}
	else if (nb < 16)
	{
		nb -= 10;
		nb += 'A';
		write(1, &nb, 1);
	}
	else
	{
		ft_putnbrhexa_upper(nb / 16);
		ft_putnbrhexa_upper(nb % 16);
	}
}

void	ft_putnbrhexa_lower(unsigned int nb)
{
	if (nb < 10)
	{
		nb += '0';
		write(1, &nb, 1);
	}
	else if (nb < 16)
	{
		nb -= 10;
		nb += 'a';
		write(1, &nb, 1);
	}
	else
	{
		ft_putnbrhexa_lower(nb / 16);
		ft_putnbrhexa_lower(nb % 16);
	}
}

int	is_x(unsigned int x)
{
	int	new_x;

	ft_putnbrhexa_lower(x);
	if (x == 0)
		return (1);
	new_x = houses_hexa(x);
	return (new_x);
}

int	is_x_upper(unsigned int X)
{
	int	new_x_upper;

	ft_putnbrhexa_upper(X);
	if (X == 0)
		return (1);
	new_x_upper = houses_hexa(X);
	return (new_x_upper);
}
