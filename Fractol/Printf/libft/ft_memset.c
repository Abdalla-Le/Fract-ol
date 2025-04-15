/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:51:04 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/09 15:30:26 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_char;

	s_char = (unsigned char *) s;
	while (n--)
	{
		*s_char = c;
		s_char++;
	}
	return (s);
}
/*
#include <stdio.h>

int main()
{
	char ptr2[5] = "lele";
	printf("%s",(char *)ft_memset(ptr2,'0',1));
	return (0);
}*/
