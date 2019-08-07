/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 01:52:37 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/06 04:23:47 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_p_list	*rotation_z(t_p_list *lst, float ang)
{
	t_p_list	*tmp;

	if(!(tmp = (t_p_list *)malloc(sizeof(t_p_list))))
		return (NULL);
	tmp->x = lst->x * cos(ang) - lst->y * sin(ang);
	tmp->y = lst->x * sin(ang) + lst->y * sin(ang);
	tmp->z = lst->z;
	return (tmp);
}

t_p_list	*rotation_y(t_p_list *lst, float ang)
{
	t_p_list	*tmp;

	if(!(tmp = (t_p_list *)malloc(sizeof(t_p_list))))
		return (NULL);
	tmp->x = lst->x * cos(ang) + lst->z * sin(ang);
	tmp->y = lst->y;
	tmp->z = -lst->x * sin(ang) + lst->z * sin(ang);
	return (tmp);
}

t_p_list	*rotation_x(t_p_list *lst, float ang)
{
	t_p_list	*tmp;

	if(!(tmp = (t_p_list *)malloc(sizeof(t_p_list))))
		return (NULL);
	tmp->x = lst->x;
	tmp->y = lst->y * cos(ang) - lst->z * sin(ang);
	tmp->z = lst->y * sin(ang) + lst->z * sin(ang);
	return (tmp);
}

t_p_list	*translation(t_p_list *lst, int tx, int ty, int tz)
{
	t_p_list	*tmp;

	if(!(tmp = (t_p_list *)malloc(sizeof(t_p_list))))
		return (NULL);
	tmp->x = tx + lst->x;
	tmp->y = ty + lst->y;
	tmp->z = tz + lst->z;
	return (tmp);
}

t_p_list	*zoom(t_p_list *lst, int s_x, int s_y, int s_z)
{
	t_p_list	*tmp;

	if(!(tmp = (t_p_list *)malloc(sizeof(t_p_list))))
		return (NULL);
	tmp->x = s_x * lst->x;
	tmp->y = s_y * lst->y;
	tmp->z = s_z * lst->z;
	return (tmp);
}
