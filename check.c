/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 01:12:33 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/04 04:30:51 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_getnbr(char *str, int *nbr)
{
	int	i;

	*nbr = 0;
	i = -1;
	if(str[0] == '+' || str[0] == '-')
	{
		if (!str[1])
			return (0);
		i++;
	}
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return(0);
	}
	*nbr = ft_atoi(str);
	return(1);
}

int		get_file(t_p_list **head, int fd)
{
	char	*line;
	char	**str;
	int		x_size;
	int		z;
	int		y_size;

	line = NULL;
	y_size = 0;
	while (get_next_line(fd, &line) > 0)
	{
		x_size = 0;
		str = ft_split(line, " \t");
		while(str[x_size])
		{
			if (!ft_getnbr(str[x_size], &z) || !add_to_p_list(head, x_size, y_size, z))
				return (0);
			x_size++;
		}
		y_size++;
	}
	return(1);
}

int	add_to_p_list(t_p_list **head, int x, int y, int z)
{
	t_p_list	*temp;
	t_p_list	*new;

	new = (t_p_list *)malloc(sizeof(t_p_list));
	if (!new)
		return (0);
	new->next = NULL;
	new->x = x;
	new->y = y;
	new->z = z;
	temp = *head;
	if (temp == NULL)
		*head = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (1);
}

void	free_list(t_p_list **head)
{
	if (*head)
	{
		free_list(&(*head)->next);
		free(*head);
	}
}
