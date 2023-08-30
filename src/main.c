/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:15:01 by palucena          #+#    #+#             */
/*   Updated: 2023/08/30 17:54:02 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(int ac, char **av)
{
	t_info	*info;

	if (ac != 2)
	{
		if (ac <= 1 || ac == 3 || ac >= 5)
			error_msg();
		else if ((ac == 4 && check_name(av[1]) != 2))
			error_msg();
	}
	else if (check_name(av[1]) == 0)
		error_msg();
	info = create_window();
	init_fract(info, av);
	print_fractal(info);
	mlx_loop(info->mlx);
	mlx_delete_image(info->mlx, info->win);
	mlx_terminate(info->mlx);
	free(info);
	return (0);
}
