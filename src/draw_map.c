/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 17:38:22 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 15:38:52 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_straight_line(t_fdf *fdf, t_line line)
{
	if (line.dy == 0)
	{
		if (line.x2 < line.x1)
			ft_swap(&line.x1, &line.x2);
		line.cx = line.x1;
		while (line.cx <= line.x2)
		{
			pixel_put(fdf, line.cx, line.y1, color_gradient(fdf, line));
			line.cx++;
		}
	}
	else
	{
		if (line.y2 < line.y1)
			ft_swap(&line.y1, &line.y2);
		line.cy = line.y1;
		while (line.cy <= line.y2)
		{
			pixel_put(fdf, line.x1, line.cy, color_gradient(fdf, line));
			line.cy++;
		}
	}
}

void	draw_line_horizontally(t_fdf *fdf, t_line line)
{
	if (line.x2 < line.x1)
	{
		ft_swap(&line.y1, &line.y2);
		ft_swap(&line.x1, &line.x2);
	}
	line.cx = line.x1;
	while (line.cx != line.x2)
	{
		line.cy = line.dy / line.dx * line.cx + line.b;
		pixel_put(fdf, line.cx, line.cy, color_gradient(fdf, line));
		line.cx++;
	}
}

void	draw_line_vertically(t_fdf *fdf, t_line line)
{
	if (line.y2 < line.y1)
	{
		ft_swap(&line.y1, &line.y2);
		ft_swap(&line.x1, &line.x2);
	}
	line.cy = line.y1;
	while (line.cy <= line.y2)
	{
		line.cx = (line.cy - line.b) / (line.dy / line.dx);
		pixel_put(fdf, line.cx, line.cy, color_gradient(fdf, line));
		line.cy++;
	}
}

void	draw_line(t_fdf *fdf, int p1, int p2)
{
	t_line	line;

	line = fdf->line;
	line.p1 = p1;
	line.p2 = p2;
	line.x1 = fdf->map->p[p1].xm * fdf->map->zoom + WIDTH / 2;
	line.y1 = fdf->map->p[p1].ym * fdf->map->zoom + HEIGHT / 2;
	line.x2 = fdf->map->p[p2].xm * fdf->map->zoom + WIDTH / 2;
	line.y2 = fdf->map->p[p2].ym * fdf->map->zoom + HEIGHT / 2;
	line.dx = line.x2 - line.x1;
	line.dy = line.y2 - line.y1;
	line.b = line.y1 - (line.dy / line.dx) * line.x1;
	if (line.dx == 0 || line.dy == 0)
		draw_straight_line(fdf, line);
	else if (ft_abs(line.dy) <= ft_abs(line.dx))
		draw_line_horizontally(fdf, line);
	else
		draw_line_vertically(fdf, line);
}

void	draw_map(t_fdf *fdf)
{
	int		i;
	t_map	*map;

	i = 0;
	map = fdf->map;
	clear_map(fdf);
	while (i < map->total)
	{
		if ((i + 1) % map->cols)
			draw_line(fdf, i, i + 1);
		if (i < map->total - map->cols)
			draw_line(fdf, i, i + map->cols);
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	display_hud(fdf);
}
