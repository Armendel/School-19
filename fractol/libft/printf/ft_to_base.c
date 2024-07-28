/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:34:06 by asaini            #+#    #+#             */
/*   Updated: 2023/07/28 16:17:55 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_base(long unsigned int n, char *base)
{
	char				*p;
	size_t				size;
	char				str[20];

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_strlen(base);
	p = str + 18;
	ft_memset(str, '\0', 20);
	while (n != 0)
	{
		*p = base[(n % size)];
		n = n / size;
		p--;
	}
	return (ft_strdup(p + 1));
}
