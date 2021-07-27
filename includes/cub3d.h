/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouter </var/mail/yobouter>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:52:01 by yobouter          #+#    #+#             */
/*   Updated: 2021/04/25 18:52:04 by yobouter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>

# define FORWARD_Z	    122
# define BACK_S		    115
# define RIGHT_D		100
# define LEFT_Q		    113
# define R_RIGHT		65363
# define R_LEFT			65361
# define ESC           	65307

typedef struct s_mapinfo
{
	int		rx;
	int		ry;
	char	*notext;
	char	*sotext;
	char	*wetext;
	char	*eatext;
	char	*sprite;
	int		floorcol[3];
	int		ceilingcol[3];
	int		countlinemap;	
	char	**map;
	int		mapx;
	int		mapy;
	int		countnot;
	int		countsot;
	int		counteat;
	int		countwet;
	int		countst;
	int		countfc;
	int		countcc;
	int		countres;
	int		exit;
	int		dx;
	int		dy;
	int		scrx;
	int		scry;
	char	startdir;
	char	*file;
	int		readlines;
	int		linelength;
	int		emptyline;
	int		startmap;
	int		fd;
	int		once;
}				t_mapinfo;

typedef struct s_sprite
{
	int				total;
	int				*sorted;
	double			*dist;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transx;
	double			transy;
	int				sprscreenx;
	int				sprheight;
	int				sprwidth;
	int				drawstartx;
	int				drawstarty;
	int				drawendy;
	int				drawendx;
	double			*zbuffer;
}					t_sprite;

typedef struct s_sprxy
{
	double			x;
	double			y;
}					t_sprxy;

typedef struct s_texture
{
	int				texdir;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
}					t_texture;

typedef struct s_ray
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			raydirx;
	double			raydiry;
	double			camera;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;

	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			m_speed;
	double			r_speed;
	int				x;
	int				texture;
}					t_ray;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				forward;
	int				back;
	int				left;
	int				right;
	int				r_left;
	int				r_right;
	int				width;
	int				height;
	void			*img2;
	int				*addr2;
}					t_data;

typedef struct s_game
{
	int			save;
	t_mapinfo	*map;
	t_data		data;
	t_data		text[5];
	t_ray		ray;
	t_sprite	sprite;
	t_sprxy		*sxy;
	t_texture	t;
}				t_game;

void	*malloczero(size_t size);
int		ft_strlen(const char *s);
char	*trimstr(const char *line, const char *set);
int		is_digit(char c);
int		get_number(const char *str, int i, int j, t_game *g);
int		has_spaces(const char *str);
int		white_space(char c);
int		empty_line(const char *str);
void	init_mapinfo(t_game *g);
int		getresolution(const char *line, t_game *g);
int		getnotext(const char *str, t_game *g);
void	getsotext(const char *str, t_game *g);
int		getwetext(const char *str, t_game *g);
int		geteatext(const char *str, t_game *g);
int		getsprite(const char *str, t_game *g);
int		getfloorcol(const char *str, t_game *g);
int		getceilingcol(const char *str, t_game *g);
void	getmap(const char *str, t_mapinfo *map);
void	getinfo(char *line, t_game *g);
int		ft_atoix(const char *str, int i, t_game *g);
int		ft_atoiy(const char *str, int i, t_game *g);
void	print_mapinfo(t_mapinfo *map);
int		check_map(t_game *g);
int		isolated_space(t_game *g, int x, int y);
int		is_nseo(char c);
int		count_nseo(t_game *g);
int		count_zero(t_game *g);
void	retrieve_info(t_game *g);
int		ft_memcmp(const void *a1, const void *a2, size_t size);
int		cub3d(char *file, t_game *g);
void	init_game(t_game *g);
void	*ft_memcpy(void *to, void *from, size_t size);
void	get_err(char *message, t_game *g);
int		check_diag1(t_game *g, int x, int y);
int		check_diag2(t_game *g, int x, int y);
void	check_line(char *str, t_game *g);
void	getinfo2(char *str, t_game *g);
int		is_mapline(const char *str);
int		weird_map(t_game *g);
int		get_mapline(t_mapinfo *map);
void	count_text(t_game *g);
int		init_sprite(t_game *g);
void	init_gamebis(t_game *g);
int		set_mlx(t_game *g);
void	init_direction(t_game *g);
void	retrieve_texture(t_game *g);
void	init_raycasting(t_game *g);
void	get_sidedists(t_game *g);
int		createRGB(int r, int g, int b);
int		draw_ray(t_game *g);
void	set_sprite(t_game *g, int i);
void	sprite_handler(t_game *g);
void	draw_sprite(t_game *g, int y, int texX, int stripe);
void	sort_by_dist(t_game *g);
void	save_image(t_game *g);
void	move_forward_back(t_game *g);
void	rotate_left_right(t_game *g);
void	ft_swap(t_game *g);
int		exit_game(t_game *g);
int		key_press(int keycode, t_game *g);
int		key_release(int keycode, t_game *g);
int		wrong_char(const char *s);
int		get_closest(const char *s, int nb);
int		check_mapline(const char *str);
void	get_mapinfo(char *line, t_game *g);
void	getmapsize(const char *l, t_game *g);
void	is_closed(t_game *g);
void	move_left_right(t_game *g);
int		count_numbers(const char *str);
#endif 
