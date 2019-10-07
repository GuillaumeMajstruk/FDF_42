/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:49:36 by guillaume         #+#    #+#             */
/*   Updated: 2018/09/26 22:26:19 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	map_zoomin(t_env *env)
{
	t_iter	i;
	t_iter	j;

	i = -1;
	while (++i < env->grid_dim.height)
	{
		j = -1;
		while (++j < env->grid_dim.width)
		{
			env->p_tab[i][j].x *= env->zoom_factor;
			env->p_tab[i][j].y *= env->zoom_factor;
			env->p_tab[i][j].z *= env->zoom_factor;
		}
	}
}

void	map_zoomout(t_env *env)
{
	t_iter	i;
	t_iter	j;

	i = -1;
	while (++i < env->grid_dim.height)
	{
		j = -1;
		while (++j < env->grid_dim.width)
		{
			env->p_tab[i][j].x /= env->zoom_factor;
			env->p_tab[i][j].y /= env->zoom_factor;
			env->p_tab[i][j].z /= env->zoom_factor;
		}
	}
}
