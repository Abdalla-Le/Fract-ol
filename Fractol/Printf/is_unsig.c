/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_unsig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:43:25 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/25 12:07:26 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	houses_unsig(unsigned int nb)
{
	int	houses;

	houses = 0;
	while (nb > 0)
	{
		nb /= 10;
		houses++;
	}
	return (houses);
}

void	ft_putnbr_u(unsigned int n)
{
	if (n < 10)
	{
		n += 48;
		write (1, &n, 1);
	}
	else
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
}

int	is_uns(unsigned int nb)
{
	int	houses;

	ft_putnbr_u(nb);
	if (nb == 0)
		return (1);
	houses = houses_unsig(nb);
	return (houses);
}
