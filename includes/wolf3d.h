/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:55:45 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/16 00:03:59 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <sys/time.h>
# include "libft.h"

# include <stdio.h>

# define W_WIDTH  	800
# define W_HEIGHT 	600
# define POS_X		e->p.pos.x
# define POS_Y		e->p.pos.y
# define DIR_X		e->p.dir.x
# define DIR_Y		e->p.dir.y
# define PLANE_X	e->p.plane.x
# define PLANE_Y	e->p.plane.y
# define CAMERA_X	e->p.cam.x

typedef struct		s_coord
{
	double			x;
	double			y;
}					t_coord;

typedef struct		s_coord2
{
	int				x;
	int				y;
}					t_coord2;

typedef struct		s_ray
{
	t_coord			pos;
	t_coord			dir;
	t_coord			d_dist;
	t_coord			s_dist;
	t_coord2		map;
	int				line_h;
	int				y_start;
	int				y_end;
}					t_ray;

typedef struct		s_player
{
	t_coord			pos;
	t_coord			dir;
	t_coord			plane;
	t_coord			cam;
	t_coord2		step;
	int				side;
	int				hit;
}					t_player;

typedef struct		s_img
{
	int				width;
	int				height;
	int				e;
	int				bpp;
	int				sl;
}					t_img;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img_ptr;
	unsigned int	*view;
	t_img			img;
	t_player		p;
	t_ray			r;
	double			cur_time;
	double			old_time;
	double			move_s;
	double			rot_s;
	int				color;
	int				**map;
}					t_env;

void				draw_vline(t_env *e, int x, int y1, int y2, int color);
void				ft_put_pixel(t_env *e, int x, int y, int color);
int					readfile(t_env *e);
int					loop_hook(t_env *e);
int					key_hook(int key, t_env *e);
int					key_press(int key, t_env *e);
void				init_env(t_env *e);
void				init_ray(t_env *e, int x);
void				wall_color(t_env *e);
void				show_fps(t_env *e);
void				show_error(int n);

#endif
