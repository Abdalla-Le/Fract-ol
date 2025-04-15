/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:22:45 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/09 15:22:19 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	tam_s1;
	size_t	tam_s2;
	size_t	i;
	size_t	j;

	tam_s1 = ft_strlen(s1);
	tam_s2 = ft_strlen(s2);
	new_s = (char *) malloc(sizeof(char) * (tam_s1 + tam_s2 + 1));
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_s[i + j] = s2[j];
		j++;
	}
	new_s[i + j] = '\0';
	return (new_s);
}
