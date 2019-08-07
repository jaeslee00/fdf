/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:42:49 by hmidoun           #+#    #+#             */
/*   Updated: 2019/04/16 15:23:44 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(src));
	if (!tmp)
		return (NULL);
	tmp = ft_strcpy(tmp, src);
	return (tmp);
}
