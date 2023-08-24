/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:40:33 by palucena          #+#    #+#             */
/*   Updated: 2023/08/24 17:43:33 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fract(t_info *info)
{
	info->max_iterations = 30;
	info->zoom = 3;
	info->offset_x = -0.5;
	info->offset_y = 0;
	if (info->name == 3)
		info->offset_y = -0.4;
}

t_info	*create_window(char *name)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if(!info)
		return (NULL);
	info->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", false);
	if (!info->mlx)
		exit(EXIT_FAILURE);
	info->win = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->win)
		exit(EXIT_FAILURE);
	info->name = check_name(name);
/* 	if (name) */
	init_fract(info);
	mlx_image_to_window(info->mlx, info->win, 0, 0);
	mlx_key_hook(info->mlx, &hook, (void *)info);
	mlx_scroll_hook(info->mlx, &my_scrollhook, (void *)info);
	return (info);
}
