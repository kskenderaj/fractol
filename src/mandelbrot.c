/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:40:48 by kskender          #+#    #+#             */
/*   Updated: 2025/07/26 11:00:24 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	temp;
	int		i;
	double	modulus_squared;

	zr = 0;
	zi = 0;
	i = 0;
	while ((zr * zr + zi * zi <= 4.0) && i < max_iter)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		i++;
	}
	if (i == max_iter)
		return (i);
	modulus_squared = zr * zr + zi * zi;
	if (modulus_squared > 0.0)
		return (i + 1 - log(log(modulus_squared)) / log(2.0));
	else
		return (i);
}
