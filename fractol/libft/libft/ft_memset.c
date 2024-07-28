/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:33:48 by asaini            #+#    #+#             */
/*   Updated: 2023/05/22 13:35:38 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*addr;
	size_t			i;

	i = 0;
	addr = b;
	while (i < len)
	{
		addr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
