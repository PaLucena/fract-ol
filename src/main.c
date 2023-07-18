/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:15:01 by palucena          #+#    #+#             */
/*   Updated: 2023/07/18 13:26:27 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MLX/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define WIDTH 1024
#define HEIGHT 1024

/* static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void	ft_hook(void	*param)
{
	const mlx_t	*mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			x = 0;
	int			y = 0;

	mlx = mlx_init(WIDTH, HEIGHT, "Avestruz", true); // Nueva ventana
	img = mlx_new_image(mlx, 256, 256); // Nueva imagen
	if (!mlx)
		ft_error();
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_put_pixel(img, 0, 0, 0xFF0000); // Pone un pixel en la posicion (x, y)
	while (x < WIDTH)
	{
		while (y < HEIGHT)
			mlx_put_pixel(img, x, ++y, 0xFF0000); // Va rellenando "y"
		mlx_put_pixel(img, ++x, y, 0xFF000000); // Va rellenando "x"
		y = 0;
	}
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
} */

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void	ft_hook(void	*param)
{
	const mlx_t	*mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{
	int			x = 0;
	int			y = 0;
	mlx_t		*mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	mlx_image_t	*img = mlx_new_image(mlx, WIDTH, HEIGHT);

	if (!mlx)
		ft_error();
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_put_pixel(img, 0, 0, 0x0000FFFF);
	while (x < WIDTH)
	{
		while (y < HEIGHT)
			mlx_put_pixel(img, x, y++, 0x0000FFFF);
		x++;
		y = 0;
	}
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
