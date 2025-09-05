/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:21:04 by kskender          #+#    #+#             */
/*   Updated: 2025/07/28 11:28:36 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	julia(double cr, double ci, t_fractol *f)
{
	double	zr;
	double	zi;
	int		i;
	double	new_zr;

	zr = cr;
	zi = ci;
	i = 0;
	while ((zr * zr + zi * zi <= 4.0) && i < f->max_iter)
	{
		new_zr = zr * zr - zi * zi + f->real;
		zi = 2 * zr * zi + f->imag;
		zr = new_zr;
		i++;
	}
	return (i);
}
