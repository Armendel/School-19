/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:00:48 by asaini            #+#    #+#             */
/*   Updated: 2023/07/28 19:28:05 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt_state	*get_fmt_state(const char *s)
{
	t_fmt_state	*state;
	char		c;

	if (!s)
		return (0);
	state = create();
	if (!state)
		return (0);
	state->fmt = ft_strchr(s, '%');
	if (!state->fmt)
	{
		state->fmt = 0;
		return (state);
	}
	(state->fmt)++;
	c = *state->fmt;
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
	{
		state->fmt--;
		return (state);
	}
	state->error = 1;
	state->fmt = 0;
	return (state);
}

int	write_text(const char *s, size_t *i, int *count, t_fmt_state *state)
{
	while (s[*i] && &s[*i] != state->fmt)
	{
		if (s[*i] != '%')
		{
			if (write(1, &s[*i], 1) <= 0)
				return (free_and_ret(&state, 0));
			(*count)++;
		}
		(*i)++;
	}
	return (1);
}

int	write_fmt(t_fmt_state *state, va_list *args, size_t *i, int *count)
{
	char	*repr;

	repr = get_repr(*(state->fmt + 1), args);
	if (!repr)
		return (free_and_ret(&state, 0));
	if (!handle_repr(repr, count, i, state))
		return (0);
	return (1);
}

int	handle_repr(char *repr, int *count, size_t *i, t_fmt_state *state)
{
	size_t	size;
	char	fmt;

	if (!repr)
		return (1);
	fmt = *(state->fmt + 1);
	size = ft_strlen(repr);
	if (fmt == 'c' && *repr == '\0')
	{
		(*count)++;
		write(1, "\0", 1);
	}
	else
		*count += size;
	if (write(1, repr, size) < (ssize_t)size)
	{
		free(state);
		free(repr);
		return (0);
	}
	*i += 2;
	free(repr);
	repr = 0;
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	t_fmt_state		*state;
	size_t			i;
	int				count;

	i = 0;
	va_start(args, s);
	count = 0;
	while (s[i])
	{
		state = get_fmt_state(s + i);
		if (!state || fmt_error(state))
			return (free_and_ret(&state, -1));
		if (!write_text(s, &i, &count, state))
			return (-1);
		if (no_fmt(state))
			return (free_and_ret(&state, count));
		if (!write_fmt(state, &args, &i, &count))
			return (-1);
		free(state);
		state = 0;
	}
	va_end(args);
	return (count);
}
