/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:37:54 by guillaume         #+#    #+#             */
/*   Updated: 2018/09/19 17:51:48 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	map_move_left(t_env *env)
{
	t_iter	i;
	t_iter	j;

	i = -1;
	while (++i < env->grid_dim.height)
	{
		j = -1;
		while (++j < env->grid_dim.width)
			env->p_tab[i][j].x -= env->move_factor;
	}
}

void	map_move_right(t_env *env)
{
	t_iter	i;
	t_iter	j;

	i = -1;
	while (++i < env->grid_dim.height)
	{
		j = -1;
		while (++j < env->grid_dim.width)
			env->p_tab[i][j].x += env->move_factor;
	}
}

void	map_move_up(t_env *env)
{
	t_iter	i;
	t_iter	j;

	i = -1;
	while (++i < env->grid_dim.height)
	{
		j = -1;
		while (++j < env->grid_dim.width)
			env->p_tab[i][j].y -= env->move_factor;
	}
}

void	map_move_down(t_env *env)
{
	t_iter	i;
	t_iter	j;

	i = -1;
	while (++i < env->grid_dim.height)
	{
		j = -1;
		while (++j < env->grid_dim.width)
			env->p_tab[i][j].y += env->move_factor;
	}
}
