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
void	julia(t_info *info);

void	fractal(char	*av, t_info *info)
{
	if (strcmp(av, "mandelbrot") == 0 || strcmp(av, "Mandelbrot") == 0)
		mandelbrot(info);
	else if (strcmp(av, "julia") == 0 || strcmp(av, "Julia") == 0)
		julia(info);
	/* else if (strcmp(av, "burningship") == 0 || strcmp(av, "Burningship") == 0)
		burningship(&info); */ // Paso a paso
	else
	{
	//	ft_putstr_fd("\nError: Wrong arguments\n", 1);
	//	ft_putstr_fd("Example: ./fractol mandelbrot\n", 1);
	}
}

void	mandelbrot(t_info *info)
{
	double	cx;
	double	cy;
	double	z;
	double	tmp;
	int		i;

	cx = (info->pos_x - WIDTH / 2) * info->zoom / WIDTH - 0.5;
	cy = (info->pos_y - (HEIGHT / 2)) * (info->zoom / HEIGHT);
	i = 0;
	info->zx = 0.0;
	info->zy = 0.0;
	while (i <= info->max_iterations)
	{
		if (z >= 4.0)
			break ;
		// printf("x = %f y = %f\n", x, y);
		tmp = info->zx * info->zx - info->zy * info->zy + cx;
		info->zy = 2 * info->zx * info->zy + cy;
		info->zx = tmp;
		z = info->zx * info->zx + info->zy * info->zy;
		i++;
	}
	draw_pixel(info, i);
} // Mio

void	julia(t_info *info)
{
	double	cx;
	double	cy;
	double	z;
	double	tmp;
	int		i;

	cx = -0.8;
	cy = 0.156;
	i = 0;
	info->zx = (info->pos_x - WIDTH / 2) * info->zoom / WIDTH;
	info->zy = (info->pos_y - (HEIGHT / 2)) * (info->zoom / HEIGHT);
	while (i <= info->max_iterations)
	{
		if (z >= 4.0)
			break ;
		// printf("x = %f y = %f\n", x, y);
		tmp = info->zx * info->zx - info->zy * info->zy + cx;
		info->zy = 2 * info->zx * info->zy + cy;
		info->zx = tmp;
		z = info->zx * info->zx + info->zy * info->zy;
		i++;
	}
	draw_pixel(info, i);
}

/* void	ese_raro(t_info *info)
{
	double	x;
	double	y;
	double	z;
	double	tmp;
	int		i;

	x = WIDTH / (-2) + info->pos_x;
	y = HEIGHT / (-2) + info->pos_y;
	info->zx = 0.0;
	info->zy = 0.0;
	i = 0;
	while (i <= info->max_iterations)
	{
		// printf("x = %f y = %f\n", x, y);
		tmp = info->zx * info->zx - info->zy * info->zy + x * 0.02;
		info->zy = 2 * info->zx * info->zy + y * 0.02;
		info->zx = tmp;
		z = info->zx + info->zy;
		if (z >= __DBL_MAX__ || z * (-1) >= __DBL_MAX__)
			break ;
		i++;
	}
	draw_pixel(info, i);
} */ // Pseudo fractal aleatorio encontrado sin querer


//void	burningship(t_info *info) Paso a paso