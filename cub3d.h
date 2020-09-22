/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:53:29 by mbelorge          #+#    #+#             */
/*   Updated: 2020/02/10 17:17:24 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibX/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "./libft/libft.h"

# define ECHAP		53
# define KEY_W		13
# define KEY_S		1
# define KEY_A		0
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124

typedef struct	s_bmp
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char t;
}				t_bmp;

typedef struct	s_map
{
	int			lo;
	int			la;
	int			x;
	int			y;
	char		**tabmap;

}				t_map;

typedef struct	s_resol
{
	int			width;
	int			heigth;

}				t_resol;

typedef struct	s_image
{
	void		*img;
	char		*adrr;
	int			bpx;
	int			line_l;
	int			endian;

}				t_image;

typedef struct	s_move
{
	int			av_rec;
	int			left;
	int			right;
	int			cam;

}				t_move;

typedef struct	s_param
{
	void		*mlx_ptr;
	void		*win_ptr;

}				t_param;

typedef struct	s_player
{
	double		x;
	double		y;
	char		orientation;
	double		dir_x;
	double		dir_y;
	double		plan_x;
	double		plan_y;

}				t_player;

typedef struct	s_texture
{
	char		*orientation;
	char		*path;
	int			width;
	int			heigth;
	t_image		i;
}				t_texture;

typedef struct	s_color
{
	char		orientation;
	int			r;
	int			g;
	int			b;
	int			color_hex;

}				t_color;

typedef struct	s_raycast
{
	int			x;
	int			y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			xactual;
	int			yactual;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	double		pwd;
	int			hit;
	int			line_heigth;
	int			draw_start;
	int			draw_end;
	int			side;
	double		wall_x;
	int			textposx;
	int			textposy;
	double		step;
	double		position;
	int			color;
}				t_raycast;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			place;
	t_texture	t;
	double		distwall;
}				t_sprite;

typedef struct	s_sp
{
	double		x;
	double		y;
	double		invdet;
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			sprite_h;
	int			start_y;
	int			start_x;
	int			end_y;
	int			end_x;
	int			width;
	int			height;
	double		*distance_tab;
}				t_sp;

typedef struct	s_cub3d
{
	t_resol		resol;
	t_sprite	*sprite;
	t_sp		sp;
	char		sp_path;
	int			sprite_nb;
	void		*mlx_ptr;
	void		*win_ptr;
	t_texture	t_no;
	t_texture	t_so;
	t_texture	t_we;
	t_texture	t_ea;
	t_texture	t_spr;
	t_color		color_floor;
	t_color		color_ceiling;
	t_map		map;
	t_map		old_map;
	t_param		param;
	t_player	player;
	int			save;
	t_raycast	ray;
	t_image		img;
	double		speed_moove;
	double		olddir_x;
	double		olddir_y;
	double		oldplan_x;
	double		oldplan_y;
	t_move		move;
	double		rotate;
	t_image		minimap;
	char		*sprite_path;
	char		*ext;
}				t_cub3d;

t_map			check_fd (int fd);
t_map			lenght_map(int fd);
void			ft_read_fd(int fd,t_cub3d *cub3d);
t_resol			resolution_parse(char *line);
void			define_texture(t_cub3d *cub3d, char *line);
t_texture		texture_parse(char *line);
void			define_color(t_cub3d *cub3d, char *line);
t_color			color_parse(char *line);
void			check_map(int fd, char *line, t_cub3d *cub3d);
void			check_line(char *line, char a);
void			fill_map(char **map, char *line, t_map m);
void			check_error_border_map (char **map, t_map m);
void			check_error_inside_map (char **map, t_map m);
void			ft_error_map(int index, char a, int b, int c);
void			check_path(char *path, char *s);
void			check_color(t_color color);
void			check_color2(char *buff, char c);
void			check_error_resolution(t_resol *resolution);
void			ft_error_fd(int index, char *s);
void			ft_error_color_fd(int index, char c);
void			ft_error_div(int index);
void			start_game(t_cub3d *cub3d);
int				close_cross(t_cub3d *cub3d);
void			search_player(t_cub3d *cub3d);
void			put_ceiling_and_floor(t_cub3d *cub3d);
void			raycasting(t_cub3d *cub3d);
void			ft_position_initial(t_cub3d *cub3d);
void			get_texture (t_cub3d *cub3d);
int				key_control(int key, t_cub3d *cub3d);
void			ft_left_right(t_cub3d *cub3d);
void			ft_rotate_cam (t_cub3d *cub3d);
int				create_rgb(int r, int g, int b);
int				screenshot_map(t_cub3d *cub3d);
void			image_pixel(t_image *image, int x, int y, int argb);
void			ft_up_and_down (t_cub3d *cub3d);
void			put_minimap(t_cub3d *cub3d);
void			ft_draw_walls(t_cub3d *cub3d);
void			init_raycast(t_cub3d *cub3d);
void			calcul_sidedist(t_cub3d *cub3d);
void			ft_rev_char_tab(char *tab, int size);
void			inv(t_cub3d *cub3d);
int				key_control2(int key, t_cub3d *cub3d);
void			calcul_wall_orientation(t_cub3d *cub3d);
unsigned int	my_mlx_pixel_get(t_image img, int x, int y);
void			header_bmp(t_cub3d *cub3d, unsigned char header[54],
				unsigned int pixel_bytes_per_row);
void			get_img_data(t_cub3d *cub3d,
				t_bmp img_data[cub3d->resol.heigth][cub3d->resol.width]);
unsigned char	get_t(unsigned int color);
unsigned char	get_r(unsigned int color);
unsigned char	get_g(unsigned int color);
unsigned char	get_b(unsigned int color);
void			save_original_map (t_cub3d *cub3d);
void			free_double_tab(char **tab, int lenght);
void			free_orientation(t_cub3d *cub3d);
void			free_all(t_cub3d *cub3d);
void			search_number_sprite(t_cub3d *cub3d);
void			init_sprite(t_cub3d *cub3d);
void			ft_error_texture (int index, char *s);
void			get_texture_sprite(t_cub3d *c);
void			sprite(t_cub3d *cub3d);
void			sort_sprite(t_cub3d *cub);
void			draw_sprite (t_cub3d *cub, int stripe, int i);
void			calcul_draw_sprite(t_cub3d *cub);
void			position_sprite(t_cub3d *cub);
void			check_arg(t_cub3d *cub3d, char **argv);

#endif
