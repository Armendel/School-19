/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:53:28 by asaini            #+#    #+#             */
/*   Updated: 2023/06/13 18:43:39 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*addr;
	size_t			i;

	i = 0;
	addr = s;
	while (i < n)
	{
		addr[i] = '\0';
		i++;
	}
}
