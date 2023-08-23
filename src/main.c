/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:15:01 by palucena          #+#    #+#             */
/*   Updated: 2023/08/23 17:35:47 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int32_t	main(int ac, char **av)
{
	t_info	*info;

	if (ac < 2)
	{
		ft_putstr_fd("Esta mal", 1);
		exit (1);
	}
	info = create_window();
	info->name = av[1]; //funcion check name
	print_fractal(info);
	mlx_loop(info->mlx);
	mlx_delete_image(info->mlx, info->win);
	mlx_terminate(info->mlx);
	return(0);
}

/* int	check_args(int ac, char *fr)
{
	int	f;

	if (ac != 2)
	{
		if (ac != 4)
			exit (1);
	}
	if (strcmp(fr, "mandelbrot") == 0 || strcmp(fr, "1"))
		f = 1;
	else if (strcmp(fr, "julia") == 0 || strcmp(fr, "Julia") == 0 || strcmp(fr, "2"))
		f = 2;
	else if (strcmp(fr, "burningship") == 0 || strcmp(fr, "Burningship") == 0)
		f = 3; // Paso a paso
	else
		exit (1);
	return (f);
}

int32_t	main(int ac, char **av)
{
	t_info	info;
	int		a;

	a = check_args(ac, av[1]);	
	create_window(&info);
	while (info.pos_y < HEIGHT)
	{
		info.pos_x = -1;
		while (++info.pos_x < WIDTH)
			fractal(a, &info);
		info.pos_y++;
	}
	mlx_loop(info.mlx);
	mlx_delete_image(info.mlx, info.win);
	mlx_terminate(info.mlx);
	return(0);
}
 */