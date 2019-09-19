/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/25 11:42:11 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 17:03:44 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/gnl/get_next_line.h"
# include "minilibx_macos/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080
# define R 2
# define G 1
# define B 0
# define WHITE 16777215

typedef union		u_rgb
{
	unsigned int	value;
	unsigned char	byte[4];
}					t_rgb;

typedef struct		s_line
{
	int				p1;
	int				p2;
	int				cx;
	int				cy;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	double			dx;
	double			dy;
	int				b;
}					t_line;

typedef struct		s_points
{
	double			x;
	double			y;
	double			z;
	double			xm;
	double			ym;
	double			zm;
	t_rgb			c;
}					t_p;

typedef struct		s_map
{
	int				rows;
	int				cols;
	int				total;
	double			zoom;
	double			izoom;
	double			elev;
	int				proj;
	int				x_rot;
	int				y_rot;
	int				z_rot;
	t_p				*p;
}					t_map;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_data;
	t_map			*map;
	t_line			line;
	int				bpp;
	int				sl;
	int				ed;
}					t_fdf;

int					init_fdf(char *file, t_fdf *fdf);
void				draw_map(t_fdf *fdf);

int					calc_x(t_map *map, int i);
int					calc_y(t_map *map, int i);
void				pixel_put(t_fdf *fdf, int x, int y, int c);
void				clear_map(t_fdf *fdf);
void				reset_points(t_fdf *fdf);

void				rotate_x(t_fdf *fdf, int deg);
void				rotate_y(t_fdf *fdf, int deg);
void				rotate_z(t_fdf *fdf, int deg);
void				rotate(t_fdf *fdf, char axis, int deg);

void				edit_elevation(t_fdf *fdf, int elev);
void				display_hud(t_fdf *fdf);

void				orthographic_projection(t_fdf *fdf);
void				isometric_projection(t_fdf *fdf);
void				oblique_projection(t_fdf *fdf);

int					color_gradient(t_fdf *fdf, t_line line);
double				calc_percent(int start, int end, int current);
int					calc_color(int start, int end, double percent);

#endif
