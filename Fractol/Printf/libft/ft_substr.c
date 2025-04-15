/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 07:33:38 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/11 12:06:55 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_new;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len_s - start < len)
		len = len_s - start;
	s_new = (char *)malloc (sizeof(char) * (len + 1));
	i = 0;
	while (i < len && s[start + i])
	{
		s_new[i] = s[start + i];
		i++;
	}
	s_new[i] = '\0';
	return (s_new);
}
/*
int main()
{
	char *str = "gabriel is crazy";
	unsigned int start = 11;
	size_t len = 5;

	printf("%s", ft_substr(str, start, len));
	return 0;
}*/
