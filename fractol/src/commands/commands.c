/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <saini.mendel@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:26:22 by asaini            #+#    #+#             */
/*   Updated: 2024/08/05 19:49:31 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	help_msg(void)
{
	ft_printf("You can start the fractol drawing using the arguments : \n");
	ft_printf("J or M for Julia or Mandelbrot\n");
	ft_printf("Two numbers for the complex number constants for Julia\n");
	ft_printf("You can also add an argument for the number of iterations\n");
	ft_printf("Mandelbrot has only nb of iteration as argument.\n\n");
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

static int	error_msg(char *str)
{
	ft_printf("%s", str);
	help_msg();
	return (0);
}

int	parse_command(int argc, char **argv, t_vars *vars)
{
	if (argc < 2 || argc > 5)
		return (error_msg("The number of arguments is incorrect ! \n"));
	if (ft_strlen(argv[1]) != 1 && (argv[1][0] != 'J' || argv[1][0] != 'M'))
		return (error_msg("You must select a fractal : Julia or Mandelbrot\n"));
	fill_args(vars, 0.0, 0.0);
	if (argv[1][0] == 'J' && argc >= 4)
	{
		fill_args(vars, atod(argv[2]), atod(argv[3]));
		if (argv[1][0] == 'J' && argc == 5)
			vars->max_it = (int)atod(argv[4]);
		return (1);
	}
	else if (argv[1][0] == 'M' && argc > 3)
		return (error_msg("Too much arguments for Mandlebrot.\n"));
	else if (argv[1][0] == 'M' && argc >= 2)
	{
		vars->type = 1;
		if (argv[1][0] == 'M' && argc == 3)
			vars->max_it = (int)atod(argv[2]);
		return (1);
	}
	help_msg();
	return (0);
}
