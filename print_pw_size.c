/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pw_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:52:05 by wanton            #+#    #+#             */
/*   Updated: 2020/01/09 10:27:30 by wanton           ###   ########.fr       */
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

void		print_pw_size(t_file_info *tmp, int m_size)
{
	t_file_info	*p;

	p = tmp;
	ft_putspace(m_size - ft_lennumber(tmp->st_nlink));
	ft_putnbr(tmp->st_nlink);
	ft_putchar('\t');
}
