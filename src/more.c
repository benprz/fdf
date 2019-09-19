/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   more.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/13 15:23:17 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 20:27:57 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

void	edit_elevation(t_fdf *fdf, int elev)
{
	t_map	*map;

	map = fdf->map;
	if (elev == 1)
		map->elev += 0.05;
	else
		map->elev -= 0.05;
	if (map->proj == 0)
		orthographic_projection(fdf);
	else if (map->proj == 1)
		isometric_projection(fdf);
	else if (map->proj == 2)
		oblique_projection(fdf);
}

void	put_string(t_fdf *fdf, int x, int y, char *str)
{
	mlx_string_put(fdf->mlx, fdf->win, x, y, WHITE, str);
}

void	put_string2(t_fdf *fdf, int x, int y, char *str)
{
	mlx_string_put(fdf->mlx, fdf->win, x, y, WHITE, str);
	free(str);
}

void	display_hud(t_fdf *fdf)
{
	put_string(fdf, 20, HEIGHT - 190, "total = ");
	put_string2(fdf, 105, HEIGHT - 190, ft_itoa(fdf->map->total));
	put_string(fdf, 20, HEIGHT - 165, "rows  = ");
	put_string2(fdf, 105, HEIGHT - 165, ft_itoa(fdf->map->rows));
	put_string(fdf, 20, HEIGHT - 140, "cols  = ");
	put_string2(fdf, 105, HEIGHT - 140, ft_itoa(fdf->map->cols));
	put_string(fdf, 20, HEIGHT - 115, "zoom  = ");
	put_string2(fdf, 105, HEIGHT - 115, ft_itoa(fdf->map->zoom));
	put_string(fdf, 20, HEIGHT - 90, "x_rot = ");
	put_string2(fdf, 105, HEIGHT - 90, ft_itoa(fdf->map->x_rot));
	put_string(fdf, 20, HEIGHT - 65, "y_rot = ");
	put_string2(fdf, 105, HEIGHT - 65, ft_itoa(fdf->map->y_rot));
	put_string(fdf, 20, HEIGHT - 40, "z_rot = ");
	put_string2(fdf, 105, HEIGHT - 40, ft_itoa(fdf->map->z_rot));
}
