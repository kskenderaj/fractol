/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:45:33 by kskender          #+#    #+#             */
/*   Updated: 2025/07/26 17:46:12 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	burning_ship(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	temp;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while ((zr * zr + zi * zi <= 4.0) && i < max_iter)
	{
		temp = zr * zr - zi * zi + cr;
		zi = fabs(2 * zr * zi) + ci;
		zr = fabs(temp);
		i++;
	}
	if (i == max_iter)
		return (i);
	if (zr * zr + zi * zi > 0)
		return (i + 1 - log(log(zr * zr + zi * zi)) / log(2.0));
	return (i);
}
