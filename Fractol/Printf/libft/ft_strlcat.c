/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:20:56 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/11 12:06:08 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	j;
	size_t			dest_len;

	dest_len = ft_strlen(dst);
	j = 0;
	if (dest_len >= size)
		return (size + ft_strlen(src));
	while (src[j] && (dest_len + j) < (size - 1))
	{
		dst[dest_len + j] = src[j];
		j++;
	}
	dst[dest_len + j] = '\0';
	return (dest_len + ft_strlen(src));
}

/*
int	main()
{
	char	str1[20] = "leticiaaa";
	char	str2[10] = "blim blom";

	printf("%i", ft_strlcat(str1, str2,5));
	return 0;
}*/
