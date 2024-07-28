/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <saini.mendel@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:03:22 by asaini            #+#    #+#             */
/*   Updated: 2024/07/25 16:10:33 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "stdlib.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

# define ROW 500.0
# define LINE 500.0
# define MAX_ITERATION 50.0

enum	e_commands_return
{
	OK = 0,
	ERROR = 1,
	CMD_ERROR = 2,
};

enum	e_keys
{
	BTN_CLOSE = 17,
	KEY_ESC = 65307,
	WHEEL_UP = 4,
	WHEEL_DOWN = 5,
	UP = 65362,
	DOWN = 65364,
	LEFT = 65361,
	RIGHT = 65363,
};

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_data;

typedef struct s_bounds
{
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
}	t_bounds;

typedef struct s_params
{
	double	x;
	double	y;
}	t_params;

typedef struct s_vars
{
	void				*mlx;
	void				*win;
	int					type;
	t_params			c;
	t_data				data;
	t_bounds			bounds;
}	t_vars;

void	put_pixel(t_data *data, int x, int y, int color);
void	calculate_fractal(t_vars *vars);
void	draw_mandelbrot_color(t_vars *vars, int x, int y);
void	draw_julia_color(t_vars *vars, int x, int y);
int		close_mlx_win(t_vars *vars);
int		key_event(int keycode, t_vars *vars);
int		mouse_event(int keycode, int x, int y, t_vars *vars);
double	modulus(double re, double im);
double	to_im(double im_min, double im_max, double y);
double	to_re(double re_min, double re_max, double x);
int		parse_command(int argc, char **argv, t_vars *vars);
void	help_msg(void);
double	atod(const char *str);

#endif