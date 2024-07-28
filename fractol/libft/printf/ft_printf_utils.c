/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:57:58 by asaini            #+#    #+#             */
/*   Updated: 2023/08/10 12:32:59 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_str(char c)
{
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	return (ft_strdup(tmp));
}

int	free_and_ret(t_fmt_state **smth, int i)
{
	if (!smth || !(*smth))
		return (i);
	free(*smth);
	*smth = NULL;
	return (i);
}

int	push(char **dest, const char *src)
{
	char	*tmp;

	if (!dest || !(*dest) || !src)
		return (0);
	tmp = ft_strjoin(*dest, src);
	if (!tmp)
		return (0);
	free(*dest);
	*dest = tmp;
	return (1);
}

int	push_back(char **dest, const char *src)
{
	char	*tmp;

	if (!dest || !(*dest) || !src)
		return (0);
	tmp = ft_strjoin(src, *dest);
	if (!tmp)
		return (0);
	free(*dest);
	*dest = tmp;
	return (1);
}
