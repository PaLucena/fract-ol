/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:41:45 by palucena          #+#    #+#             */
/*   Updated: 2023/08/24 17:11:26 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	hook2(mlx_key_data_t keydata, t_info *info)
{
	if (keydata.key == MLX_KEY_O)
		info->max_iterations -= 5;
	if (keydata.key == MLX_KEY_P)
		info->max_iterations += 5;
	if (keydata.key == MLX_KEY_R)
		init_fract(info);
	if (keydata.key == MLX_KEY_F)
	{
		if (info->name == 3)
			info->name = 1;
		else
			info->name++;
		init_fract(info);
	}
}

void	hook(mlx_key_data_t keydata, void	*param)
{
	t_info			*info;
	double			c_offs;

	info = (t_info *)param;
	c_offs = LIMIT * info->zoom * 0.02;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
	//	mlx_delete_image(info->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_UP)
			info->offset_y += -c_offs;
 		if (keydata.key == MLX_KEY_DOWN)
			info->offset_y -= -c_offs;
		if (keydata.key == MLX_KEY_RIGHT)
			info->offset_x += c_offs;
		if (keydata.key == MLX_KEY_LEFT)
			info->offset_x -= c_offs;
		else
			hook2(keydata, info);
	}
	print_fractal(info);
}

/* void	my_keyhook(mlx_key_data_t mlx_keydata, void *param)
{
	t_info			*info;

	info = (t_info *)param;
	if (mlx_keydata.action == MLX_RELEASE)
		info->keydata.key = mlx_keydata.key;
} // Versión 2 */

/* void	 zoom(t_info *info, int direc)
{
	if (direc > 0)
	{
		printf("%f\n", info->zoom);
		info->zoom -= 0.1;
		puts("Zoom in");
	}
	else
	{
		info->zoom += 0.1;
		puts("Zoom out");
	}
} */

void	my_scrollhook(double x, double y, void *param)
{
	t_info	*info;

	info = (t_info *)param;
	(void)x;
	if (y > 0)
		info->zoom /= 1.1;
	else
		info->zoom *= 1.1;
	print_fractal(info);
}
