/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:39:01 by asaini            #+#    #+#             */
/*   Updated: 2023/06/13 22:54:44 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_split(char const *s, char c)
{
	unsigned int	i;
	size_t			count;
	int				word_start;

	word_start = 0;
	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == c)
		{
			i++;
			while (s[i] == c)
				i++;
			word_start = 0;
			i--;
		}
		else if (!word_start)
		{
			word_start = 1;
			count++;
		}
	}
	return (count);
}

static	size_t	count_chars(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**malloc_split(char const *s, char c)
{
	size_t	count;

	count = count_split(s, c);
	return (malloc((count + 1) * sizeof(char *)));
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	size_t			count;
	size_t			i;

	if (!s)
		return (NULL);
	split = malloc_split(s, c);
	if (!split)
		return (0);
	i = -1;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		count = count_chars(s, c);
		if (count == 0)
			break ;
		split[++i] = malloc((count + 1) * sizeof(char));
		if (!(split[i]))
			return (0);
		ft_strlcpy(split[i], s, count + 1);
		s += count;
	}
	split[++i] = NULL;
	return (split);
}
