/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 03:35:33 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/14 06:59:53 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		center_iso(t_fdf_info *fdf, t_coord *max, t_coord *min)
{
	if (abs(max->x - min->x) > (X_IMG) || abs(min->y - max->y) > Y_IMG)
	{
		if (fdf->zoom == 1)
		{
			fdf->iso_center[0] =
				(X_IMG / 2) - (min->x + abs(max->x - min->x) / 2);
			fdf->iso_center[1] =
				(Y_IMG / 2) - (abs(min->y - max->y) / 2 + min->y);
		}
		return (0);
	}
	fdf->iso_center[0] = (X_IMG / 2) - (min->x + abs(max->x - min->x) / 2);
	fdf->iso_center[1] = (Y_IMG / 2) - (abs(min->y - max->y) / 2 + min->y);
	return (1);
}

static int		check_output_screen(t_info *to_draw, t_fdf_info *fdf)
{
	t_coord	max;
	t_coord	min;
	size_t	i;

	i = 0;
	min.x = to_draw[0].x;
	max.x = to_draw[0].x;
	min.y = to_draw[0].y;
	max.y = to_draw[0].y;
	while (++i < fdf->grid.length)
	{
		if ((to_draw)[i].x > max.x)
			max.x = (to_draw)[i].x;
		if ((to_draw)[i].x < min.x)
			min.x = (to_draw)[i].x;
		if ((to_draw)[i].y > max.y)
			max.y = (to_draw)[i].y;
		if ((to_draw)[i].y < min.y)
			min.y = (to_draw)[i].y;
	}
	return (center_iso(fdf, &max, &min));
}

static void		isotst(t_info *to_draw, int size)
{
	int	x;
	int y;
	int	i;

	i = -1;
	while (++i < size)
	{
		x = (to_draw[i].x - to_draw[i].y) * cos(RAD_30);
		y = -to_draw[i].z + (to_draw[i].x + to_draw[i].y) * sin(RAD_30);
		to_draw[i].x = x;
		to_draw[i].y = y;
	}
}

static t_info	*all_zoom(t_array grid, int z)
{
	t_info	*to_draw;
	size_t	i;

	i = -1;
	if (!(to_draw = (t_info *)malloc(sizeof(t_info) * grid.length)))
		ft_error(MALLOC_ERROR);
	while (++i < grid.length)
		to_draw[i] = zoom(((t_info*)grid.ptr)[i], z, z, z);
	isotst(to_draw, (int)grid.length);
	return (to_draw);
}

int				init_zoom(t_fdf_info *fdf)
{
	t_info	*to_draw;

	fdf->zoom = 1;
	to_draw = all_zoom(fdf->grid, fdf->zoom);
	while (check_output_screen(to_draw, fdf))
	{
		fdf->zoom++;
		to_draw = all_zoom(fdf->grid, fdf->zoom);
	}
	free(to_draw);
	if (fdf->zoom > 1)
		return (fdf->zoom - 1);
	return (1);
}
