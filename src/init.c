/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:40:33 by palucena          #+#    #+#             */
/*   Updated: 2023/08/22 17:08:03 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fract(t_info *info)
{
	info->pos_x = 0;
	info->pos_y = 0;
	info->max_iterations = 35;
	info->zoom = 4;
}

void	create_window(t_info *info)
{
//	mlx_set_setting(MLX_FULLSCREEN, true); KLK
	info->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!info->mlx)
		exit(EXIT_FAILURE);
	info->win = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->win)
		exit(EXIT_FAILURE);
	init_fract(info);
	mlx_image_to_window(info->mlx, info->win, 0, 0);
	mlx_key_hook(info->mlx, &hook, &info);
//	mlx_loop_hook(info->mlx, &my_keyhook, &info);
	mlx_scroll_hook(info->mlx, &my_scrollhook, &info);
//	mlx_mouse_hook(info->mlx, &my_mousehook, &info);
}
