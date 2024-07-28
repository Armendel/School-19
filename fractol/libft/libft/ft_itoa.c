/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <saini.mendel@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:23:18 by asaini            #+#    #+#             */
/*   Updated: 2024/07/25 15:48:38 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	push(char *buffer, char c)
{
	while (*buffer)
		buffer++;
	*buffer = c;
}

static	void	to_dec(char *buffer, long int n)
{
	if (n >= 10)
	{
		to_dec(buffer, n / 10);
		to_dec(buffer, n % 10);
	}
	else
		push(buffer, n + '0');
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*repr;
	char		buffer[15];

	nb = n;
	ft_bzero(buffer, 15);
	if (nb < 0)
	{
		buffer[0] = '-';
		nb *= -1;
	}
	to_dec(buffer, nb);
	repr = malloc((ft_strlen(buffer) + 1) * sizeof(char));
	if (!repr)
		return (0);
	ft_strlcpy(repr, buffer, 15);
	return (repr);
}
