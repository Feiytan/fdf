#include "fdf.h"

void		put_pixel_to_img(t_win param)
{
	char *temp = param.data;
	param.data = param.data + param.y * param.sizeline + param.x * param.bpp;
	if (param.data > temp && param.data < temp + (param.img_sizey - 1) * param.sizeline + (param.img_sizex - 1) * param.bpp)
	{
		*(int *)param.data = param.color;
	}
}

void		get_points(t_win *param)
{
	param->xi += param->img_sizex >> 1;
	param->yi = (param->img_sizey >> 1) - param->yi;
	param->xf += param->img_sizex >> 1;
	param->yf = (param->img_sizey >> 1) - param->yf;
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
		put_pixel_to_img(*param);
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
		put_pixel_to_img(*param);
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
	param.dx = abs(param.dx);
	param.dy = abs(param.dy);
	put_pixel_to_img(param);
	if (param.dx > param.dy)
		print_hori(&param, (param.dx >> 1), 1);
	else
		print_verti(&param, param.dy >> 1, 1);
}
