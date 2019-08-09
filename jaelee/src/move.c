/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 01:52:37 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/08 08:47:21 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info	rotation_z(t_info lst, float ang)
{
	t_info	tmp;

	tmp.x = lst.x * cos(ang) - lst.y * sin(ang);
	tmp.y = lst.x * sin(ang) + lst.y * cos(ang);
	tmp.z = lst.z;
	tmp.color = lst.color;
	return (tmp);
}

t_info	rotation_y(t_info lst, float ang)
{
	t_info	tmp;

	tmp.x = lst.x * cos(ang) + lst.z * sin(ang);
	tmp.y = lst.y;
	tmp.z = -lst.x * sin(ang) + lst.z * cos(ang);
	tmp.color = lst.color;
	return (tmp);
}

t_info	rotation_x(t_info lst, float ang)
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



/*
t_info	rotation(t_info lst, float x_ang, float y_ang, float z_ang)
{
	t_info	tmp;

	tmp.x = lst.x * cos(z_ang) - lst.y * sin(z_ang) + lst.x * cos(y_ang) + lst.z * sin(y_ang) + lst.x;
	tmp.y = lst.x * sin(z_ang) + lst.y * cos(z_ang) + lst.y + lst.y * cos(x_ang) - lst.z * sin(x_ang);
	tmp.z = lst.z + -lst.x * sin(y_ang) + lst.z * cos(y_ang) + lst.y * sin(x_ang) + lst.z * cos(x_ang);
	tmp.color = lst.color;
	return (tmp);
}

*/
