/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:21:36 by asaini            #+#    #+#             */
/*   Updated: 2023/06/13 18:53:58 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	char			*ptr;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	ptr = str;
	i = 0;
	while (s1[i])
	{
		*ptr = s1[i++];
		ptr++;
	}
	i = 0;
	while (s2[i])
	{
		*ptr = s2[i++];
		ptr++;
	}
	*ptr = '\0';
	return (str);
}
