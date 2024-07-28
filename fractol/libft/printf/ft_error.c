/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:27:58 by asaini            #+#    #+#             */
/*   Updated: 2023/07/28 16:22:41 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt_state	*create(void)
{
	t_fmt_state	*state;

	state = (t_fmt_state *)malloc(sizeof(t_fmt_state));
	if (!state)
		return (0);
	state->fmt = 0;
	state->error = 0;
	return (state);
}

int	no_fmt(t_fmt_state *state)
{
	return (state->error == 0 && state->fmt == 0);
}

int	fmt_error(t_fmt_state *state)
{
	return (state->error == 1);
}
