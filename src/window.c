/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:08:36 by palucena          #+#    #+#             */
/*   Updated: 2023/07/20 20:37:22 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	create_window(t_fractol *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		exit(EXIT_FAILURE);
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "fract-ol");
	if (fractal->win == NULL)
		exit(EXIT_FAILURE);
}

int	close_window(t_fractol *fractal)
{
	//free fractal?
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_clear_window(fractal->mlx, fractal->win);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	key_handler(int keycode, t_fractol *fractal)
{
	if (keycode == ESC_KEY)
		close_window(fractal);
	return (0);
}

void	loop(t_fractol *fractal)
{
	mlx_key_hook(fractal->win, key_handler, &fractal);
	mlx_hook(fractal->win, 17, 0, close_window, &fractal); // ????
	mlx_loop(fractal->mlx);
}
