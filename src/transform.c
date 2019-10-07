/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:44:30 by gmajstru          #+#    #+#             */
/*   Updated: 2018/09/19 19:02:59 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point		to_iso(t_point point)
{
	t_point	iso_p;

	iso_p = point;
	iso_p.x = (point.x - point.y);
	iso_p.y = (point.z != 0) ? ((point.x + point.y) / 2) - point.z :
										(point.x + point.y) / 2;
	return (iso_p);
}
