/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:08:36 by palucena          #+#    #+#             */
/*   Updated: 2023/07/29 15:25:51 by palucena         ###   ########.fr       */
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

/* void	mandelbrot(t_info *info)
{
	double	x;
	double	y;
	double	z;
	int		i;

	x = WIDTH / (-2) + info->pos_x;
	y = HEIGHT / (-2) + info->pos_y;
	i = 0;
	while (i <= info->max_iterations)
	{
		//printf("x = %f y = %f\n", x, y);
		info->real = (x * x) - (y * y);
		info->imag = 2 * x * y;
		z = info->real + info->imag + x + y;
		if (z >= __DBL_MAX__ || z * (-1) >= __DBL_MAX__)
			break ;
		i++;
	}
	draw_pixel(info, i);
} */ // Mio

void	mandelbrot(t_info *info)
{
	int		i;
	double	x_temp;
	double	x;
	double	y;

	i = 0;
	info->real = 0.0;
	info->imag = 0.0;
	x = (info->pos_x / 0.03) + (-1.21); // WIDTH / (-2) + info->pos_x; // (info->x / info->zoom) + info->offset_x;
	y = (info->pos_y / 0.03) + (-1.21); // HEIGHT / (-2) + info->pos_y; // (info->y / info->zoom) + info->offset_y;
	while (++i < info->max_iterations)
	{
		//printf("x = %f y = %f\n", x, y);
		x_temp = info->real * info->real - info->imag * info->imag + x;
		info->imag = 2. * info->real * info->imag + y;
		info->real = x_temp;
		if (info->real * info->real + info->imag * info->imag >= __DBL_MAX__)
		break ;
	}
	draw_pixel(info, i);
} // Robado

// void	julia(t_info *info)  Paso a paso

//void	burningship(t_info *info) Paso a paso