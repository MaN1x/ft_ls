/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_assist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:09:39 by wanton            #+#    #+#             */
/*   Updated: 2019/12/24 11:14:56 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			find_maxlen(t_file_info *tmp)
{
	t_file_info	*p;
	size_t		n;

	n = 0;
	if (tmp)
	{
		p = tmp;
		while (p)
		{
			if (n < ft_strlen(p->file_name))
				n = ft_strlen(p->file_name);
			p = p->next;
		}
	}
	return (n);
}

t_file_info	*ft_take_elem(t_file_info *head, int n)
{
	int			i;
	t_file_info	*p;

	i = 0;
	p = head;
	while (i++ < n && p)
	{
		p = p->next;
	}
	if (!p)
		return (NULL);
	return (p);
}
