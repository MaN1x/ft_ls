/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pw_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:52:05 by wanton            #+#    #+#             */
/*   Updated: 2020/01/17 10:54:36 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			max_len_pw_nb(t_file_info *tmp)
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
			foo = ft_lennumber(p->st_nlink);
			if (res < foo)
				res = foo;
			p = p->next;
		}
	}
	return (res);
}

int			max_len_minor(t_file_info *tmp)
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
			foo = ft_lennumber((int)minor(p->st_rdev));
			if (res < foo)
				res = foo;
			p = p->next;
		}
	}
	return (res);
}

void		print_pw_size(t_file_info *tmp, int m_size)
{
	ft_putspace(m_size - ft_lennumber(tmp->st_nlink));
	ft_putnbr(tmp->st_nlink);
	ft_putchar(' ');
}

int			max_len_name(t_file_info *tmp)
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
			foo = ft_strlen(p->pw_name);
			if (res < foo)
				res = foo;
			p = p->next;
		}
	}
	return (res);
}

void		print_name(t_file_info *tmp, int name_size)
{
	ft_putstr(tmp->pw_name);
	ft_putspace(name_size - (int)ft_strlen(tmp->pw_name));
	ft_putstr("  ");
}
