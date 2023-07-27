/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:15:01 by palucena          #+#    #+#             */
/*   Updated: 2023/07/26 18:40:53 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	create_window(t_info *info)
{
//	mlx_set_setting(MLX_FULLSCREEN, true); KLK
	info->mlx = mlx_init(WIDTH, HEIGHT, "Banderas", true);
	if (!info->mlx)
		exit(EXIT_FAILURE);
	info->win = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->win)
		exit(EXIT_FAILURE);
	info->size_x = 0;
	info->size_y = 0;
	info->iterations = 50;
	mlx_image_to_window(info->mlx, info->win, 0, 0);
	mlx_loop_hook(info->mlx, &hook, &info);
	mlx_key_hook(info->mlx, &my_keyhook, &info);
	mlx_scroll_hook(info->mlx, &my_scrollhook, &info);
}

uint32_t get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
} // Como vergas se ponen los colores en esta libreria de mierda?????

int32_t	main(int ac, char **av)
{
	t_info	info;

	create_window(&info);
	while (info.size_y < HEIGHT)
	{
		info.size_x = -1;
		while (++info.size_x < WIDTH)
			fractal(av[1], &info);
		info.size_y++;
	}
	mlx_loop(info.mlx);
	mlx_delete_image(info.mlx, info.win);
	mlx_terminate(info.mlx);
	return(0);
}
