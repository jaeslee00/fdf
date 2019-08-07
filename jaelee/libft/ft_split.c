/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 21:41:15 by hmidoun           #+#    #+#             */
/*   Updated: 2019/04/16 15:23:29 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_char(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static int		nbr_word(char *str, char *charset)
{
	int j;
	int car;
	int i;

	i = 0;
	car = 0;
	j = 0;
	while (str[i])
	{
		if (check_char(str[i], charset))
			car = 0;
		else if (car == 0)
		{
			j++;
			car = 1;
		}
		i++;
	}
	return (j);
}

static int		ft_strlen_str(char *str, char *charset)
{
	int i;

	i = 0;
	while (str[i] != '\0' && !check_char(str[i], charset))
	{
		i++;
	}
	return (i);
}

static char		*ft_strdup_str(char *src, char *charset)
{
	char	*tmp;
	int		len;
	int		i;

	len = ft_strlen_str(src, charset);
	tmp = (char*)malloc(sizeof(char) * len);
	if (!tmp)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && !check_char(src[i], charset))
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char			**ft_split(char *str, char *charset)
{
	char	**tab_str;
	int		car;
	int		i;
	int		j;

	j = 0;
	i = 0;
	car = 0;
	tab_str = (char **)malloc(sizeof(char *) * (nbr_word(str, charset) + 1));
	if (!tab_str)
		return (NULL);
	while (str[i])
	{
		if (check_char(str[i], charset))
			car = 0;
		else if (car == 0)
		{
			tab_str[j] = ft_strdup_str(str + i, charset);
			j++;
			car = 1;
		}
		i++;
	}
	tab_str[j] = 0;
	return (tab_str);
}
