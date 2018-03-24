#ifndef TEST_H
#define TEST_H
#define RGB 0xFF6633

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "/Users/laurick/github/libft/libft.h"
#include "/Users/laurick/includes/minilibx_macos/mlx.h"
#include <math.h>

typedef	struct s_point
{
	double x;
	double y;
	double z;
}				t_point;

typedef struct s_line
{
	char *line;
	struct s_line *next;
}				t_line;

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
	int		xplace;
	int		yplace;
	int			xinc;
	int			yinc;
	int		wsizex;
	int		wsizey;
	int img_sizex;
	int img_sizey;
	int		xmax;
	int		ymax;
	int		scale;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	unsigned int		color;
	int		zoom;
	t_point **tab;
}			t_win;

void	get_line(t_win param);
void	get_map(int fd, t_line *firstline, t_win *param);
int		deal_key(int keycode, t_win *param);
void	print_tab(t_win param, int xmax, int ymax);
void	print_map(t_win *param, int i, int j);
void	get_scaled_point(t_win *param, int i, int j);
void	align_points(t_win *param, int i, int j);
void	zoom(t_win *param, int i);
void	get_scaled_points(t_win *param, int i, int j);
void	print_data(t_win param);
#endif

/*
 * 126 = haut;
 * 123 = gauche;
 * 125 = bas;
 * 124 = droite;
 */
