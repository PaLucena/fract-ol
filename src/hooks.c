/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:41:45 by palucena          #+#    #+#             */
/*   Updated: 2023/07/29 13:31:41 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// añadir botones para:
//	- Aumentar número de iteraciones
void	hook(mlx_key_data_t keydata, void	*param)
{
	t_info			*info;
/* 	mlx_key_data_t	keydata; */

	info = (t_info *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
	//	mlx_delete_image(info->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_UP) // Todavia no se como va esto
			info->pos_y += 1;
/* 		if (keydata.key == MLX_KEY_DOWN)
			info->win->instances[0].y += 5;
		if (keydata.key == MLX_KEY_LEFT)
			info->win->instances[0].x -= 5;
		if (keydata.key == MLX_KEY_RIGHT)
			info->win->instances[0].x += 5; */
	}
}

/* void	my_keyhook(mlx_key_data_t mlx_keydata, void *param)
{
	t_info			*info;

	info = (t_info *)param;
	if (mlx_keydata.action == MLX_RELEASE)
		info->keydata.key = mlx_keydata.key;
} // Versión 2 */

void	my_scrollhook(double x, double y, void *param)
{
	t_info	*info;

	info = (t_info *)param;
	(void)x;
	if (y > 0)
		puts("Up!");
	else if (y < 0)
		puts("Down!");
}