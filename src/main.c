/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:58:18 by kskender          #+#    #+#             */
/*   Updated: 2025/07/28 12:51:05 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	parse_args(int ac, char **av, t_fractol *f)
{
	if (!(ft_strncmp(av[1], "julia", 5) != 0))
	{
		if (ac != 4 || !is_valid_float(av[2]) || !is_valid_float(av[3]))
			handle_errors(f);
		f->real = ft_atof(av[2]);
		f->imag = ft_atof(av[3]);
	}
	else if (!(ft_strncmp(av[1], "mandelbrot", 11) != 0) && ac == 2)
		;
	else if (!(ft_strncmp(av[1], "burning_ship", 12) != 0) && ac == 2)
		;
	else
		handle_errors(f);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
		handle_errors(NULL);
	init(&f, av[1]);
	parse_args(ac, av, &f);
	setup_hooks(&f);
	mlx_loop_hook(f.mlx, draw_fractol, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (0);
}
