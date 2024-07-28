/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:39:40 by asaini            #+#    #+#             */
/*   Updated: 2023/06/13 16:41:07 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;
	unsigned char		character;

	str = (unsigned char *)s;
	character = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		if (str[i] == character)
			return (&str[i]);
	}
	return (0);
}
