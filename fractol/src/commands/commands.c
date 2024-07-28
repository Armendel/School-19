/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <saini.mendel@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:26:22 by asaini            #+#    #+#             */
/*   Updated: 2024/07/25 15:35:04 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	help_msg(void)
{
	ft_printf("You can start the fractol drawing using the arguments : \n");
	ft_printf("J or M for Julia or Mandelbrot\n");
	ft_printf("Two numbers for the complex number constants for Julia\n");
	ft_printf("Mandelbrot takes no addionnal argument.\n\n");
	ft_printf("Example for Julia : \n");
	ft_printf("./fractol J 0.355 0.355\n\n");
	ft_printf("Example for Mandelbrot : \n");
	ft_printf("./fractol M\n");
}

static void	fill_args(t_vars *vars, double c_x, double c_y)
{
	vars->type = 0;
	vars->c.x = c_x;
	vars->c.y = c_y;
}

int	parse_command(int argc, char **argv, t_vars *vars)
{
	if (argc < 2 || argc > 4)
	{
		ft_printf("The number of arguments is incorrect ! \n");
		help_msg();
		return (0);
	}
	if (ft_strlen(argv[1]) != 1 && (argv[1][0] != 'J' || argv[1][0] != 'M'))
	{
		ft_printf("You must select a fractal type : Julia or Mandelbrot\n");
		help_msg();
		return (0);
	}
	if (argv[1][0] == 'J')
		fill_args(vars, atod(argv[2]), atod(argv[3]));
	else if (argv[1][0] == 'M' && argc == 2)
		vars->type = 1;
	else if (argv[1][0] == 'M' && argc > 2)
	{
		ft_printf("Mandelbrot takes no additionnal argument.\n");
		return (0);
	}
	return (1);
}
