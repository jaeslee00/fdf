/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 00:04:40 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/09 05:01:35 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_x(t_info p1, t_info p2, void *mlx_ptr, void *win_ptr)
{
	int dx;
	int dy;
	int yi;
	int d;
	int	x0;
	int y0;

	y0 = p1.y;

	x0 = p1.x;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	while (x0 < p2.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, get_color(x0, p1, p2, 1));
		if (d > 0)
		{
			y0 += yi;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
		x0++;
	}
}

void	draw_line_y(t_info p1, t_info p2, void *mlx_ptr, void *win_ptr)
{
	int dx;
	int dy;
	int xi;
	int d;
	int y0;
	int x0;

	x0 = p1.x;
	y0 = p1.y;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx *= -1;
	}
	d = 2 * dx - dy;
	while (y0 < p2.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, get_color(y0, p1, p2, 0));
		if (d > 0)
		{
			x0 += xi;
			d = d - 2 * dy;
		}
		d = d + 2 * dx;
		y0++;
	}
}

void	draw_line(t_info p1, t_info p2, void *mlx_ptr, void *win_ptr)
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

double percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int 	get_color(int current, t_info start, t_info end, int i)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (i == 1)
		percentage = percent(start.x, end.x, current);
	else if(i == 0)
		percentage = percent(start.y, end.y, current);
	else
		percentage = percent(start.z, end.z, current);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	//printf("%d\n", (red << 16) | (green << 8) | blue); something wrong to fix here
	return ((red << 16) | (green << 8) | blue);
}

void	set_color(t_array grid, int *x_line)
{
	size_t	i;
	t_info	t1;
	t_info	t2;

	t1.z = 0;
	t2.z = 15;
	t1.color = 65280;
	t2.color = 16187906;
	i = -1;
	while (++i < grid.length)
	{
		*x_line = i;
		if (((t_info*)grid.ptr)[i].y == 1 && ((t_info*)grid.ptr)[i].x == 0)
			break;
	}
	i = -1;
	while (++i < grid.length)
	{
		if (((t_info*)grid.ptr)[i].color == -1)
			((t_info*)grid.ptr)[i].color = get_color(((t_info*)grid.ptr)[i].z, t1, t2, -1);
		((t_info*)grid.ptr)[i].x -= *x_line / 2; // dont know if it really matter
		((t_info*)grid.ptr)[i].y -= (grid.length / *x_line) / 2;//same
	}
}
