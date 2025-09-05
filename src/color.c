/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:53:10 by kskender          #+#    #+#             */
/*   Updated: 2025/07/29 13:14:44 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	select_palettes(double t, int shift, t_rgb *c)
{
	if (shift % 4 == 0)
	{
		if (t > 1.0)
			t = 1.0;
		c->r = (int)(128 + 127 * sin(99.2831 * t + 1.0));
		c->g = (int)(128 + 127 * sin(99.2831 * t + 3.0));
		c->b = (int)(128 + 127 * sin(99.2831 * t + 5.0));
	}
	else if (shift % 4 == 1)
	{
		c->r = (int)(255 * t + 20 * sin(t * 10));
		c->g = (int)(100 * t + 10 * sin(t * 5));
		c->b = (int)(30 * (1 - t) + 10 * sin(t * 7));
	}
	else
	{
		c->r = (int)(t * 999 * sin(69.420));
		c->g = (int)(t * 80 * sin(69.420));
		c->b = (int)(t * 1337 * sin(69.420));
	}
}

uint32_t	get_smooth_color(double iter, int max_iter, int shift)
{
	double	t;
	t_rgb	c;

	t = iter / max_iter;
	select_palettes(t, shift, &c);
	return ((c.r << 24) | (c.g << 16) | (c.b << 8) | 0xFF);
}

static void	handle_pixel(t_fractol *f, int x, int y)
{
	double		cr;
	double		ci;
	int			iter;
	uint32_t	color;

	cr = (x - WIDTH / 2) / (0.5 * f->zoom * WIDTH) + f->x_offset;
	ci = (y - HEIGHT / 2) / (0.5 * f->zoom * HEIGHT) + f->y_offset;
	if (!strncmp(f->name, "mandelbrot", 10))
		iter = mandelbrot(cr, ci, f->max_iter);
	else if (!ft_strncmp(f->name, "julia", 5))
		iter = julia(cr, ci, f);
	else
		iter = burning_ship(cr, ci, f->max_iter);
	color = get_smooth_color(iter, f->max_iter, f->color_shift);
	mlx_put_pixel(f->image, x, y, color);
}

void	draw_fractol(void *param)
{
	t_fractol	*f;
	int			x;
	int			y;

	f = (t_fractol *)param;
	f->max_iter = 50 + (int)(log10(f->zoom + 1.0) * 50);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(f, x, y);
			x++;
		}
		y++;
	}
}
