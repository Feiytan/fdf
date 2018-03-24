#include "fdf.h"

//NE PAS OUBLIER DE FREE LA LISTE

void	print_tab(t_win param, int xmax, int ymax)
{
	int i;
	int j;

	i = 0;
	while (i < ymax)
	{
		j = 0;
		while (j < xmax)
		{
			printf("x = %f, y = %f, z = %f\n", param.tab[i][j].x, param.tab[i][j].y, param.tab[i][j].z);
			j++;
		}
		i++;
	}
}

int		nb_pointers(char **pointer)
{
	int i;

	i = 0;
	while (*pointer++)
		i++;
	return (i);
}

void	split_line(t_line *line, int size, t_win *param)
{
	char **line_split;
	int nb_char;

	param->ymax = 0;
	if(!(param->tab = malloc(sizeof(t_point *)  * size)))
		ft_error("malloc error");
	while (param->ymax < size)
	{
		line_split = ft_strsplit(line->line, ' ');
		nb_char = nb_pointers(line_split);
		if(!(param->tab[param->ymax] = malloc(sizeof(t_point) * nb_char)))
			ft_error("malloc error");
		param->xmax = 0;
		while (*line_split)
		{
			param->tab[param->ymax][param->xmax].x = param->xmax;
			param->tab[param->ymax][param->xmax].y = param->ymax * - 1;
			param->tab[param->ymax][param->xmax].z = ft_atoi(*line_split++);
			(param->xmax)++;
		}
		(param->ymax)++;
		line = line->next;
	}
}

t_line	*get_new_line(t_line *line)
{
	t_line	*newline;

	if (!(newline = malloc(sizeof(t_line))))
		ft_error("malloc error0");
	newline->next = NULL;
	line->next = newline;
	return(newline);
}

void		get_map(int fd, t_line *firstline, t_win *param)
{
	t_line *line;
	char *temp;
	int i;

	i = 0;
	line = firstline;
	while (get_next_line(fd, &temp))
	{
		if (ft_strlen(temp) && i == 0)
		{
			firstline->line = temp;
			i++;
		}
		else if (ft_strlen(temp))
		{
			line = get_new_line(line);
			line->line = temp;
			i++;
		}
	}
	split_line(firstline, i, param);
}
