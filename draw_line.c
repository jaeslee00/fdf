/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 00:04:40 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/05 03:24:43 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_x(t_p_list p1, t_p_list p2, void *mlx_ptr, void *win_ptr)
{
	int dx;
	int dy;
	int yi;
	int d;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	while (p1.x < p2.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, p1.x, p1.y, 100000);
		if (d > 0)
		{
			p1.y += yi;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
		p1.x++;
	}
}

void	draw_line_y(t_p_list p1, t_p_list p2, void *mlx_ptr, void *win_ptr)
{
	int dx;
	int dy;
	int xi;
	int d;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx *= -1;
	}
	d = 2 * dx - dy;
	while (p1.y < p2.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, p1.x, p1.y, 100000);
		if (d > 0)
		{
			p1.x += xi;
			d = d - 2 * dy;
		}
		d = d + 2 * dx;
		p1.y++;
	}
}

void	draw_line(t_p_list p1, t_p_list p2, void *mlx_ptr, void *win_ptr)
{
	if (abs(p1.y - p2.y) < abs(p1.x - p2.x))
	{
		if (p1.x > p2.x)
			draw_line_x(p2, p1, mlx_ptr, win_ptr);
		else
			draw_line_x(p1, p2, mlx_ptr, win_ptr);
	}
	else
	{
		if (p1.y > p2.y)
			draw_line_y(p2, p1, mlx_ptr, win_ptr);
		else
			draw_line_y(p1, p2, mlx_ptr, win_ptr);
	}
}
