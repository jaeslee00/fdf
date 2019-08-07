/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 23:39:15 by midounhoc         #+#    #+#             */
/*   Updated: 2019/04/16 15:24:07 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*find;

	find = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			find = (char *)(s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (find);
}
