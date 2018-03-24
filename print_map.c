#include "fdf.h"

void	align_points(t_win *param, int i, int j)
{
	int decalex = ((int)param->tab[0][param->xmax - 1].x - (int)param->tab[param->ymax - 1][0].x) >> 1;
	int decaley = param->tab[param->ymax - 1][param->xmax - 1].y / 2;
	decalex += param->tab[param->ymax  - 1][0].x;
	i = 0;
	while (i < param->ymax)
	{
		j = 0;
		while (j < param->xmax)
			param->tab[i][j++].y -= decaley;
		i++;
	}
	i = 0;
	while(i < param->ymax)
	{
		j = 0;
		while (j < param->xmax)
			param->tab[i][j++].x -= decalex;
	i++;
	}
}

void	print_sys(t_win param)
{
	//	ft_putnbr(param.img_sizey);
	param.xi = (param.img_sizex >> 1) - 1;
	param.yi = 0;
	param.yf = 0;
	param.xf = ((param.img_sizex >> 1) - 1) * -1;
	get_line(param);
	param.xi = 0;
	param.yi = (param.img_sizey >> 1) - 1;
	param.xf = 0;
	param.yf = ((param.img_sizey >> 1) - 1) * -1;
	get_line(param);
}

void	get_scaled_points(t_win *param, int i, int j)
{
	int temp;
	if (param->img_sizex / param->xmax > param->img_sizey / param->ymax)
		param->scale = param->img_sizey / param->ymax  >> 1;
	else
		param->scale = param->img_sizex / param->xmax >> 1;
	while (i < param->ymax)
	{
		j = 0;
		while (j < param->xmax)
		{
			param->tab[i][j].x *= param->scale;
			param->tab[i][j].y *= param->scale;
			temp = param->tab[i][j].x;
			param->tab[i][j].x -= param->tab[i][j].y;
			param->tab[i][j].y = ((temp + (int)param->tab[i][j].y) >> 1) + param->tab[i][j].z * param->scale;
			j++;
		}
		i++;
	}
}

void	print_map(t_win *param, int i, int j)
{
	while (i < param->ymax)
	{
		j = 0;
		while (j < param->xmax)
		{
			param->xf = param->tab[i][j].x;
			param->yf = param->tab[i][j].y;
			if (j != 0)
			{
				param->xi = param->tab[i][j - 1].x;
				param->yi = param->tab[i][j - 1].y;
				get_line(*param);
			}
			if (i != 0)
			{
				param->xi = param->tab[i - 1][j].x;
				param->yi = param->tab[i - 1][j].y;
				get_line(*param);
			}
			j++;
		}
		i++;
	}
}
