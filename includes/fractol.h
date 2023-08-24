/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:38:50 by palucena          #+#    #+#             */
/*   Updated: 2023/08/24 16:56:36 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define WIDTH 600
#define HEIGHT 600
#define LIMIT 2.0

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
	int						name;
	mlx_t					*mlx; // instance
	mlx_image_t				*win; // image
	int32_t					pos_x; // valor de x en la ventana
	int32_t					pos_y; // valor de y en la ventana
	double					zx;
	double					zy;
	double					zoom;
	double					offset_x;
	double					offset_y;
	int						max_iterations;
//	struct mlx_key_data		keydata;
}			t_info;



/*				fractal.c				*/
void	print_fractal(t_info *info);

/*				hooks.c					*/
void		hook(mlx_key_data_t keydata, void *param);
//void		my_keyhook(mlx_key_data_t mlx_keydata, void *param);
void		my_scrollhook(double x, double y, void *param);
//void	my_mousehook(mouse_key_t m_code, action_t x, modifier_key_t y, void *param);
/*				image.c					*/
void		draw_pixel(t_info *info, int	n);

/*				init.c					*/
void		init_fract(t_info *info);
t_info		*create_window(char *name);

/*				utils.c					*/
int			check_name(char *name);
void		error_msg(void);
//double		ft_atof(char *nb);


#endif