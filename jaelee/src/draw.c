/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 04:05:06 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/07 07:38:03 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_info *(*to_draw), int size)
{
	int	x;
	int y;
	int	i;

	i = -1;
	while (++i < size)
	{
		x =  (((*to_draw))[i].x - (*to_draw)[i].y) * cos(M_PI / 6.0f);
		y = -(*to_draw)[i].z + ((*to_draw)[i].x + (*to_draw)[i].y) * sin(M_PI / 6.0f);
		(*to_draw)[i].x = x;
		(*to_draw)[i].y = y;
		(*to_draw)[i] = translation((*to_draw)[i], 400, 400, 0);
	}
}

void	draw(t_info *to_draw, int x_line, int size, void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;

	y = -1;
	iso(&to_draw, size);
	while (++y < size / x_line)
	{
		x = -1;
		while (++x < x_line)
		{
			if (x < x_line - 1)
				draw_line(to_draw[x + y * x_line], to_draw[x + 1 + y * x_line], mlx_ptr, win_ptr);
			if (y < size / x_line - 1)
				draw_line(to_draw[x + y * x_line], to_draw[x + (y+1) * x_line], mlx_ptr, win_ptr);
		}
	}
}
