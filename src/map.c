/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:07:33 by guillaume         #+#    #+#             */
/*   Updated: 2018/09/26 22:23:56 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point		*create_point(t_env *env, int i, int j, int alt)
{
	t_point	*point;

	point = NULL;
	if (!(point = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	point->x = (j * env->tile_size) + env->origin;
	point->y = (i * env->tile_size);
	point->z = alt * 13;
	return (point);
}

t_point		**create_map_tab(t_env *env, t_list **begin_alt_list)
{
	t_iter	i;
	t_iter	j;
	t_point	**p_tab;
	t_list	*altitudes;

	p_tab = NULL;
	altitudes = (begin_alt_list) ? *begin_alt_list : NULL;
	if (!(p_tab = (t_point**)malloc(sizeof(t_point*) * env->grid_dim.height)))
		return (NULL);
	i = -1;
	while (++i < env->grid_dim.height)
	{
		if (!(p_tab[i] = malloc(sizeof(t_point) * env->grid_dim.width)))
			return (NULL);
		j = -1;
		while (++j < env->grid_dim.width && altitudes)
		{
			p_tab[i][j] = to_iso(*(create_point(env, i, j,
			*((int*)altitudes->content))));
			altitudes = altitudes->next;
		}
	}
	return (p_tab);
}

void		draw_horizontal_map(t_env *env)
{
	t_iter	i;
	t_iter	j;
	t_point	iso_curr;
	t_point	iso_prev;

	i = -1;
	while (++i < env->grid_dim.height)
	{
		j = 0;
		while (++j < env->grid_dim.width)
		{
			iso_prev = env->p_tab[i][j - 1];
			iso_curr = env->p_tab[i][j];
			drawline(env, iso_prev, iso_curr);
		}
	}
}

void		draw_vertical_map(t_env *env)
{
	t_iter	i;
	t_iter	j;
	t_point	iso_curr;
	t_point	iso_prev;

	i = 0;
	while (++i < env->grid_dim.height)
	{
		j = -1;
		while (++j < env->grid_dim.width)
		{
			iso_prev = env->p_tab[i - 1][j];
			iso_curr = env->p_tab[i][j];
			drawline(env, iso_prev, iso_curr);
		}
	}
}

void		draw_map(t_env *env)
{
	draw_horizontal_map(env);
	draw_vertical_map(env);
}
