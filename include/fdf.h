/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:35:17 by guillaume         #+#    #+#             */
/*   Updated: 2018/09/27 19:09:41 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

/*
** Color defines en Hexadecimale.
*/
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

/*
** Paramètres d'environement pour initialisation.
*/
# define X_EVENT 2
# define X_MASK 1
# define WIN_MAX_W 1920
# define WIN_MIN_W 800
# define WIN_MAX_H 1080
# define WIN_MIN_H 600
# define NUM_ACTION 7

/*
** DEFINES: STR(s) pour qualifier les erreurs probablement
** rencontrée.
*/
# define FILE_DIGITS_ERROR "file must only contains digits."
# define FILE_EXT_ERROR "file is not of the good extension."
# define FILE_OPEN_ERROR "open() failed to open the file."
# define WRONG_ARG_NUM "wrong arg number."
# define W_H_NOT_INT "Width or Height is not of the good type."
# define INPUT_FILE_CORRUPTED "Input .fdf file is corrupted."
# define NOT_RANGE "Width or Height specified is not within the correct range."
# define ENV_INIT_FAILURE "Environement failed to init."

typedef unsigned int					t_u_int;
typedef	int								t_bool;
typedef unsigned int					t_iter;
typedef struct s_env					t_env;
typedef struct s_point					t_point;
typedef struct s_dim					t_dim;
typedef struct s_line_caracteristics	t_line_car;
typedef struct s_color					t_color;
typedef enum e_key						t_key;
typedef struct s_keyboard_manager		t_kb_mgr;
typedef void							(*t_f_ptr)(t_env*);

struct		s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
};

struct		s_point
{
	double	x;
	double	y;
	double	z;
	t_color	color;
};

struct		s_dim
{
	t_u_int	height;
	t_u_int	width;
};

struct		s_line_caracteristics
{
	t_point	p1;
	t_point	p2;
	t_point	e;
	t_point	d;
	t_point	der;
	t_point	current;
	int		xincr;
	int		yincr;
};

enum		e_key
{
	Esc = 53,
	Right = 123,
	Left,
	Down = 125,
	Up,
	Plus = 24,
	Minus = 27,
	Color_change = 260
};

struct		s_keyboard_manager
{
	t_key	key;
	t_f_ptr	func_ptr;
};

struct		s_env
{
	void		*mlx_app_ptr;
	void		*mlx_win_ptr;
	char		*app_name;
	t_dim		window_dim;
	double		origin;
	double		tile_size;
	double		zoom_factor;
	int			move_factor;
	t_kb_mgr	*keyboard_mgr;
	t_color		color;
	t_color		*colors;
	t_dim		grid_dim;
	t_point		**p_tab;
};

void		init_line_carateristics(t_line_car *l_car, t_point p1,
								t_point p2);
t_color		init_color(int r, int g, int b, int a);
void		print_usage(void);
int			on_init_error_exit(char const *msg, int exit_code);
t_color		*init_color_table(void);
t_kb_mgr	*init_keyboard_manager(void);
t_u_int		get_tab_width(char **tab);
int			str_is_digit(char *str);
void		add_pt_to_lst(t_list **lst, char **tab);
t_list		*check_input_file(char const *file_name, t_dim *tab_dim);
int			key_hook(int keycode, t_env *env);
t_env		*init_env(char *n, t_dim grid_dim, t_dim win_dim,
					t_list **begin_alt_list);
void		drawline_small_angle(t_env *env, t_line_car line_car);
void		drawline_great_angle(t_env *env, t_line_car line_car);
void		drawline(t_env *env, t_point p1, t_point p2);
t_point		to_iso(t_point point);
t_point		**create_map_tab(t_env *env, t_list **begin_alt_list);
void		draw_horizontal_map(t_env *env);
void		draw_vertical_map(t_env *env);
void		draw_map(t_env *env);
t_u_int		convert_color_touint(t_color color);
t_color		convert_color_tocolor(t_u_int col_val);
void		change_map_color(t_env *env);

void		map_move_left(t_env *env);
void		map_move_right(t_env *env);
void		map_move_up(t_env *env);
void		map_move_down(t_env *env);
void		map_zoomin(t_env *env);
void		map_zoomout(t_env *env);

#endif
