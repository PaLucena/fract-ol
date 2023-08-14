/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:15:01 by palucena          #+#    #+#             */
/*   Updated: 2023/08/14 16:04:32 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	create_window(t_info *info)
{
//	mlx_set_setting(MLX_FULLSCREEN, true); KLK
	info->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!info->mlx)
		exit(EXIT_FAILURE);
	info->win = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->win)
		exit(EXIT_FAILURE);
	info->pos_x = 0;
	info->pos_y = 0;
	info->max_iterations = 50;
	mlx_image_to_window(info->mlx, info->win, 0, 0);
	mlx_key_hook(info->mlx, &hook, &info);
//	mlx_loop_hook(info->mlx, &my_keyhook, &info);
	mlx_scroll_hook(info->mlx, &my_scrollhook, &info);
}

int32_t	main(int ac, char **av)
{
	t_info	info;

	if (ac < 2)
	{
	//	ft_putstr_fd("Esta mal", 1);
		exit (1);
	}
	else
	{
		create_window(&info);
		while (info.pos_y < HEIGHT)
		{
			info.pos_x = -1;
			while (++info.pos_x < WIDTH)
				fractal(av[1], &info);
			info.pos_y++;
		}
	}
	mlx_loop(info.mlx);
	mlx_delete_image(info.mlx, info.win);
	mlx_terminate(info.mlx);
	return(0);
}
