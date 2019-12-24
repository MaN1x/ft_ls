/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_assist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:09:39 by wanton            #+#    #+#             */
/*   Updated: 2019/12/24 14:13:44 by wanton           ###   ########.fr       */
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

void		print_total(t_file_info	*tmp)
{
	t_file_info		*p;
	unsigned long	res;
	int 			count;

	res = 0;
	count = 0;
	p = tmp;
	while (p)
	{
		res += (p->block);
		p = p->next;
		count++;
	}
	if (count != 0)
	{
		ft_putstr("total ");
		ft_putnbr((int) res);
		ft_putchar('\n');
	}
}

void		print_head(t_dir *dir)
{
	if (dir && ((ft_strcmp(dir->dir_name, "."))))
	{
		ft_putstr(dir->dir_name);
		ft_putstr(":\n");
	}
}

void		print_time(t_file_info	*tmp)
{
	char 	*str;
	int		i;

	i = 4;
	str = ctime(&(tmp->time));
	while (i--)
	{
		str++;
	}
	write(1, str, 12);
	ft_putchar(' ');
}