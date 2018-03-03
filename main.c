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

void		get_line(t_win *param)
{
	param->x = param->xi;
	param->y = param->yi;
	param->dx = param->xf - param->xi;
	param->dy = param->yf - param->yi;
	param->xinc = (param->dx > 0) ? 1 : -1;
	param->yinc = ( param->dy > 0 ) ? 1 : -1 ;
	param->dx = abs(param->dx) ;
	param->dy = abs(param->dy) ;
	mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->x, param->y, RGB);
	if (param->dx >= param->dy)
		print_hori(param, param->dx / 2, 1);
	else
		print_verti(param, param->dy / 2, 1);
}

void		getmap(char *file, t_point tab[YMAX + 1][XMAX + 1])
{
	int fd;
	char *line;
	char **dline;
	int i;
	int size;

	size = 0;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	dline = ft_strsplit(line, ' ');
	printf("%s", *dline);
	ft_putnbr(size);
	free(line);
}

void		getmap2(t_point tab[YMAX + 1][XMAX + 1], int i, int j)
{
	int x_start = 650;
	int y_start = -100;
	int tempx;
	while (i < YMAX + 1)
	{
		j = 0;
		while (j < XMAX + 1)
		{
			tab[i][j].x = (x_start + 100 * j);
			tempx = tab[i][j].x;
			tab[i][j].y = y_start + 100 * i;
			tab[i][j].x = tempx - tab[i][j].y;
			tab[i][j].y = (tempx + tab[i][j].y) / 2;
			if (j == 1)
				tab[i][j].y += 42;
		printf("tab[%d][%d], x = %d, y = %d.  ", i, j, tab[i][j].x, tab[i][j].y);
			j++;
		}
		i++;
	}
	ft_putchar('\n');
}



void		print_map(t_win *param, t_point tab[YMAX + 1][XMAX + 1])
{
	int i;
	int j;

	i = 0;
	while (i < YMAX + 1)
	{
		j = 0;
		while (j < XMAX + 1)
		{
			if (j != 0)
			{
				param->xi = tab[i][j - 1].x;
				param->yi = tab[i][j - 1].y;
				param->xf = tab[i][j].x;
				param->yf = tab[i][j].y;
				get_line(param);
			}
			if (i != 0)
			{
				param->xi = tab[i][j].x;
				param->yi = tab[i][j].y;
				param->xf = tab[i - 1][j].x;
				param->yf = tab[i - 1][j].y;
				get_line(param);
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_win param;
	t_point tab[YMAX + 1][XMAX + 1];
	getmap(argv[1], tab);
//	get_map2(tab, 0, 0);
//	param.mlx_ptr = mlx_init();
//	param.win_ptr = mlx_new_window(param.mlx_ptr, 1500, 1000, "window");
//	print_map(&param, tab);
//	mlx_loop(param.mlx_ptr);
}
