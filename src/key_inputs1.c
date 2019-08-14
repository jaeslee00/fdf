/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_inputs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:59:54 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/14 03:59:51 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	press_zoom(int key, t_fdf_info *fdf)
{
	if (key == NUMBER_PAD_PLUS)
	{
		if (fdf->zoom < fdf->init_zoom * 10)
			fdf->zoom++;
	}
	else if (key == NUMBER_PAD_MINUS)
	{
		if (fdf->zoom > 1)
			fdf->zoom--;
	}
}

void	press_move(int key, t_fdf_info *fdf)
{
	if (key == ARROW_DOWN)
		fdf->y_offset += 5;
	else if (key == ARROW_UP)
		fdf->y_offset -= 5;
	else if (key == ARROW_RIGHT)
		fdf->x_offset += 5;
	else if (key == ARROW_LEFT)
		fdf->x_offset -= 5;
}

void	press_rotation(int key, t_fdf_info *fdf)
{
	if (key == MAIN_PAD_A)
		(fdf)->x_rot += 0.05;
	else if (key == MAIN_PAD_D)
		(fdf)->x_rot -= 0.05;
	else if (key == MAIN_PAD_W)
		(fdf)->y_rot += 0.05;
	else if (key == MAIN_PAD_S)
		(fdf)->y_rot -= 0.05;
	else if (key == MAIN_PAD_Q)
		(fdf)->z_rot += 0.05;
	else if (key == MAIN_PAD_E)
		(fdf)->z_rot -= 0.05;
}
