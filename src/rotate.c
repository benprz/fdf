/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotate.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 09:25:31 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 15:42:31 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

void	rotate_x(t_fdf *fdf, int deg)
{
	t_map	*map;
	int		i;
	double	rad;

	map = fdf->map;
	map->x_rot += deg;
	i = 0;
	rad = (double)deg * M_PI / 180;
	while (i != map->total)
	{
		map->p[i].ym = (map->p[i].ym * cos(rad) + (map->p[i].zm * -sin(rad)));
		map->p[i].zm = (map->p[i].ym * sin(rad) + (map->p[i].zm * cos(rad)));
		i++;
	}
}

void	rotate_y(t_fdf *fdf, int deg)
{
	t_map	*map;
	int		i;
	double	rad;

	map = fdf->map;
	map->y_rot += deg;
	i = 0;
	rad = (double)deg * M_PI / 180;
	while (i != map->total)
	{
		map->p[i].xm = (map->p[i].xm * cos(rad) + (map->p[i].zm * sin(rad)));
		map->p[i].zm = (map->p[i].xm * -sin(rad) + (map->p[i].zm * cos(rad)));
		i++;
	}
}

void	rotate_z(t_fdf *fdf, int deg)
{
	t_map	*map;
	int		i;
	double	rad;

	map = fdf->map;
	map->z_rot += deg;
	i = 0;
	rad = (double)deg * M_PI / 180;
	while (i != map->total)
	{
		map->p[i].xm = (map->p[i].xm * cos(rad) + (map->p[i].ym * -sin(rad)));
		map->p[i].ym = (map->p[i].xm * sin(rad) + (map->p[i].ym * cos(rad)));
		i++;
	}
}

void	rotate(t_fdf *fdf, char axis, int deg)
{
	int i;
	int sign;

	i = 0;
	sign = deg > 0 ? 1 : -1;
	while (i < ft_abs(deg))
	{
		if (axis == 'x')
			rotate_x(fdf, sign);
		if (axis == 'y')
			rotate_y(fdf, sign);
		if (axis == 'z')
			rotate_z(fdf, sign);
		i++;
	}
}
