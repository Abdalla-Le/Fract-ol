/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:14:56 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/10/09 15:15:41 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if ((nmemb == 0) || (size == 0))
	{
		ptr = malloc(1);
		return (ptr);
	}
	total = size * nmemb;
	if (total / size != nmemb)
		return (NULL);
	ptr = (char *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return ((void *)ptr);
}
/*
#include <limits.h>
#include <stdlib.h>

int main()
{
	char *ptr = ft_calloc(5678, 3);
	if (ptr == NULL)
		printf("calloc failed \n");
	else
		printf("calloc success \n");
	free(ptr);
	return (0);
} */
