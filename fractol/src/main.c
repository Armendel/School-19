/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <saini.mendel@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:19:26 by asaini            #+#    #+#             */
/*   Updated: 2024/08/05 19:53:10 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	clean_init(t_vars *vars)
{
	vars->data.addr = NULL;
	vars->data.img = NULL;
	vars->data.bits_per_pixel = 0;
	vars->data.endian = 0;
	vars->data.line_length = 0;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->max_it = 50;
	vars->bounds.x_min = -2;
	vars->bounds.x_max = 2;
	vars->bounds.y_min = -2;
	vars->bounds.y_max = 2;
	vars->type = 0;
	vars->c.x = 0;
	vars->c.y = 0;
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	clean_init(&vars);
	if (!parse_command(argc, argv, &vars) || vars.max_it <= 0)
		close_mlx_win(&vars);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, ROW, LINE, "fractol");
	if (!vars.win)
		close_mlx_win(&vars);
	vars.data.img = mlx_new_image(vars.mlx, ROW, LINE);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits_per_pixel,
			&vars.data.line_length, &vars.data.endian);
	calculate_fractal(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	mlx_hook(vars.win, BTN_CLOSE, 0, close_mlx_win, &vars);
	mlx_key_hook(vars.win, key_event, &vars);
	mlx_mouse_hook(vars.win, mouse_event, &vars);
	mlx_loop(vars.mlx);
	close_mlx_win(&vars);
	return (0);
}
