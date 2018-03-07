#include "fdf.h"

//NE PAS OUBLIER DE FREE LA STRUCTURE

void	print_tab(t_point **tab)
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			printf("x = %d, j = %d, z = %d\n", tab[i][j].x, tab[i][j].y, tab[i][j].z);
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

t_point		**split_line(t_line *line, int size, int *xmax, int *ymax)
{
	char **line_split;
	t_point  **tab;
	int nb_char;

	*ymax = 0;
	if(!(tab = malloc(sizeof(t_point *)  * size)))
		ft_error("malloc error");
	while (*ymax < size)
	{
		line_split = ft_strsplit(line->line, ' ');
		nb_char = nb_pointers(line_split);
		if(!(tab[*ymax] = malloc(sizeof(t_point) * nb_char)))
			ft_error("malloc error");
		*xmax = 0;
		while (*line_split)
		{
			tab[*ymax][*xmax].x = *xmax;
			tab[*ymax][*xmax].y = *ymax;
			tab[*ymax][*xmax].z = ft_atoi(*line_split++);
			(*xmax)++;
		}
		(*ymax)++;
		line = line->next;
	}
	(*xmax)--;
	(*ymax)--;
	return (tab);
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

int		get_map(int fd, t_line *firstline)
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
	return (i);
}

int		main(int argc, char **argv)
{
	int fd;
	t_line firstline;
	t_line *line;
	int size = 0;
	int xmax;
	int ymax;
	t_point **tab;

	line = &firstline;
	firstline.next = NULL;
	if (argc != 2)
		ft_error("nb arg");
	if ((fd = open(argv[1], O_RDONLY)) != 3)
		ft_error("Erreur fichier");
	size = get_map(fd, &firstline);
//	ft_putnbr(size);
//	while (size--)
//	{
//		ft_putstr("line = ");
//		ft_putendl(line->line);
//		line = line->next;
//	}
	tab = split_line(&firstline, size, &xmax, &ymax);
	ft_putnbr(xmax);
	ft_putchar('\n');
	ft_putnbr(ymax);
//	print_tab(tab);
	return (0);
}
