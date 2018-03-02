#include "fdf.h"

void		print_hori(t_win *param, int cumul, int i)
{
	while (i++ <= param->dx)
	{
		param->x += param->xinc;
		cumul += param->dy;
		if (cumul >= param->dx)
		{
			cumul -= param->dx;
			param->y += param->yinc;
		}
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->x, param->y, RGB);
	}
}

void		print_verti(t_win *param, int cumul, int i)
{
	while (i++ <= param->dy)
	{
		param->y += param->yinc;
		cumul += param->dx;
		if (cumul >= param->dy)
		{
			cumul -= param->dy;
			param->x += param->xinc;
		}
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->x, param->y, RGB);
		}
}

void		get_line(t_win param)
{
	int dx,dy,i,xinc,yinc,cumul;
	param.x = param.xi;
	param.y = param.yi;
	param.dx = param.xf - param.xi;
	param.dy = param.yf - param.yi;
	param.xinc = (param.dx > 0) ? 1 : -1;
	param.yinc = ( param.dy > 0 ) ? 1 : -1 ;
	param.dx = abs(param.dx) ;
	param.dy = abs(param.dy) ;
	mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x, param.y, RGB);
	if (param.dx > param.dy)
		print_hori(&param, dx / 2, 1);
	else
		print_verti(&param, dy / 2, 1);
}

int		main(int argc, char **argv)
{
	t_win param;

	if (argc != 5)
		error("nb arg");
	param.xi = atoi(argv[1]);
	param.yi = atoi(argv[2]);
	param.xf = atoi(argv[3]);
	param.yf = atoi(argv[4]);
	printf("%d\n", param.xi);
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, 1100, 700, "window");
	get_line(param);
	mlx_loop(param.mlx_ptr);
}
