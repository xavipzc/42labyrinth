/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:55:45 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/23 18:43:11 by PZC              ###   ########.fr       */
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
# define MAP		e->m.map

# define POS_X		e->p.pos.x
# define POS_Y		e->p.pos.y
# define DIR_X		e->p.dir.x
# define DIR_Y		e->p.dir.y
# define STEP_X		e->p.step.x
# define STEP_Y		e->p.step.y
# define SIDE		e->p.side
# define HIT		e->p.hit
# define PLANE_X	e->p.plane.x
# define PLANE_Y	e->p.plane.y
# define CAMERA_X	e->p.cam.x
# define TIME		e->cur_time
# define OLD_TIME	e->old_time
# define MOVE_SPEED	e->move_s
# define ROT_SPEED	e->rot_s

# define R_POS_X	e->r.pos.x
# define R_POS_Y	e->r.pos.y
# define R_DIR_X	e->r.dir.x
# define R_DIR_Y	e->r.dir.y
# define R_MAP_X	e->r.map.x
# define R_MAP_Y	e->r.map.y
# define R_SIDED_X	e->r.s_dist.x
# define R_SIDED_Y	e->r.s_dist.y
# define R_DELTAD_X	e->r.d_dist.x
# define R_DELTAD_Y	e->r.d_dist.y
# define R_LINE_H	e->r.line_h
# define R_Y_START	e->r.y_start
# define R_Y_END	e->r.y_end

# define MOVE_UP	e->k.move_up
# define MOVE_DOWN	e->k.move_down
# define MOVE_LEFT	e->k.move_left
# define MOVE_RIGHT	e->k.move_right
# define SPEEDX2	e->k.speed

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

typedef struct		s_key
{
	int				move_up;
	int				move_down;
	int				move_left;
	int				move_right;
	int				speed;
}					t_key;

typedef struct		s_map
{
	int				**map;
	int				width;
	int				height;
}					t_map;

typedef struct		s_menu
{
	void			*menu_ptr;
	unsigned int	*menu_img;
	int				on;
}					t_menu;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img_ptr;
	unsigned int	*view;
	t_map			m;
	t_img			img;
	t_player		p;
	t_ray			r;
	t_key			k;
	t_menu			menu;
	double			cur_time;
	double			old_time;
	double			move_s;
	double			rot_s;
	int				save_file;
	int				music;
	int				color;
}					t_env;

void				draw_vline(t_env *e, int x);
void				ft_put_pixel(unsigned int* img, int x, int y, int color);
int					readfile(t_env *e);
int					loop_hook(t_env *e);
int					key_press(int key, t_env *e);
int					key_release(int key, t_env *e);
int					quit_window(t_env *e);
void				init_env(t_env *e, char *bin);
void				init_ray(t_env *e, int x);
void				wall_color(t_env *e);
void				get_fps(t_env *e);
void				move_player(t_env *e);
void				show_error(int n);
int					show_menu(t_env *e);
void				reset_game(t_env *e);
void				save_game(t_env *e);
void				is_savefile(t_env *e);
void 				action_event(t_env *e);
void 				music_append(t_env *e);

#endif
