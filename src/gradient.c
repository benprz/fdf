/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gradient.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/17 19:09:20 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 16:46:45 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

double	calc_percent(int start, int end, int current)
{
	double index;
	double delta;

	index = current - start;
	delta = end - start;
	return ((!delta) ? 1.0 : (index / delta));
}

int		calc_color(int start, int end, double percent)
{
	return (start + percent * (end - start));
}

int		color_gradient(t_fdf *fdf, t_line line)
{
	t_rgb	color;
	t_rgb	c1;
	t_rgb	c2;
	double	percent;

	c1.value = fdf->map->p[line.p1].c.value;
	c2.value = fdf->map->p[line.p2].c.value;
	color.value = 0;
	if (c1.value == c2.value)
		return (c1.value);
	if (line.dx > line.dy)
		percent = calc_percent(line.x1, line.x2, line.cx);
	else
		percent = calc_percent(line.y1, line.y2, line.cy);
	color.byte[R] = calc_color(c1.byte[R], c2.byte[R], percent);
	color.byte[G] = calc_color(c1.byte[G], c2.byte[G], percent);
	color.byte[B] = calc_color(c1.byte[B], c2.byte[B], percent);
	return (color.value);
}
