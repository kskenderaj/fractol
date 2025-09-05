/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:55:10 by kskender          #+#    #+#             */
/*   Updated: 2025/07/26 18:11:09 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(f->mlx);
	if (keydata.key == MLX_KEY_UP)
		f->y_offset -= 0.1 / f->zoom;
	if (keydata.key == MLX_KEY_DOWN)
		f->y_offset += 0.1 / f->zoom;
	if (keydata.key == MLX_KEY_LEFT)
		f->x_offset -= 0.1 / f->zoom;
	if (keydata.key == MLX_KEY_RIGHT)
		f->x_offset += 0.1 / f->zoom;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		f->color_shift = (f->color_shift + 1) % 3;
	draw_fractol(f);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractol	*f;
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		prev_zoom;
	double		scale;

	f = (t_fractol *)param;
	(void)xdelta;
	prev_zoom = f->zoom;
	if (ydelta > 0)
		f->zoom *= 1.2;
	else if (ydelta < 0)
		f->zoom /= 1.2;
	else
		return ;
	scale = 1.0 / (f->zoom * 0.5 * WIDTH);
	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	f->x_offset += (mouse_x - WIDTH / 2) * (1.0 / (0.5 * prev_zoom * WIDTH)
			- scale);
	f->y_offset += (mouse_y - HEIGHT / 2) * (1.0 / (0.5 * prev_zoom * HEIGHT)
			- scale);
}

void	setup_hooks(t_fractol *f)
{
	mlx_key_hook(f->mlx, key_hook, f);
	mlx_scroll_hook(f->mlx, scroll_hook, f);
}
