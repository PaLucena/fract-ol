#include "../includes/fractol.h"

int32_t	main(void)
{
	t_info		info;
	uint32_t	color;

	create_window(&info);
	color = get_rgba(255, 255, 255, 255);
	
	//mlx_put_pixel(info.win, info.size_x, info.size_y, color);
	while (info.size_y < HEIGHT)
	{
		info.size_x = 0;
		color = get_rgba(254, 254, 254, 0);
		if (info.size_y >= HEIGHT / 5 * 2 && info.size_y < HEIGHT / 5 * 3)
			color = get_rgba(255, 255, 255, 255); //0xFFFFFF;
		else
			color = get_rgba(143, 13, 13, 255); //0x8F0D0DFF;
		while (info.size_x < WIDTH)
		{
			mlx_put_pixel(info.win,  info.size_x, info.size_y, color);
			info.size_x++;
		}
		info.size_y++;
	}
	mlx_loop(info.mlx);
	mlx_delete_image(info.mlx, info.win);
	mlx_terminate(info.mlx);
	return (0);
}