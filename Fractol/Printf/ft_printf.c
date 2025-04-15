/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 07:58:43 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/25 12:15:19 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(va_list args, int letter)
{
	int	houses;

	if (letter == 'c')
		houses = is_char(va_arg(args, int));
	if (letter == 's')
		houses = is_str(va_arg(args, char *));
	if (letter == 'p')
		houses = is_ptr(va_arg(args, void *));
	if (letter == 'd')
		houses = is_dec(va_arg(args, int));
	if (letter == 'i')
		houses = is_int(va_arg(args, int));
	if (letter == 'u')
		houses = is_uns(va_arg(args, unsigned int));
	if (letter == 'x')
		houses = is_x(va_arg(args, unsigned int));
	if (letter == 'X')
		houses = is_x_upper(va_arg(args, unsigned int));
	if (letter == '%')
		houses = is_char('%');
	return (houses);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		houses;
	va_list	args;

	va_start(args, s);
	houses = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("scpudiXx%", s[i + 1]))
		{
			i++;
			houses += conversion(args, s[i]);
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			houses++;
		}
		i++;
	}
	va_end(args);
	return (houses);
}
