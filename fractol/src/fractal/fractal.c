/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <saini.mendel@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:16:17 by mendel            #+#    #+#             */
/*   Updated: 2024/08/05 19:54:48 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_fractal(t_vars *vars)
{
	int			i;
	int			j;
	void		(*f)(t_vars *vars, int, int);

	mlx_clear_window(vars->mlx, vars->win);
	if (vars->type == 1)
		f = draw_mandelbrot_color;
	else
		f = draw_julia_color;
	i = -1;
	while (++i < LINE)
	{
		j = -1;
		while (++j < ROW)
		{
			f(vars, i, j);
		}
	}
}

int	get_color(double it, double max_it)
{
	int		r;
	int		g;
	int		b;
	double	n;

	if (it == max_it)
	{
		r = 0;
		g = 0;
		b = 0;
	}
	else
	{
		n = it / max_it;
		r = (int)(9 * (1 - n) * n * n * n * 255);
		g = (int)(15 * (1 - n) * (1 - n) * n * n * 255);
		b = (int)(8.5 * (1 - n) * (1 - n) * (1 - n) * n * 255);
	}
	return (r << 16 | g << 8 | b);
}

static int	get_iteration(double re, double im, t_params *params,
		double max_it)
{
	double	i;
	double	tmp;
	double	re_sq;
	double	im_sq;

	i = 0;
	re_sq = re * re;
	im_sq = im * im;
	while (re_sq + im_sq <= 4 && i < max_it)
	{
		tmp = re;
		re = re_sq - im_sq + params->x;
		im = (2 * tmp * im) + params->y;
		re_sq = re * re;
		im_sq = im * im;
		i++;
	}
	return (i);
}

void	draw_mandelbrot_color(t_vars *vars, int x, int y)
{
	double		im;
	double		re;
	t_params	params;
	double		i;

	params.y = to_im(vars->bounds.y_min, vars->bounds.y_max, y);
	params.x = to_re(vars->bounds.x_min, vars->bounds.x_max, x);
	re = vars->c.x;
	im = vars->c.y;
	i = get_iteration(re, im, &params, vars->max_it);
	put_pixel(&vars->data, x, y, get_color(i, vars->max_it));
}

void	draw_julia_color(t_vars *vars, int x, int y)
{
	double		im;
	double		re;
	double		i;
	t_params	params;

	im = to_im(vars->bounds.y_min, vars->bounds.y_max, y);
	re = to_re(vars->bounds.x_min, vars->bounds.x_max, x);
	params.x = vars->c.x;
	params.y = vars->c.y;
	i = get_iteration(re, im, &params, vars->max_it);
	put_pixel(&vars->data, x, y, get_color(i, vars->max_it));
}
