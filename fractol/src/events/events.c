/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <saini.mendel@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:32:40 by asaini            #+#    #+#             */
/*   Updated: 2024/07/25 15:33:48 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_mlx_win(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	key_event(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		close_mlx_win(vars);
	return (0);
}

static void	mul_bounds(t_bounds *bounds, double val)
{
	bounds->x_min *= val;
	bounds->y_min *= val;
	bounds->x_max *= val;
	bounds->y_max *= val;
}

int	mouse_event(int keycode, int x, int y, t_vars *vars)
{
	double	cursor_re;
	double	cursor_im;
	double	zoom;

	if (keycode == WHEEL_UP)
		zoom = 0.8;
	else if (keycode == WHEEL_DOWN)
		zoom = 1.2;
	else
		return (0);
	cursor_re = to_re(vars->bounds.x_min, vars->bounds.x_max, x);
	cursor_im = to_im(vars->bounds.y_min, vars->bounds.y_max, y);
	vars->bounds.x_min = cursor_re - (cursor_re - vars->bounds.x_min) * zoom;
	vars->bounds.x_max = cursor_re + (vars->bounds.x_max - cursor_re) * zoom;
	vars->bounds.y_min = cursor_im - (cursor_im - vars->bounds.y_min) * zoom;
	vars->bounds.y_max = cursor_im + (vars->bounds.y_max - cursor_im) * zoom;
	mul_bounds(&vars->bounds, 1);
	calculate_fractal(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}
