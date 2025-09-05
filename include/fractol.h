/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:37:24 by kskender          #+#    #+#             */
/*   Updated: 2025/07/29 13:28:17 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf/ft_printf.h"
# include <MLX42/MLX42.h>
# include <libft.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_fractol
{
	char		*name;
	double		zoom;
	double		x_offset;
	double		y_offset;
	int			max_iter;
	int			width;
	int			height;
	int			color_shift;
	double		real;
	double		imag;
	mlx_t		*mlx;
	mlx_image_t	*image;
	mlx_image_t	*eagle_img;
	double		re_factor;
	double		im_factor;

}				t_fractol;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

// init.c
void			init_fractol(t_fractol *fractol);

// draw.c
void			draw_fractol(void *param);

// fractals
int				mandelbrot(double cr, double ci, int max_iter);
int				julia(double cr, double ci, t_fractol *f);
int				burning_ship(double cr, double ci, int max_iter);

// color
uint32_t		get_smooth_color(double iter, int max_iter, int shift);

// hooks.c
void			key_hook(mlx_key_data_t keydata, void *param);
void			scroll_hook(double xdelta, double ydelta, void *param);
void			setup_hooks(t_fractol *f);

// utils
void			handle_errors(t_fractol *f);
void			init(t_fractol *f, char *name);
int				is_valid_float(const char *str);

#endif
