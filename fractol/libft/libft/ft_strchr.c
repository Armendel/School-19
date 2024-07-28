/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:25:44 by asaini            #+#    #+#             */
/*   Updated: 2023/06/13 22:09:30 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = c;
	i = -1;
	while (s[++i])
	{
		if (s[i] == ch)
			return ((char *)s + i);
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (0);
}
