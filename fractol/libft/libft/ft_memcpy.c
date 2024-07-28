/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:18:29 by asaini            #+#    #+#             */
/*   Updated: 2023/06/12 16:50:15 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*my_dst;
	const char	*my_src;

	if (!dst && !src)
		return (0);
	my_dst = dst;
	my_src = src;
	i = -1;
	while (++i < n)
		my_dst[i] = my_src[i];
	return (dst);
}
