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

void	moove(t_win *param, int keycode)
{
	printf("\nDecaleX = %d, decaleY = %d\n", param->xplace, param->yplace);
	int i = 0;
	int j = 0;
	while (i < param->ymax)
	{
		j = 0;
		while (j < param->xmax)
		{
			if (keycode == 126)
			{
				param->tab[i][j++].y += 10;
			}
			else if (keycode == 125)
			{
				param->tab[i][j++].y -= 10;
			}
			else if (keycode == 124)
			{
				param->tab[i][j++].x += 10;
			}
			else
			{
				param->tab[i][j++].x -= 10;
			}
		}
		i++;
	}
	if (keycode == 126)
	{
		param->yplace -= 10;
	}
	else if (keycode == 125)
	{
		param->yplace += 10;
	}
	else if (keycode == 124)
	{
		param->xplace -= 10;
	}
	else
	{
		param->xplace += 10;
	}
	printf("\nDecaleX = %d, decaleY = %d\n", param->xplace, param->yplace);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	param->img_ptr = mlx_new_image(param->mlx_ptr, param->img_sizex, param->img_sizey);
	param->data = mlx_get_data_addr(param->img_ptr, &param->bpp, &param->sizeline, &param->endian);
	param->bpp /= 8;
	print_map(param, 0, 0);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0);
}

void	zoom(t_win *param, int i)
{
	param->scale += i;
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	param->img_ptr = mlx_new_image(param->mlx_ptr, param->img_sizex, param->img_sizey);
	init_tab(param, 0, 0, 1);
	get_scaled_points(param, 0, 0);
	align_points(param, 0, 0);
	param->data = mlx_get_data_addr(param->img_ptr, &param->bpp, &param->sizeline, &param->endian);
	param->bpp /= 8;
	print_map(param, 0, 0);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr,
			0, 0);
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
	get_scaled_points(param, 0, 0);
	align_points(param, 0, 0);
	param->data = mlx_get_data_addr(param->img_ptr, &param->bpp, &param->sizeline, &param->endian);
	param->bpp /= 8;
	print_map(param, 0, 0);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr,
			0, 0);
}

int		deal_key(int keycode, t_win *param)
{
	ft_putnbr(keycode);
	if (keycode == 4 || keycode == 11)
		get_z(param, keycode);
	else if (keycode == 24)
		zoom(param, 2);
	else if(keycode == 27)
		zoom(param, -2);
	else if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
		moove(param, keycode);
	return (0);
}
