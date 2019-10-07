/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 20:07:27 by guillaume         #+#    #+#             */
/*   Updated: 2018/09/27 00:16:45 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		main(int argc, char **argv)
{
	t_env	*env;
	t_dim	win_dim;
	t_dim	grid_dim;
	t_list	*alt;

	env = NULL;
	if (argc != 4)
		return (on_init_error_exit(WRONG_ARG_NUM, EXIT_FAILURE));
	if (!(win_dim.width = ft_atoi(argv[1])) ||
			!(win_dim.height = ft_atoi(argv[2])))
		return (on_init_error_exit(W_H_NOT_INT, EXIT_FAILURE));
	if (!(alt = check_input_file(argv[3], &grid_dim)))
		return (on_init_error_exit(INPUT_FILE_CORRUPTED, EXIT_FAILURE));
	if ((win_dim.height < WIN_MIN_H || win_dim.height > WIN_MAX_H) ||
	(win_dim.width < WIN_MIN_W || win_dim.width > WIN_MAX_W))
		return (on_init_error_exit(NOT_RANGE, EXIT_FAILURE));
	if (!(env = init_env(argv[3], grid_dim, win_dim, &alt)))
		return (on_init_error_exit(ENV_INIT_FAILURE, EXIT_FAILURE));
	draw_map(env);
	mlx_hook(env->mlx_win_ptr, X_EVENT, X_MASK, key_hook, env);
	mlx_loop(env->mlx_app_ptr);
	return (0);
}
