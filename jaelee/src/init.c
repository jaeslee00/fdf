/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 03:35:33 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/09 08:07:17 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_output_screen(t_info *to_draw, size_t size ,int T[3])
{
	int xmax;
	int	xmin;
	int	ymax;
	int	ymin;
	size_t i;

	i = 0;
	xmin = to_draw[0].x;
	xmax = to_draw[0].x;
	ymin = to_draw[0].y;
	ymax = to_draw[0].y;
	while (++i < size)
	{
		if ((to_draw)[i].x > xmax)
			xmax = (to_draw)[i].x;
		if ((to_draw)[i].x < xmin)
			xmin = (to_draw)[i].x;
		if ((to_draw)[i].y > ymax)
			ymax = (to_draw)[i].y;
		if ((to_draw)[i].y < ymin)
			ymin = (to_draw)[i].y;
	}
	if (abs(xmax - xmin) > (X_SCREEN - X_INSTRUCTION) || abs(ymin - ymax) > Y_SCREEN)
	{
		/*if (z == 1)
		{
			T[0] = (((X_SCREEN - X_INSTRUCTION) / 2) + X_INSTRUCTION) - ( xmin + abs(xmax - xmin)/2);
			T[1] = (Y_SCREEN / 2) - (abs(ymin - ymax) / 2 + ymin);
		}*/
		return (0);
	}
	T[0] = (((X_SCREEN - X_INSTRUCTION) / 2) + X_INSTRUCTION) - ( xmin + abs(xmax - xmin)/2);
	T[1] = (Y_SCREEN / 2) - (abs(ymin - ymax) / 2 + ymin);
	//printf("%d\t%d\n", abs(xmax - xmin), abs(ymax - ymin));
	return (1);
}

static void	isotst(t_info *(*to_draw), int size)
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
		//(*to_draw)[i] = translation((*to_draw)[i], T[0], T[1], 0);//! translate it to the centre need to be changed
	}
}


static t_info	*all_zoom(t_array grid, int z)
{
	t_info	*to_draw;
	size_t	i;

	i = -1;
	to_draw = (t_info *)malloc(sizeof(t_info) * grid.length);
	while (++i < grid.length)
		to_draw[i] = zoom(((t_info*)grid.ptr)[i], z, z, z);

	isotst(&to_draw, (int) grid.length);

	return (to_draw);
}

int		init_zoom(t_array grid, int T[3])
{
	int		zoom;
	t_info	*to_draw;

	zoom = 1;
	to_draw = all_zoom(grid, zoom);
	while (check_output_screen(to_draw, grid.length, T))
	{
		zoom++;
		//printf("%d\n", zoom);
		to_draw = all_zoom(grid, zoom);
	}
	return(zoom - 1);
}

