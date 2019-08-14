/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 01:52:37 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/14 03:55:35 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info	rotation_z(t_info lst, double ang)
{
	t_info	tmp;

	tmp.x = lst.x * cos(ang) - lst.y * sin(ang);
	tmp.y = lst.x * sin(ang) + lst.y * cos(ang);
	tmp.z = lst.z;
	tmp.color = lst.color;
	return (tmp);
}

t_info	rotation_y(t_info lst, double ang)
{
	t_info	tmp;

	tmp.x = lst.x * cos(ang) + lst.z * sin(ang);
	tmp.y = lst.y;
	tmp.z = -lst.x * sin(ang) + lst.z * cos(ang);
	tmp.color = lst.color;
	return (tmp);
}

t_info	rotation_x(t_info lst, double ang)
{
	t_info	tmp;

	tmp.x = lst.x;
	tmp.y = lst.y * cos(ang) - lst.z * sin(ang);
	tmp.z = lst.y * sin(ang) + lst.z * cos(ang);
	tmp.color = lst.color;
	return (tmp);
}

t_info	translation(t_info lst, int tx, int ty, int tz)
{
	t_info	tmp;

	tmp.x = tx + lst.x;
	tmp.y = ty + lst.y;
	tmp.z = tz + lst.z;
	tmp.color = lst.color;
	return (tmp);
}

t_info	zoom(t_info lst, int s_x, int s_y, int s_z)
{
	t_info	tmp;

	tmp.x = s_x * lst.x;
	tmp.y = s_y * lst.y;
	tmp.z = s_z * lst.z;
	tmp.color = lst.color;
	return (tmp);
}
