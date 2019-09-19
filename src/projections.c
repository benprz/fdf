/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   projections.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/31 17:25:25 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 15:39:10 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

void	orthographic_projection(t_fdf *fdf)
{
	reset_points(fdf);
	rotate(fdf, 'x', fdf->map->x_rot);
	rotate(fdf, 'y', fdf->map->y_rot);
	rotate(fdf, 'z', fdf->map->z_rot);
	fdf->map->proj = 0;
}

void	isometric_projection(t_fdf *fdf)
{
	reset_points(fdf);
	rotate(fdf, 'z', 45);
	rotate(fdf, 'x', 60);
	fdf->map->proj = 1;
}

void	oblique_projection(t_fdf *fdf)
{
	reset_points(fdf);
	rotate(fdf, 'x', 60);
	rotate(fdf, 'y', -45);
	fdf->map->proj = 2;
}
