/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:05:10 by asaini            #+#    #+#             */
/*   Updated: 2023/06/13 22:07:34 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if ((!haystack || !needle) && len == 0)
		return (0);
	i = 0;
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (0);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && i + j < len && needle[j] == haystack[i + j])
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
