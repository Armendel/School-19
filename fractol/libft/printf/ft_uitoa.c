/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:19:16 by asaini            #+#    #+#             */
/*   Updated: 2023/07/27 20:55:55 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	push(char *buffer, char c)
{
	while (*buffer)
		buffer++;
	*buffer = c;
}

static	void	to_dec(char *buffer, unsigned int n)
{
	if (n >= 10)
	{
		to_dec(buffer, n / 10);
		to_dec(buffer, n % 10);
	}
	else
		push(buffer, n + '0');
}

char	*ft_uitoa(unsigned int n)
{
	char		*repr;
	char		buffer[15];

	ft_bzero(buffer, 15);
	to_dec(buffer, n);
	repr = malloc((ft_strlen(buffer) + 1) * sizeof(char));
	if (!repr)
		return (0);
	ft_strlcpy(repr, buffer, 15);
	return (repr);
}
