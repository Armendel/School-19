/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:01:25 by asaini            #+#    #+#             */
/*   Updated: 2023/06/13 16:39:14 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_in_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (end >= 0 && char_is_in_set(s1[end], set))
		end--;
	while (s1[start] && char_is_in_set(s1[start], set))
		start++;
	if (start > end)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	str = malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 2);
	return (str);
}
