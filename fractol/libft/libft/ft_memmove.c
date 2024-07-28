/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:43:03 by asaini            #+#    #+#             */
/*   Updated: 2023/06/12 16:57:22 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*my_dst;
	const unsigned char	*my_src;

	if (!dst && !src)
		return (0);
	my_dst = dst;
	my_src = src;
	i = -1;
	if (dst <= src)
	{
		while (++i < len)
			my_dst[i] = my_src[i];
	}
	else
	{
		i = 0;
		while (++i <= len)
			my_dst[len - i] = my_src[len - i];
	}
	return (dst);
}
