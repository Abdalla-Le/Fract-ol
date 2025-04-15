/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:40:29 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/09 15:26:05 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_char;
	size_t			i;

	s_char = (unsigned char *) s;
	if (c == 0 && n == 0)
		return (NULL);
	i = 0;
	while (n > i)
	{
		if (s_char[i] == (unsigned char)c)
			return ((void *)s_char + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main ()
{
	const char s[] = "leticia";
        char c = 'i';
        printf("%p",(char*)ft_memchr(s, c, 7));
        return (0);
}
*/
