/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:45:10 by guillaume         #+#    #+#             */
/*   Updated: 2018/09/27 00:17:21 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	show(char const *msg)
{
	ft_putendl(msg);
}

void	print_usage(void)
{
	char *first;
	char *second;

	first = ft_strdup("\t-> '*.fdf' must be the name of a (non-corrupted");
	second = ft_strdup("/valid) file with the '.fdf' extension");
	show("usage: ./fdf [window_width] [window_height] [*.fdf]");
	show("\t-> 'window_width' must be an integer within range [800 / 1920]");
	show("\t-> 'window_height' must be an integer within range [600 / 1080]");
	show(ft_strjoin(first, second));
}

int		on_init_error_exit(char const *msg, int exit_code)
{
	show(msg);
	print_usage();
	exit(exit_code);
}

t_color	*init_color_table(void)
{
	t_color	*tab;

	tab = NULL;
	if (!(tab = (t_color*)malloc(sizeof(t_color) * 11)))
		return (tab);
	tab[0] = init_color(161, 229, 0, 0);
	tab[1] = init_color(150, 206, 19, 0);
	tab[2] = init_color(140, 183, 38, 0);
	tab[3] = init_color(129, 160, 57, 0);
	tab[4] = init_color(119, 137, 76, 0);
	tab[5] = init_color(108, 114, 95, 0);
	tab[6] = init_color(98, 91, 114, 0);
	tab[7] = init_color(87, 68, 133, 0);
	tab[8] = init_color(77, 45, 152, 0);
	tab[9] = init_color(66, 22, 171, 0);
	tab[10] = init_color(56, 0, 191, 0);
	return (tab);
}

t_env	*init_env(char *n, t_dim g_dim, t_dim win_dim, t_list **begin_alt_list)
{
	t_env *env;

	env = NULL;
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (env);
	env->mlx_app_ptr = mlx_init();
	env->app_name = ft_strdup(ft_strjoin("fdf_gmajstru - ", n));
	env->window_dim.width = win_dim.width;
	env->window_dim.height = win_dim.height;
	env->grid_dim.width = g_dim.width;
	env->grid_dim.height = g_dim.height;
	env->mlx_win_ptr = mlx_new_window(env->mlx_app_ptr, env->window_dim.width,
			env->window_dim.height, env->app_name);
	env->tile_size = 50;
	env->color = init_color(161, 229, 0, 0);
	if (!(env->colors = init_color_table()))
		return (NULL);
	env->origin = 400;
	env->p_tab = create_map_tab(env, begin_alt_list);
	env->zoom_factor = 1.025;
	env->move_factor = 30;
	if (!(env->keyboard_mgr = init_keyboard_manager()))
		return (NULL);
	mlx_do_key_autorepeaton(env->mlx_app_ptr);
	return (env);
}
