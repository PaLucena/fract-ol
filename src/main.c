/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:15:01 by palucena          #+#    #+#             */
/*   Updated: 2023/08/21 18:40:30 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int32_t	main(int ac, char **av)
{
	t_info	info;

	if (ac < 2)
	{
	//	ft_putstr_fd("Esta mal", 1);	-	-	-	-	PQ NO FUNCIONA LIBFT??
		printf("\tQue fractal??");
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
