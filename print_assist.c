/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_assist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:09:39 by wanton            #+#    #+#             */
/*   Updated: 2020/01/15 14:48:04 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_total_mode		g_total_mode;
extern t_first_head		g_first_head;

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

void		print_total(t_file_info *tmp)
{
	t_file_info		*p;
	unsigned long	res;
	int				count;

	if (g_total_mode == NO)
		return ;
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
		ft_putnbr((int)res);
		ft_putchar('\n');
	}
}

void		print_head(t_dir *dir)
{
	if (g_first_head == FOLLOW)
	{
		ft_putstr(dir->dir_name);
		ft_putstr(":\n");
	}
	g_first_head = FOLLOW;
}

void		print_time(t_file_info *tmp)
{
	struct tm	lt;
	char		*str;
	int			i;

	i = 4;
	str = ctime(&(tmp->time));
	while (i--)
		str++;
	if (tmp->time < (time(NULL) - 15811200))
	{
		localtime_r(&tmp->time, &lt);
		write(1, str, 6);
		ft_putstr("  ");
		ft_putnbr(lt.tm_year + 1900);
	}
	else
		write(1, str, 12);
	ft_putchar(' ');
}
