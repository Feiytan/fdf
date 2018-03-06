#include "/Users/laurick/includes/libft/libft.h"
#include "/Users/laurick/includes/libft/fdf.h"
#include <math.h>

void	print_sys(t_win param)
{
	param.xi = -(param.wsizex / 2);
	param.yi = 0;
	param.xf = param.wsizex / 2;
	param.yf = 0;
	get_line(param);
	param.xi = 0;
	param.yi = param.wsizey / 2;
	param.xf = 0;
	param.yf = -(param.wsizey / 2);
	get_line(param);
	param.xi = -param.wsizex / 2;
	param.yi = 200;
	param.xf = param.wsizex / 2;
	param.yf = 200;
	get_line(param);
}

void	rot(t_win *param)
{
	int i;
	double  tab[3] = {param->xi, param->yi, 0};
	double tab2[3];
	double mr1[3][3] = {{cos(0.178), -sin(0.178), 0}, {sin(0.178), cos(0.178), 0}, {0, 0, 1}};
	i = 0;
	while (i < 3)
	{
		tab2[i] = tab[0] * mr1[i][0] + tab[1] * mr1[i][1] + tab[2] * mr1[i][2];
		i++;
	}
	param->xi = tab2[0];
	param->yi = tab2[1];
}

int		deal_key(int keycode, t_win *param)
{
	
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	print_sys(*param);
	rot(param);
	get_line(*param);
	return (0);
}

int		main(int argc, char **argv)
{
	t_win param;

	if (argc != 5)
		error("Error : nb arg");
	param.wsizex = 1000;
	param.wsizey = 700;
	param.xi = (double)atoi(argv[1]);
	param.yi = (double)atoi(argv[2]);
	param.xf = (double)atoi(argv[3]);
	param.yf = (double)atoi(argv[4]);
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.wsizex, param.wsizey, "win1");
	mlx_key_hook(param.win_ptr, deal_key, &param);
	print_sys(param);
	get_line(param);
	mlx_loop(param.mlx_ptr);
	return (0);
}
