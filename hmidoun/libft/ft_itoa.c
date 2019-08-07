/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:02:47 by midounhoc         #+#    #+#             */
/*   Updated: 2019/04/16 14:24:46 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_maxint(void)
{
	char	*str;

	str = ft_strnew(11);
	if (str == NULL)
		return (NULL);
	return (ft_strcpy(str, "-2147483648"));
}

static	void	power_neg(int n, int *len, int *div)
{
	*div = 1;
	*len = 0;
	if (n < 0)
	{
		(*len) += 1;
		n *= -1;
	}
	while (n / (*div) > 9)
	{
		(*len) += 1;
		(*div) *= 10;
	}
}

static	char	*ft_fill_str(char *str, int n, int len, int div)
{
	int i;

	i = 0;
	while (i <= len)
	{
		if (n < 0)
		{
			n *= -1;
			str[0] = '-';
			i++;
		}
		str[i] = ('0' + n / div);
		n = n - (n / div) * div;
		div /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		len;
	int		div;
	char	*str;

	if (n == -2147483648)
		return (ft_maxint());
	power_neg(n, &len, &div);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	return (ft_fill_str(str, n, len, div));
}
