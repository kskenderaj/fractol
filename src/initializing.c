/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:13:37 by kskender          #+#    #+#             */
/*   Updated: 2025/07/28 12:58:13 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init(t_fractol *f, char *name)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, name, false);
	if (!f->mlx)
		exit(EXIT_FAILURE);
	f->image = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->image)
		exit(EXIT_FAILURE);
	mlx_image_to_window(f->mlx, f->image, 0, 0);
	f->zoom = 0.6;
	f->x_offset = -0.5;
	f->y_offset = 0.0;
	f->name = name;
	f->color_shift = 0;
}
