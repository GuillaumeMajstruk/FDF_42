/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 19:22:29 by guillaume         #+#    #+#             */
/*   Updated: 2018/09/19 17:30:47 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_color		init_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

t_u_int		convert_color_touint(t_color color)
{
	t_u_int	col;

	col = (color.a << 24) + (color.r << 16) + (color.g << 8) + color.b;
	return (col);
}

t_color		convert_color_tocolor(t_u_int col_val)
{
	t_color	color;

	color.a = (col_val >> 24) & 255;
	color.r = (col_val >> 16) & 255;
	color.g = (col_val >> 8) & 255;
	color.b = col_val & 255;
	return (color);
}

void		change_map_color(t_env *env)
{
	static int	col_num;
	static int	increase;
	static int	decrease;

	if (col_num == 10)
	{
		decrease = 1;
		increase = 0;
	}
	if (col_num == 0)
	{
		increase = 1;
		decrease = 0;
	}
	if (increase)
		col_num++;
	else
		col_num--;
	env->color = env->colors[col_num];
	return ;
}
