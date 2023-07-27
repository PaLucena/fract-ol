/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:08:36 by palucena          #+#    #+#             */
/*   Updated: 2023/07/27 17:20:29 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_info *info);

void	fractal(char	*av, t_info *info)
{
	if (strcmp(av, "mandelbrot") == 0 || strcmp(av, "Mandelbrot") == 0)
		mandelbrot(info);
	/* else if (strcmp(av, "julia") == 0 || strcmp(av, "Julia") == 0)
		julia(&info);
	else if (strcmp(av, "burningship") == 0 || strcmp(av, "Burningship") == 0)
		burningship(&info); */ // Paso a paso
	else
	{
	//	ft_putstr_fd("\nError: Wrong arguments\n", 1);
	//	ft_putstr_fd("Example: ./fractol mandelbrot\n", 1);
	}
}

void	mandelbrot(t_info *info)
{
	double	x;
	double	y;
	double	z;
	int		i;

	x = WIDTH / (-2) + info->pos_x;
	y = HEIGHT / (-2) + info->pos_y;
	i = 0;
	while (++i <= info->max_iterations)
	{
		info->real = exp2(x) - exp2(y);
		info->imag = 2 * x * y;
		z = info->real + info->imag + x + y;
		if (z >= __DBL_MAX__)
			break ;
	}
	draw_pixel(info, i);
}

// void	julia(t_info *info)  Paso a paso

//void	burningship(t_info *info) Paso a paso