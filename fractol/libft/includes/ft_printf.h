/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:16:20 by asaini            #+#    #+#             */
/*   Updated: 2023/08/10 12:33:29 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# define HEX "0123456789abcdef"
# define BIG_HEX "0123456789ABCDEF"
# define OCT "01234567"
# define BIN "01"

typedef struct s_fmt_state
{
	char	*fmt;
	int		error;
}	t_fmt_state;

t_fmt_state		*create(void);

char			*to_str(char c);
int				no_fmt(t_fmt_state *state);
int				fmt_error(t_fmt_state *state);
char			*to_base(long unsigned int n, char *base);
char			*to_str(char c);
char			*get_repr(char fmt, va_list *args);
int				handle_repr(char *repr, int *count, size_t *i,
					t_fmt_state *state);
int				write_fmt(t_fmt_state *state, va_list *args,
					size_t *i, int *count);
int				write_text(const char *s, size_t *i, int *count,
					t_fmt_state *state);
int				push(char **dest, const char *src);
int				push_back(char **dest, const char *src);
int				free_and_ret(t_fmt_state **smth, int i);
t_fmt_state		*get_fmt_state(const char *s);
int				ft_printf(const char *s, ...);
char			*ft_uitoa(unsigned int n);

#endif