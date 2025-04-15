/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:30:10 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/04 14:09:11 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sig;
	int	i;
	int	result;

	i = 0;
	sig = 1;
	result = 0;
	while (nptr[i] <= 32 && nptr[i])
		if (nptr[i++] == '\e')
			return (0);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sig *= -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sig);
}
/*
int     main(void)
{
        char str[] = "-43 02";
        printf("%d \n", ft_atoi(str));
        printf("%d", atoi(str));
        return (0);
}*/
