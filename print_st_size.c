/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_st_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:55:38 by wanton            #+#    #+#             */
/*   Updated: 2020/01/16 14:06:41 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_file_type		g_file_type;

int			max_len_st_nb(t_file_info *tmp)
{
	t_file_info	*p;
	int			res;
	int			foo;

	res = 0;
	if (tmp)
	{
		p = tmp;
		while (p)
		{
			foo = ft_lennumber(p->st_size);
			if (res < foo)
				res = foo;
			p = p->next;
		}
	}
	return (res);
}
//TODO: сделать нормальные отступы для major и minor
void		print_st_size(t_file_info *tmp, int m_size)
{
	if ((g_file_type == C) || (g_file_type == B))
	{
		ft_putnbr((int)major(tmp->st_rdev));
		ft_putstr(", ");
		ft_putnbr((int)minor(tmp->st_rdev));
	}
	else
	{
		ft_putspace(m_size - ft_lennumber(tmp->st_size));
		ft_putnbr(tmp->st_size);
	}
	ft_putchar(' ');
}

int 		max_len_name_gr(t_file_info *tmp)
{
	t_file_info	*p;
	int			res;
	int			foo;

	res = 0;
	if (tmp)
	{
		p = tmp;
		while (p)
		{
			foo = ft_strlen(p->gr_name);
			if (res < foo)
				res = foo;
			p = p->next;
		}
	}
	return (res);
}

void		print_name_gr(t_file_info *tmp, int size)
{
	ft_putstr(tmp->gr_name);
	ft_putspace(size - (int) ft_strlen(tmp->gr_name));
	ft_putstr("  ");
}