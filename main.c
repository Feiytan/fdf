#include "fdf.h"

void	print_data(t_win param)
{
	printf("data = %p\n", param.data);
	printf("color = %d\n", param.color);
	printf("bpp = %d\n", param.bpp);
	printf("sizeline = %d\n", param.sizeline);
	printf("endian = %d\n", param.endian);
}

int		main(int argc, char **argv)
{
	t_win param;
	t_line line;
	int fd;

	if (argc != 2)
		ft_error("nb arg");
	if ((fd = open(argv[1], O_RDONLY)) != 3)
		ft_error("FD error");
	param.wsizex = 1000;
	param.wsizey = 600;
	param.img_sizex = 1000;
	param.img_sizey = 600;
	param.xplace = (param.wsizex - param.img_sizex) >> 1;
	param.yplace = (param.wsizey - param.img_sizey) >> 1;
	get_map(fd, &line, &param);
//	ft_putnbr(param.xmax);
//	ft_putchar('\n');
//	ft_putnbr(param.ymax);
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.wsizex, param.wsizey, "1");
	param.img_ptr = mlx_new_image(param.mlx_ptr, param.img_sizex, param.img_sizey);
	param.color = mlx_get_color_value(param.mlx_ptr, 0xff2020);
	get_scaled_points(&param, 0, 0);
	align_points(&param, 0, 0);
	param.data = mlx_get_data_addr(param.img_ptr, &param.bpp, &param.sizeline, &param.endian);
	print_data(param);
	param.bpp /= 8;
	print_map(&param, 0, 0);
//	print_tab(param, param.xmax, param.ymax);
	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, param.img_ptr, param.xplace, param.yplace);
	mlx_key_hook(param.win_ptr, deal_key, &param);
	mlx_loop(param.mlx_ptr);
}
