/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_inputs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:36:03 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/14 04:00:04 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_transformation(t_fdf_info *fdf)
{
	fdf->x_rot = 0;
	fdf->y_rot = 0;
	fdf->z_rot = 0;
	fdf->x_offset = 0;
	fdf->y_offset = 0;
	fdf->color_offset = -1.3;
	set_color(fdf->grid, fdf, 0);
	fdf->zoom = fdf->init_zoom;
}

void	perspective(int key, t_fdf_info *fdf)
{
	if (key == MAIN_PAD_I)
	{
		reset_transformation(fdf);
		fdf->perspective = ISO;
	}
	else if (key == MAIN_PAD_P)
	{
		reset_transformation(fdf);
		fdf->perspective = PARALLEL;
	}
}

void	press_offset_color(int key, t_fdf_info *fdf)
{
	if (key == PAD_9 && fdf->color_offset > -3.0)
	{
		fdf->color_offset -= 0.02;
		set_color(fdf->grid, fdf, 0);
	}
	else if (key == PAD_6 && fdf->color_offset < -0.5)
	{
		fdf->color_offset += 0.02;
		set_color(fdf->grid, fdf, 0);
	}
}
