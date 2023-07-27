/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:50:15 by palucena          #+#    #+#             */
/*   Updated: 2023/07/27 17:17:05 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

uint32_t get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
} 

void	draw_pixel(t_info	*info, int	n)
{
	uint32_t	color;

	if (n == info->max_iterations)
		color = get_rgba(255, 255, 255, 255);
	else
		color = get_rgba(0, 0, 0, 255);
	mlx_put_pixel(info->win, info->pos_x, info->pos_y, color);
}
