/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:39:39 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/11 11:48:22 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	int		tam;
	size_t	i;
	char	*new_s;

	len = ft_strlen (s1);
	i = 0;
	while (i < len && ft_strchr(set, s1[i]))
		i++;
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		len--;
	tam = len - i + 1;
	if (tam <= 0)
		return (ft_strdup(""));
	new_s = (char *)malloc(sizeof(char) * tam);
	if (new_s == NULL)
		return (NULL);
	ft_memmove(new_s, s1 + i, tam - 1);
	new_s[tam - 1] = '\0';
	return (new_s);
}
/*
int main()
{
	char *s = "-+leticia+-";
	char *set = "+-";
	printf("%s", ft_strtrim(s, set));
	return 0;
}*/
