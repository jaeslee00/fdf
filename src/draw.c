/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 04:05:06 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/14 03:42:28 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** translate it to the centre need to be changed
*/

void	isometric(t_info *draw, t_fdf_info *fdf)
{
	int	x;
	int y;

	x = (draw->x - draw->y) * cos(RAD_30);
	y = -draw->z + (draw->x + draw->y) * sin(RAD_30);
	draw->x = x;
	draw->y = y;
	*draw = translation(*draw, fdf->iso_center[0], fdf->iso_center[1], 0);
}

void	projection(t_fdf_info *fdf)
{
	int		i;
	t_info	*copy;

	copy = fdf->copy;
	i = -1;
	while (++i < (int)fdf->grid.length)
	{
		copy[i] = zoom(((t_info*)fdf->grid.ptr)[i],
		fdf->zoom, fdf->zoom, fdf->zoom);
		copy[i] = rotation_z(copy[i], fdf->z_rot);
		copy[i] = rotation_x(copy[i], fdf->x_rot);
		copy[i] = rotation_y(copy[i], fdf->y_rot);
		if (fdf->perspective == ISO)
			isometric(&copy[i], fdf);
		else if (fdf->perspective == PARALLEL)
			copy[i] = translation(copy[i], (X_IMG / 2), (Y_IMG / 2), 0);
		copy[i] = translation(copy[i], fdf->x_offset, fdf->y_offset, 0);
	}
}

void	draw(t_fdf_info *fdf)
{
	int		x;
	int		y;
	t_info	*copy;

	copy = fdf->copy;
	reset_img(fdf->img_string);
	projection(fdf);
	y = -1;
	while (++y < fdf->map_h)
	{
		x = -1;
		while (++x < fdf->map_w)
		{
			if (x < fdf->map_w - 1)
				draw_line(copy[x + y * fdf->map_w],
					copy[(x + 1) + y * fdf->map_w], fdf);
			if (y < fdf->map_h - 1)
				draw_line(copy[x + y * fdf->map_w],
					copy[x + (y + 1) * fdf->map_w], fdf);
		}
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->img_ptr, X_INSTR, 0);
}
