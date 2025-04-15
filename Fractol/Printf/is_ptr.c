/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:43:12 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/25 12:06:29 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_adress(unsigned long nb)
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
		ft_putnbr_adress(nb / 16);
		ft_putnbr_adress(nb % 16);
	}
}

int	houses_adress(unsigned long nb)
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

int	is_ptr(void *ptr)
{
	int				houses;
	unsigned long	new_num_ptr;

	new_num_ptr = (unsigned long)ptr;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_putnbr_adress(new_num_ptr);
	houses = houses_adress(new_num_ptr) + 2;
	return (houses);
}
