/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:38:13 by hmidoun           #+#    #+#             */
/*   Updated: 2019/04/16 15:22:50 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ls_size(t_list *head)
{
	t_list		*temp;
	int			size;

	size = 0;
	temp = head;
	if (temp != NULL)
	{
		size++;
		while (temp->next != NULL)
		{
			temp = temp->next;
			size++;
		}
	}
	return (size);
}
