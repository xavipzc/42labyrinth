/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:55:45 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/25 19:04:25 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <sys/time.h>
# include "libft.h"

# define W_WIDTH	800
# define W_HEIGHT	600
# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define GREY1		0x111111
# define GREY2		0x222222
# define GREY3		0x333333
# define GREY9		0x999999
# define BLUE		0x33FFD7
# define RED		0xFF0000
# define GREEN		0x00FF00
# define SKY		0x33DAFF
# define COLOR		e->color
# define MAP		e->m.map
# define SAVE		e->save_file
# define MENU		e->menu.on
# define ERROR		e->m.error
# define SUSPENS	e->m.zone
# define SOUND		e->m.sound
# define WIN		e->win

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
	int				sound;
	int				error;
	int				zone;
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
	int				color;
	int				win;
}					t_env;

void				draw_vline(t_env *e, int x);
void				ft_put_pixel(unsigned int *img, int x, int y, int color);
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
void				action_event(t_env *e);
void				event_append(t_env *e);

#endif
