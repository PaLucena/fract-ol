/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:38:50 by palucena          #+#    #+#             */
/*   Updated: 2023/07/26 18:40:18 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define WIDTH 1024
#define HEIGHT 512

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
	mlx_t					*mlx;
	mlx_image_t				*win;
	int32_t					size_x;
	int32_t					size_y;
	int						iterations;
	struct mlx_key_data		keydata;
}			t_info;

/*				fractal.c				*/
void		fractal(char	*av, t_info *info);
/*				hooks.c					*/
void		hook(void *param);
void		my_keyhook(mlx_key_data_t mlx_keydata, void *param);
void		my_scrollhook(double x, double y, void *param);


#endif