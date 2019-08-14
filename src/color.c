/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 03:50:53 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/14 05:01:36 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	color_scale(int start, int end, int current, double offset)
{
	double	placement;
	double	distance;
	double	percent;
	double	trans;
	double	p;

	placement = current - start;
	if ((distance = end - start) == 0)
		return (1);
	trans = (distance * 0.5) * offset;
	p = (1.0 + exp((-((placement + trans) * 8.0 / distance) - 4.0)));
	percent = 1.0 / p;
	return (percent);
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static	void	z_max_min(t_fdf_info *fdf)
{
	int	i;

	i = -1;
	fdf->z_min = ((t_info*)fdf->grid.ptr)[0].z;
	fdf->z_max = ((t_info*)fdf->grid.ptr)[0].z;
	while (++i < (int)fdf->grid.length)
	{
		if (((t_info*)fdf->grid.ptr)[i].z > fdf->z_max)
			fdf->z_max = ((t_info*)fdf->grid.ptr)[i].z;
		if (((t_info*)fdf->grid.ptr)[i].z < fdf->z_min)
			fdf->z_min = ((t_info*)fdf->grid.ptr)[i].z;
	}
}

int				get_color(int current, t_info start,
					t_info end, double color_offset)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (color_offset == 100)
		percentage = percent(start.x, end.x, current);
	else if (color_offset == -100)
		percentage = percent(start.y, end.y, current);
	else
		percentage = color_scale(start.z, end.z, current, color_offset);
	red = get_light((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void			set_color(t_array grid, t_fdf_info *fdf, int flag_mv_center)
{
	size_t	i;
	t_info	t1;
	t_info	t2;

	z_max_min(fdf);
	t1.z = fdf->z_min;
	t2.z = fdf->z_max;
	t1.color = BLACK;
	t2.color = WHITE;
	i = -1;
	while (++i < grid.length)
	{
		if (((t_info*)fdf->grid.ptr)[i].flag_o_color == 0)
			((t_info*)fdf->grid.ptr)[i].color =
				get_color(((t_info*)grid.ptr)[i].z, t1, t2, fdf->color_offset);
		if (flag_mv_center)
		{
			((t_info*)grid.ptr)[i].x -= fdf->map_w / 2;
			((t_info*)grid.ptr)[i].y -= fdf->map_h / 2;
		}
	}
}
