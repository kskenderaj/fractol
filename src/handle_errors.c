/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:59:07 by kskender          #+#    #+#             */
/*   Updated: 2025/08/05 11:36:13 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	handle_errors(t_fractol *f)
{
	if (f && f->mlx)
		mlx_terminate(f->mlx);
	ft_printf("Usage:\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("./fractol julia <Real nbr> <Img nbr>\n");
	ft_printf("./fractol burning_ship\n");
	exit(1);
}
