/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/25 12:02:51 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 17:36:40 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

int		exit_fdf(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		key_press2(int keycode, t_fdf *fdf)
{
	if (keycode == 18)
		orthographic_projection(fdf);
	if (keycode == 19)
		isometric_projection(fdf);
	if (keycode == 20)
		oblique_projection(fdf);
	if (keycode == 24)
		edit_elevation(fdf, 1);
	if (keycode == 27)
		edit_elevation(fdf, -1);
	draw_map(fdf);
	return (0);
}

int		key_press(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		exit_fdf(NULL);
	if (keycode == 13)
		rotate_x(fdf, 1);
	if (keycode == 1)
		rotate_x(fdf, -1);
	if (keycode == 2)
		rotate_y(fdf, 1);
	if (keycode == 0)
		rotate_y(fdf, -1);
	if (keycode == 14)
		rotate_z(fdf, 1);
	if (keycode == 12)
		rotate_z(fdf, -1);
	if (keycode == 69)
		fdf->map->zoom *= 1.05;
	if (keycode == 78)
		fdf->map->zoom /= 1.05;
	if (keycode == 67)
		fdf->map->zoom = fdf->map->izoom;
	if (keycode >= 18 && keycode <= 27)
		key_press2(keycode, fdf);
	draw_map(fdf);
	return (0);
}

void	free_fdf(t_fdf *fdf)
{
	if (fdf)
	{
		if (fdf->map)
		{
			if (fdf->map->p)
				free(fdf->map->p);
			free(fdf->map);
		}
		free(fdf);
	}
}

int		main(int ac, char *av[])
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		if ((fdf = (t_fdf *)malloc(sizeof(t_fdf))) && init_fdf(av[1], fdf))
		{
			if ((fdf->mlx = mlx_init()))
			{
				fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, av[1]);
				fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
				fdf->img_data = mlx_get_data_addr(fdf->img, &fdf->bpp,\
						&fdf->sl, &fdf->ed);
				draw_map(fdf);
				mlx_hook(fdf->win, 2, 1L << 0, key_press, fdf);
				mlx_hook(fdf->win, 17, 1L << 17, exit_fdf, NULL);
				mlx_loop(fdf->mlx);
			}
		}
		free_fdf(fdf);
	}
	else
		ft_putendl("usage: ./fdf sample_file");
	return (0);
}
