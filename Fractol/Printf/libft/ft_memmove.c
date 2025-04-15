/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:03:51 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/09 15:29:33 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_char;
	const unsigned char	*src_char;

	dest_char = (unsigned char *) dest;
	src_char = (const unsigned char *) src;
	if (dest > src)
	{
		while (n--)
		{
			dest_char[n] = src_char[n];
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
/*
#include <string.h>
int main()
{
	char dest[10] = "abdalele";
	char *src = "lele";
	size_t n = 4;

	printf("%s", (char *) ft_memmove(dest, src, n));
	//printf("%s", (char*)memmove(dest, src, n));
	//printf("%s", (char*)memcpy(dest, src, n));
	return 0;
}*/
