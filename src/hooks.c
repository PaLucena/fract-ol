/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:41:45 by palucena          #+#    #+#             */
/*   Updated: 2023/08/24 12:45:04 by palucena         ###   ########.fr       */
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
		if (keydata.key == MLX_KEY_O)
			info->max_iterations -= 5;
		if (keydata.key == MLX_KEY_P)
			info->max_iterations += 5;
		if (keydata.key == MLX_KEY_UP)
			info->offset_y += 0.1;
 		if (keydata.key == MLX_KEY_DOWN)
			info->offset_y -= 0.1;
		if (keydata.key == MLX_KEY_RIGHT)
			info->offset_x += 0.1;
		if (keydata.key == MLX_KEY_LEFT)
			info->offset_x -= 0.1;
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
		info->zoom -= 0.1;
	else
		info->zoom += 0.1;
/* 	if (y > 0)
		info->max_iterations++;
	else
		info->max_iterations--; */
	printf("Zoom: %f\n", info->zoom);
	print_fractal(info);
}

/* void	my_mousehook(mouse_key_t m_code, action_t x, modifier_key_t y, void *param)
{
	t_info *info;

	info = (t_info *)param;
	(void)y;
	ft_printf("hola\n");
	if (m_code == 0 && x == 1) // ARRIBA
		zoom(info, 1);
	else if (m_code == 1)
		zoom(info, -1);
	print_fractal(info);
} */
