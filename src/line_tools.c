/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:41:15 by guillaume         #+#    #+#             */
/*   Updated: 2018/09/19 18:05:00 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_line_carateristics(t_line_car *l_car, t_point p1,
								t_point p2)
{
	l_car->p1.x = p1.x;
	l_car->p1.y = p1.y;
	l_car->current = l_car->p1;
	l_car->p2.x = p2.x;
	l_car->p2.y = p2.y;
	l_car->e.x = abs((int)l_car->p2.x - (int)l_car->p1.x);
	l_car->e.y = abs((int)l_car->p2.y - (int)l_car->p1.y);
	l_car->d.x = 2 * l_car->e.x;
	l_car->d.y = 2 * l_car->e.y;
	l_car->der.x = l_car->e.x;
	l_car->der.y = l_car->e.y;
	l_car->xincr = (l_car->p1.x > l_car->p2.x) ? -1 : 1;
	l_car->yincr = (l_car->p1.y > l_car->p2.y) ? -1 : 1;
}

void	drawline_small_angle(t_env *env, t_line_car line_car)
{
	t_iter	i;

	i = -1;
	while (++i <= line_car.der.x)
	{
		mlx_pixel_put(env->mlx_app_ptr, env->mlx_win_ptr, line_car.current.x,
				line_car.current.y, convert_color_touint(env->color));
		line_car.current.x += line_car.xincr;
		line_car.e.x -= line_car.d.y;
		if (line_car.e.x < 0)
		{
			line_car.current.y += line_car.yincr;
			line_car.e.x += line_car.d.x;
		}
	}
}

void	drawline_great_angle(t_env *env, t_line_car line_car)
{
	t_iter i;

	i = -1;
	while (++i <= line_car.der.y)
	{
		mlx_pixel_put(env->mlx_app_ptr, env->mlx_win_ptr, line_car.current.x,
				line_car.current.y, convert_color_touint(env->color));
		line_car.current.y += line_car.yincr;
		line_car.e.y -= line_car.d.x;
		if (line_car.e.y < 0)
		{
			line_car.current.x += line_car.xincr;
			line_car.e.y += line_car.d.y;
		}
	}
}

void	drawline(t_env *env, t_point p1, t_point p2)
{
	t_line_car line_car;

	if ((!(p2.y <= env->window_dim.height && p2.y >= 0) ||
				!(p2.x <= env->window_dim.width && p2.x >= 0)) ||
	(!(p1.y <= env->window_dim.height && p1.y >= 0) ||
				!(p1.x <= env->window_dim.width && p1.x >= 0)))
		return ;
	init_line_carateristics(&line_car, p1, p2);
	if (line_car.der.x > line_car.der.y)
		drawline_small_angle(env, line_car);
	if (line_car.der.x < line_car.der.y)
		drawline_great_angle(env, line_car);
}
