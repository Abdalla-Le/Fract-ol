/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:40:49 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/16 17:49:25 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(const char *s, char c)
{
	int	i;
	int	words;
	int	in_word;

	i = 0;
	words = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			words++;
		}
		else if (s[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (words);
}

static int	count_l(const char *s, char c)
{
	int	letters;

	letters = 0;
	while (s[letters] && s[letters] != c)
		letters++;
	return (letters);
}

void	alloc_vet(const char *s, char **new_s, char c)
{
	int	i;
	int	letters;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			letters = count_l(s + i, c);
			new_s[word] = (char *)malloc(sizeof(char) * (letters + 1));
			if (!new_s[word])
			{
				while (word > 0)
					free(new_s[--word]);
				free(new_s);
				return ;
			}
			ft_strlcpy(new_s[word++], s + i, letters + 1);
			i += letters;
		}
	}
}

char	**alloc_mat(const char *s, char c)
{
	int		words;
	char	**new_s;

	words = count_w(s, c);
	new_s = (char **)malloc(sizeof(char *) * (words + 1));
	if (new_s == NULL)
		return (NULL);
	new_s[words] = NULL;
	return (new_s);
}

char	**ft_split(const char *s, char c)
{
	char	**new_s;

	if (!s)
		return (NULL);
	new_s = alloc_mat(s, c);
	if (!new_s)
		return (NULL);
	alloc_vet(s, new_s, c);
	return (new_s);
}
