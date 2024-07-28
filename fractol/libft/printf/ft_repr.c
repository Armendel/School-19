/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:45:29 by asaini            #+#    #+#             */
/*   Updated: 2023/07/28 16:20:50 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_str(va_list *args)
{
	char	*res;

	res = (va_arg(*args, char *));
	if (!res)
		return (ft_strdup("(null)"));
	else
		return (ft_strdup(res));
}

char	*get_ptr(va_list *args)
{
	char	*res;
	char	*tmp;

	tmp = to_base((va_arg(*args, long unsigned int)), HEX);
	if (!tmp)
		return (0);
	res = ft_strjoin("0x", tmp);
	if (!res)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (res);
}

char	*get_repr(char fmt, va_list *args)
{
	if (fmt == 'c')
		return (to_str(va_arg(*args, int)));
	else if (fmt == 's')
		return (get_str(args));
	else if (fmt == 'p')
		return (get_ptr(args));
	else if (fmt == 'd')
		return ((ft_itoa(va_arg(*args, int))));
	else if (fmt == 'i')
		return ((ft_itoa(va_arg(*args, int))));
	else if (fmt == 'u')
		return ((ft_uitoa(va_arg(*args, unsigned))));
	else if (fmt == 'x')
		return (to_base(va_arg(*args, unsigned int), HEX));
	else if (fmt == 'X')
		return (to_base(va_arg(*args, unsigned int), BIG_HEX));
	else if (fmt == '%')
		return (ft_strdup("%"));
	return (0);
}
