/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <saini.mendel@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:24:35 by asaini            #+#    #+#             */
/*   Updated: 2024/07/25 15:24:36 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	to_re(double re_min, double re_max, double x)
{
	return (re_min + x / ROW * (re_max - re_min));
}

double	to_im(double im_min, double im_max, double y)
{
	return (im_min + (LINE - y) / LINE * (im_max - im_min));
}

double	modulus(double re, double im)
{
	return (sqrt((re * re) + (im * im)));
}
