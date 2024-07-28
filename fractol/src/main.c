/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <saini.mendel@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:19:26 by asaini            #+#    #+#             */
/*   Updated: 2024/07/25 15:35:32 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_data		img;
	t_bounds	bounds;

	if (!parse_command(argc, argv, &vars))
		return (0);
	bounds.x_min = -2;
	bounds.x_max = 2;
	bounds.y_min = -2;
	bounds.y_max = 2;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, ROW, LINE, "Hello world!");
	img.img = mlx_new_image(vars.mlx, ROW, LINE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	vars.data = img;
	vars.bounds = bounds;
	calculate_fractal(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, BTN_CLOSE, 0, close_mlx_win, &vars);
	mlx_key_hook(vars.win, key_event, &vars);
	mlx_mouse_hook(vars.win, mouse_event, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
