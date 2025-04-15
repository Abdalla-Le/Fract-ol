/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:47:53 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/11 11:59:57 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_mal(int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*mal(size_t size)
{
	char	*s;

	s = (char *)malloc (sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = size_mal(n);
	s = mal(len);
	s[len--] = '\0';
	if (n < 0)
	{
		n *= -1;
		s[0] = '-';
	}
	while (len >= 0)
	{
		if (s[len] == '-' && len == 0)
			break ;
		s[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (s);
}

/*
int main()
{
	int n = -2147483648;
	char *s;
	s = ft_itoa(n);
	printf ("%s", s);
	return (0);
}*/
