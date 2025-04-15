/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:51:02 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/11 11:54:32 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == 0)
	{
		return ((char *)s + ft_strlen(s));
	}
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	const char s[] = "leticia";
        char c = 'i';
        printf("%s\n",ft_strrchr(s, c));
		printf("%s",strrchr(s, c));
        return (0);

}*/
