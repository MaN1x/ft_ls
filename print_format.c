/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:44:01 by wanton            #+#    #+#             */
/*   Updated: 2020/01/15 16:51:51 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_line_break		g_line_break;
extern t_file_perm		g_file_perm;

void	short_format(t_dir *dir)
{
	t_file_info	*tmp;
	char		*name;
	int			col;

	while (dir)
	{
		if (g_line_break == NEXT_ELEM)
			ft_putchar('\n');
		col = 0;
		g_line_break = NEXT_ELEM;
		tmp = dir->file;
		print_head(dir);
		print_list(tmp, (find_maxlen(tmp) + 1), file_size(tmp), col);
		if (g_file_perm == DISALLOW)
		{
			ft_putstr_fd("ls: ", 2);
			if (!(name = ft_strrchr(dir->dir_name, '/')))
				name = dir->dir_name;
			ft_putstr_fd(++name, 2);
			ft_putstr_fd(": Permission denied\n", 2);
			g_file_perm = ALLOW;
		}
		dir = dir->next;
	}
}

void	long_format(t_dir *dir)
{
	char	*name;

	while (dir)
	{
		if (g_line_break == NEXT_ELEM)
			ft_putchar('\n');
		g_line_break = NEXT_ELEM;
		print_long_list(dir);
		if (g_file_perm == DISALLOW)
		{
			ft_putstr_fd("ls: ", 2);
			if (!(name = ft_strrchr(dir->dir_name, '/')))
				name = dir->dir_name;
			ft_putstr_fd(++name, 2);
			ft_putstr_fd(": Permission denied\n", 2);
			g_file_perm = ALLOW;
		}
		dir = dir->next;
	}
}

int 	help_print_list(char *name, int max, int kkk)
{
	ft_putstr(name);
	ft_putspace((int)(max - ft_strlen(name)));
	return (kkk);
}