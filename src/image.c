/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:50:15 by palucena          #+#    #+#             */
/*   Updated: 2023/07/29 15:49:01 by palucena         ###   ########.fr       */
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
	// printf ("iterations: %d\n", n);
	if (n <= 5)
		color = get_rgba(229, 232, 232, 255); // blanco
	else if (n <= 10)
		color = get_rgba(204, 209, 209, 255);
	else if (n <= 15)
		color = get_rgba(178, 186, 187, 255);
	else if (n <= 20)
		color = get_rgba(153, 163, 164, 255);
	else if (n <= 25)
		color = get_rgba(127, 140, 141, 255);
	else if (n <= 30)
		color = get_rgba(112, 123, 124, 255);
	else if (n <= 35)
		color = get_rgba(97, 106, 107, 255);
	else if (n <= 40)
		color = get_rgba(81, 90, 90, 255);
	else if (n <= 45)
		color = get_rgba(66, 73, 73, 255);
	else
		color = get_rgba(0, 0, 0, 255); // negro
	mlx_put_pixel(info->win, info->pos_x, info->pos_y, color);
}
