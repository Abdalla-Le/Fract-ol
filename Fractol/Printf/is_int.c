/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:43:23 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/25 12:05:39 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	houses_dec(int nb)
{
	int	houses;

	houses = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		houses++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		houses++;
	}
	return (houses);
}

int	is_dec(int nb)
{
	int	houses;

	ft_putnbr_fd (nb, 1);
	if (nb == 0)
		return (1);
	houses = houses_dec(nb);
	return (houses);
}

int	is_int(int nb)
{
	int	houses;

	ft_putnbr_fd(nb, 1);
	if (nb == 0)
		return (1);
	houses = houses_dec (nb);
	return (houses);
}
