/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:10:43 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/09 15:26:57 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;
	size_t			i;

	s1_c = (unsigned char *) s1;
	s2_c = (unsigned char *) s2;
	i = 0;
	while (n > i)
	{
		if (s1_c[i] != s2_c[i])
		{
			return (s1_c[i] - s2_c[i]);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int	main()
{
	char s1[] = "leticia";
        char s2[] = "leticio";

        size_t n = 7;
        printf("%d",ft_memcmp(s1, s2, n));
        return (0);

}*/
