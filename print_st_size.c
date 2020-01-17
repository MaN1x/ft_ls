/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_st_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:55:38 by wanton            #+#    #+#             */
/*   Updated: 2020/01/17 11:00:32 by wanton           ###   ########.fr       */
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

int			max_len_major(t_file_info *tmp)
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
			foo = ft_lennumber((int)major(p->st_rdev));
			if (res < foo)
				res = foo;
			p = p->next;
		}
	}
	return (res);
}

void		print_st_size(t_file_info *tmp, int m_size, int ma, int mi)
{
	if (((g_file_type == C) || (g_file_type == B)) && (S_ISCHR(tmp->st_mode)
	|| S_ISBLK(tmp->st_mode)))
	{
		ft_putspace((ma + 1) - ft_lennumber((int)major(tmp->st_rdev)));
		ft_putnbr((int)major(tmp->st_rdev));
		ft_putstr(", ");
		ft_putspace(mi - ft_lennumber((int)minor(tmp->st_rdev)));
		ft_putnbr((int)minor(tmp->st_rdev));
	}
	else
	{
		if ((g_file_type == C) || (g_file_type == B))
			ft_putspace(ma + mi + 2);
		ft_putspace(m_size - ft_lennumber(tmp->st_size));
		ft_putnbr(tmp->st_size);
	}
	ft_putchar(' ');
}

int			max_len_name_gr(t_file_info *tmp)
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
	ft_putspace(size - (int)ft_strlen(tmp->gr_name));
	ft_putstr("  ");
}
