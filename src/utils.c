/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/26 18:02:24 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 15:39:21 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

int		calc_x(t_map *map, int i)
{
	return ((i % map->cols - map->cols / 2));
}

int		calc_y(t_map *map, int i)
{
	return ((i / map->cols - map->rows / 2));
}

void	pixel_put(t_fdf *fdf, int x, int y, int c)
{
	int		i;
	t_rgb	color;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		i = (y * fdf->sl) + (x * 4);
		color.value = c;
		fdf->img_data[i] = color.byte[B];
		fdf->img_data[i + 1] = color.byte[G];
		fdf->img_data[i + 2] = color.byte[R];
	}
}

void	clear_map(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = WIDTH * HEIGHT;
	while (i < j)
	{
		pixel_put(fdf, i % WIDTH, i / WIDTH, 0);
		i++;
	}
}

void	reset_points(t_fdf *fdf)
{
	t_map	*map;
	int		i;

	map = fdf->map;
	i = 0;
	while (i < map->total)
	{
		map->p[i].xm = map->p[i].x;
		map->p[i].ym = map->p[i].y;
		map->p[i].zm = map->p[i].z * map->elev;
		i++;
	}
	fdf->map->x_rot = 0;
	fdf->map->y_rot = 0;
	fdf->map->z_rot = 0;
}
