/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 13:55:11 by guillaume         #+#    #+#             */
/*   Updated: 2018/09/25 21:06:56 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_kb_mgr	*init_keyboard_manager(void)
{
	t_kb_mgr *keyboard_mgr;

	keyboard_mgr = NULL;
	if (!(keyboard_mgr = (t_kb_mgr*)malloc(sizeof(t_kb_mgr) * NUM_ACTION)))
		return (keyboard_mgr);
	keyboard_mgr[0].key = Left;
	keyboard_mgr[0].func_ptr = &map_move_left;
	keyboard_mgr[1].key = Right;
	keyboard_mgr[1].func_ptr = &map_move_right;
	keyboard_mgr[2].key = Up;
	keyboard_mgr[2].func_ptr = &map_move_up;
	keyboard_mgr[3].key = Down;
	keyboard_mgr[3].func_ptr = &map_move_down;
	keyboard_mgr[4].key = Plus;
	keyboard_mgr[4].func_ptr = &map_zoomin;
	keyboard_mgr[5].key = Minus;
	keyboard_mgr[5].func_ptr = &map_zoomout;
	keyboard_mgr[6].key = Color_change;
	keyboard_mgr[6].func_ptr = &change_map_color;
	return (keyboard_mgr);
}

int			key_hook(int keycode, t_env *env)
{
	t_key	key_pressed;
	t_iter	i;

	key_pressed = keycode;
	i = -1;
	if (key_pressed == Esc)
		exit(EXIT_SUCCESS);
	while (++i < NUM_ACTION)
	{
		if (key_pressed == env->keyboard_mgr[i].key)
			env->keyboard_mgr[i].func_ptr(env);
	}
	mlx_clear_window(env->mlx_app_ptr, env->mlx_win_ptr);
	draw_map(env);
	return (0);
}
