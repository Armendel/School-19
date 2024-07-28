/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:51:20 by asaini            #+#    #+#             */
/*   Updated: 2023/06/14 16:08:53 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	min;

	if ((!dst || !src) && dstsize == 0)
		return (0);
	i = ft_strlen(dst);
	j = 0;
	min = dstsize;
	if (i < dstsize)
		min = i;
	while (src[j] && (i < dstsize - 1 && dstsize > 0))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dstsize != 0 && i <= dstsize)
		dst[i] = '\0';
	return (ft_strlen(src) + min);
}
