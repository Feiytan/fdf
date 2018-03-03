#ifndef TEST_H
#define TEST_H
#define RGB 0xFF6633
#define YMAX 4
#define XMAX 4

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "/Users/lbaumann/includes/libft/libft.h"
#include "/Users/lbaumann/includes/minilibx_macos/mlx.h"

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
	int		xi;
	int		yi;
	int		xf;
	int		yf;
	int		dx;
	int		dy;
	int		xinc;
	int		yinc;
	char	*date;
	int		bpp;
	int		sizeline;
	int		endian;
	int		color;
	char	*data;
}			t_win;

#endif

/*
 * 126 = haut;
 * 123 = gauche;
 * 125 = bas;
 * 124 = droite;
 */
