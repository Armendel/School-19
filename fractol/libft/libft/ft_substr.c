/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:30:06 by asaini            #+#    #+#             */
/*   Updated: 2023/06/13 22:34:23 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	real_len;

	if (!s)
		return (NULL);
	if ((s && start == 0 && len == 0) || ft_strlen(s) < start)
	{
		str = malloc(sizeof(char *));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	real_len = ft_strlen(s);
	if (len > real_len - start)
		len = real_len - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && start < real_len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
