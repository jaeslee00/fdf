/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 13:24:25 by midounhoc         #+#    #+#             */
/*   Updated: 2019/04/16 15:23:11 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *tmp;

	tmp = ft_memalloc(n);
	if (tmp)
	{
		ft_memcpy(tmp, src, n);
		ft_memcpy(dst, tmp, n);
	}
	free(tmp);
	return (dst);
}
