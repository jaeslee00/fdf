/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 00:04:40 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/14 05:09:05 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_x(t_info p1, t_info p2, t_fdf_info *fdf)
{
	t_coord	d;
	t_coord	curr;
	int		yi;
	int		diff;

	curr.y = p1.y;
	curr.x = p1.x;
	d.x = p2.x - p1.x;
	d.y = p2.y - p1.y;
	yi = d.y < 0 ? -1 : 1;
	d.y = abs(d.y);
	diff = 2 * d.y - d.x;
	while (curr.x < p2.x)
	{
		pixel_in_img(fdf->img_string, curr.x, curr.y,
			get_color(curr.x, p1, p2, 100));
		if (diff > 0)
		{
			curr.y += yi;
			diff = diff - 2 * d.x;
		}
		diff = diff + 2 * d.y;
		curr.x++;
	}
}

void	draw_line_y(t_info p1, t_info p2, t_fdf_info *fdf)
{
	t_coord	d;
	t_coord	curr;
	int		xi;
	int		diff;

	curr.x = p1.x;
	curr.y = p1.y;
	d.x = p2.x - p1.x;
	d.y = p2.y - p1.y;
	xi = d.x < 0 ? -1 : 1;
	d.x = abs(d.x);
	diff = 2 * d.x - d.y;
	while (curr.y < p2.y)
	{
		pixel_in_img(fdf->img_string, curr.x, curr.y,
			get_color(curr.y, p1, p2, -100));
		if (diff > 0)
		{
			curr.x += xi;
			diff = diff - 2 * d.y;
		}
		diff = diff + 2 * d.x;
		curr.y++;
	}
}

void	draw_line(t_info p1, t_info p2, t_fdf_info *fdf)
{
	if (abs(p1.y - p2.y) < abs(p1.x - p2.x))
	{
		if (p1.x > p2.x)
			draw_line_x(p2, p1, fdf);
		else
			draw_line_x(p1, p2, fdf);
	}
	else
	{
		if (p1.y > p2.y)
			draw_line_y(p2, p1, fdf);
		else
			draw_line_y(p1, p2, fdf);
	}
}

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}
