/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 00:31:24 by hmidoun           #+#    #+#             */
/*   Updated: 2019/04/16 15:23:51 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*cp_dest;
	const char	*cp_src;
	int			cp_size;
	int			dest_lenth;

	cp_dest = dest;
	cp_src = src;
	cp_size = size;
	while (cp_size-- != 0 && *cp_dest != '\0')
		cp_dest++;
	dest_lenth = cp_dest - dest;
	cp_size = size - dest_lenth;
	if (cp_size == 0)
		return (dest_lenth + ft_strlen(cp_src));
	while (*cp_src != '\0')
	{
		if (cp_size != 1)
		{
			*cp_dest++ = *cp_src;
			cp_size--;
		}
		cp_src++;
	}
	*cp_dest = '\0';
	return (dest_lenth + (cp_src - src));
}
