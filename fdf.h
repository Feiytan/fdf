#ifndef TEST_H
#define TEST_H
#define RGB 0xFF6633

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "/Users/laurick/includes/libft/libft.h"
#include "/Users/laurick/includes/minilibx_macos/mlx.h"

typedef	struct s_point
{
	int x;
	int y;
	int z;
}				t_point;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		x;
	int		y;
	double		xi;
	double		yi;
	double		xf;
	double		yf;
	int		dx;
	int		dy;
	int			xinc;
	int			yinc;
	int		wsizex;
	int		wsizey;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		color;
}			t_win;

void	get_line(t_win param);

#endif

/*
 * 126 = haut;
 * 123 = gauche;
 * 125 = bas;
 * 124 = droite;
 */
