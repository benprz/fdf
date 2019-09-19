/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_fdf.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 18:59:16 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 16:47:13 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

int		init_color(char *parse)
{
	int i;
	int j;

	i = 0;
	while (parse[i])
	{
		if (parse[i] == ',')
		{
			if (parse[i + 1] == '0' && parse[i + 2] == 'x')
			{
				i += 3;
				j = i;
				while (parse[j])
				{
					parse[j] = ft_toupper(parse[j]);
					j++;
				}
				return (ft_hextoint(parse + i));
			}
		}
		i++;
	}
	return (WHITE);
}

int		init_row(char *line, int r, t_map *map)
{
	char	**parse;
	int		i;
	int		j;

	if ((parse = ft_strsplit(line, ' ')))
	{
		i = r * map->cols;
		j = 0;
		while (parse[j])
		{
			map->p[i].x = calc_x(map, i);
			map->p[i].y = calc_y(map, i);
			map->p[i].z = ft_atoi(parse[j]);
			map->p[i].c.value = init_color(parse[j]);
			map->p[i].xm = map->p[i].x;
			map->p[i].ym = map->p[i].y;
			map->p[i].zm = map->p[i].z * map->elev;
			free(parse[j]);
			i++;
			j++;
		}
		free(parse);
		return (1);
	}
	return (0);
}

int		init_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		ret;
	int		i;

	fd = 0;
	if ((map->p = (t_p *)malloc(sizeof(t_p) * map->total)))
	{
		if ((fd = open(file, O_RDONLY)) >= 3)
		{
			i = 0;
			while ((ret = get_next_line(fd, &line)))
			{
				if (ret == -1 || !init_row(line, i, map))
					return (0);
				i++;
				free(line);
			}
			close(fd);
			return (1);
		}
	}
	return (0);
}

int		read_and_check(t_fdf *fdf, int fd)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (0);
		if (fdf->map->cols == 0)
			fdf->map->cols = ft_strlenwords(line);
		else if (ft_strlenwords(line) != fdf->map->cols)
		{
			free(line);
			ft_putendl("Rows must have the same length.");
			return (0);
		}
		fdf->map->rows++;
		free(line);
	}
	if (fdf->map->rows * fdf->map->cols < 2)
	{
		ft_putendl("Map must at least have 2 points.");
		return (0);
	}
	return (1);
}

int		init_fdf(char *file, t_fdf *fdf)
{
	int		fd;

	if ((fdf->map = (t_map *)malloc(sizeof(t_map))))
	{
		if ((fd = open(file, O_RDONLY)) >= 3)
		{
			fdf->map->rows = 0;
			fdf->map->cols = 0;
			fdf->map->elev = 0.2;
			fdf->map->proj = 0;
			fdf->map->x_rot = 0;
			fdf->map->y_rot = 0;
			fdf->map->z_rot = 0;
			fdf->map->p = NULL;
			if (!read_and_check(fdf, fd) || close(fd))
				return (0);
			fdf->map->total = fdf->map->rows * fdf->map->cols;
			fdf->map->zoom = (2.5 * HEIGHT / 4) / (double)fdf->map->rows;
			fdf->map->izoom = fdf->map->zoom;
			if (init_map(file, fdf->map))
				return (1);
		}
	}
	return (0);
}
