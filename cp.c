#include "fdf.h"

void		print_hori(int dx, int dy, int xinc, int yinc)
{
	int cumul;
	int i;

	i = 1;
	cumul = dx / 2;
	while (i++ <= dx)
}

void		get_line(t_win param)
{
	int dx,dy,i,xinc,yinc,cumul;
	param.x = param.xi;
	param.y = param.yi ;
	dx = param.xf - param.xi ;
	dy = param.yf - param.yi ;
	xinc = ( dx > 0 ) ? 1 : -1 ;
	yinc = ( dy > 0 ) ? 1 : -1 ;
	dx = abs(dx) ;
	dy = abs(dy) ;
	mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x, param.y, RGB);
	if (dx > dy)
	{
		cumul = dx / 2 ;
		for (i = 1 ; i <= dx ; i++ )
		{
			param.x += xinc ;
			cumul += dy ;
			if (cumul >= dx)
			{
				cumul -= dx;
				param.y += yinc;
			}
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x, param.y, RGB);
		}
	}
	else
	{
		cumul = dy / 2 ;
		for ( i = 1 ; i <= dy ; i++ )
		{
			param.y += yinc ;
			cumul += dx ;
			if ( cumul >= dy ) {
				cumul -= dy ;
				param.x += xinc ; }
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x, param.y, RGB);
		}
	}
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
