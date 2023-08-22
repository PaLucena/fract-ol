/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:38:50 by palucena          #+#    #+#             */
/*   Updated: 2023/08/22 16:59:00 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define WIDTH 1024
#define HEIGHT 1024

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <math.h>
# include "libft/libft.h"
# include "../includes/MLX42/include/MLX42/MLX42.h"

typedef struct s_info
{
	mlx_t					*mlx; // instance
	mlx_image_t				*win; // image
	int32_t					pos_x; // valor de x en la ventana
	int32_t					pos_y; // valor de y en la ventana
	double					zx;
	double					zy;
	double					zoom;
	int						max_iterations;
//	struct mlx_key_data		keydata;
}			t_info;

/*				fractal.c				*/
void		fractal(char	*av, t_info *info);

/*				hooks.c					*/
void		hook(mlx_key_data_t keydata, void *param);
//void		my_keyhook(mlx_key_data_t mlx_keydata, void *param);
void		my_scrollhook(double x, double y, void *param);

/*				image.c					*/
void		draw_pixel(t_info	*info, int	n);

/*				init.c					*/
void		create_window(t_info *info);


#endif