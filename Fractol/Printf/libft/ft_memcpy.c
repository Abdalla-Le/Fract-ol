/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:41:12 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/09 15:28:54 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_char;
	const unsigned char	*src_char;

	dest_char = (unsigned char *) dest;
	src_char = (const unsigned char *) src;
	while (n > 0)
	{
		*dest_char = *src_char;
		dest_char++;
		src_char++;
		n--;
	}
	return (dest);
}
/*
#include <string.h>
int main()
{
	char  dest[10] = "abdallele";
	char *src = "lele";
	size_t n = 4;
	//printf("%s\n",(char *)ft_memcpy(dest, src, n));
	//printf("%s",(char *) memcpy(dest, src, n));
	printf("%s", (char *) memmove(dest, src, n));
	return (0);
}*/
