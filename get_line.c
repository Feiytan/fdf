#include "fdf.h"

void		get_points(t_win *param)
{
	param->xi += param->wsizex / 2;
	param->yi = param->wsizey / 2 - param->yi;
	param->xf += param->wsizex / 2;
	param->yf = param->wsizey / 2 - param->yf;
}

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
	get_points(&param);
	param.x = (int)param.xi;
	param.y = (int)param.yi;
	param.dx = (int)param.xf - (int)param.xi;
	param.dy = (int)param.yf - (int)param.yi;
	param.xinc = (param.dx > 0) ? 1 : -1;
	param.yinc = ( param.dy > 0 ) ? 1 : -1 ;
	param.dx = abs(param.dx) ;
	param.dy = abs(param.dy) ;
	mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x, param.y, RGB);
	if (param.dx > param.dy)
		print_hori(&param, param.dx / 2, 1);
	else
		print_verti(&param, param.dy / 2, 1);
}
