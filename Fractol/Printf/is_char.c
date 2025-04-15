/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:43:50 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/25 12:08:48 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_char(int c)
{
	int	num;

	num = 1;
	write (1, &c, 1);
	return (num);
}

int	is_str(char *str)
{
	int	num;

	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	num = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (num);
}
