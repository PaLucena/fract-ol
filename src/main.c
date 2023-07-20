/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:15:01 by palucena          #+#    #+#             */
/*   Updated: 2023/07/20 20:12:25 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
int	main(int ac, char **av)
{
	t_fractol	fractal;

	create_window(&fractal);
	if (strcmp(av[1], "Mandelbrot") == 0)
		mandel(&fractal); //
	else if (strcmp(av[1], "Julia") == 0)
		julia(&fractal);
	else if (strcmp(av[1], "Burningship") == 0)
		burning_ship(&fractal);
	else
	{
		ft_putstr_fd("\nError: Wrong arguments\n", 1);
		ft_putstr_fd("Example: ./fractol Mandelbrot\n", 1);
	}
	loop(&fractal);
	return(0);
} */

int	main(void)
{
/* 	void	*mlx_ptr;
	void	*win_ptr; */
	t_fractol	cosas;
	int			x;
	int			y;
	int			color;

	create_window(&cosas);
	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		if (y >= HEIGHT / 5 * 2 && y < HEIGHT / 5 * 3)
			color = 0xFFFFFF;
		else
			color = 0x008F0D0D;
		while (x <= WIDTH)
		{
			mlx_pixel_put(cosas.mlx, cosas.win, x, y, color);
			x++;
		}
		y++;
	}
	loop(&cosas);
	return (0);
}
