#include "fdf.h"

void	init_tab(t_win *param, int i, int j, double zoom)
{
	while (i < param->ymax)
	{
		j = 0;
		while (j < param->xmax)
		{
			param->tab[i][j].x = j;
			param->tab[i][j].y = i * -1;
			param->tab[i][j++].z *= zoom;
		}
		i++;
	}
	print_tab(*param, 0, 0);
}

void	get_z(t_win *param, int keycode)
{
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	param->img_ptr = mlx_new_image(param->mlx_ptr, param->img_sizex, param->img_sizey);
	if (keycode == 4)
		init_tab(param, 0, 0, 1.1);
	else
		init_tab(param, 0, 0, 0.9);
//	print_tab(*param, param->xmax, param->xmax);
	ft_putchar('a');
	get_scaled_points(param, 0, 0);
	align_points(param, 0, 0);
	param->data = mlx_get_data_addr(param->img_ptr, &param->bpp, &param->sizeline, &param->endian);
	param->bpp /= 8;
	print_map(param, 0, 0);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr,
	param->xplace, param->yplace);
}

int		deal_key(int keycode, t_win *param)
{
	ft_putnbr(keycode);
	if (keycode == 4 || keycode == 11)
		get_z(param, keycode);
	return (0);
}
