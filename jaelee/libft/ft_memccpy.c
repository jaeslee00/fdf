/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 13:24:25 by midounhoc         #+#    #+#             */
/*   Updated: 2019/04/16 15:23:03 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cp_dst;
	unsigned char	*cp_src;
	size_t			i;

	cp_dst = (unsigned char *)dst;
	cp_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cp_dst[i] = cp_src[i];
		if ((unsigned char)c == cp_src[i])
			return ((unsigned char *)(dst + i + 1));
		i++;
	}
	return (NULL);
}
