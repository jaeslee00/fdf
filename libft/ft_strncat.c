/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 01:16:26 by hmidoun           #+#    #+#             */
/*   Updated: 2019/04/16 15:23:58 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	int		i;
	size_t	j;

	j = 0;
	i = ft_strlen(dest);
	while (src[j] != '\0' && j < nb)
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[j + i] = '\0';
	return (dest);
}
