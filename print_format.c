/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:44:01 by wanton            #+#    #+#             */
/*   Updated: 2020/01/17 10:50:07 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_line_break		g_line_break;
extern t_file_perm		g_file_perm;
extern t_file_type		g_file_type;

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

void	print_file_type(mode_t st_mode)
{
	if (S_ISREG(st_mode))
		ft_putchar('-');
	else if (S_ISLNK(st_mode))
		ft_putchar('l');
	else if (S_ISDIR(st_mode))
		ft_putchar('d');
	else if (S_ISBLK(st_mode))
	{
		ft_putchar('b');
		g_file_type = B;
	}
	else if (S_ISCHR(st_mode))
	{
		ft_putchar('c');
		g_file_type = C;
	}
	else if (S_ISSOCK(st_mode))
		ft_putchar('s');
	else if (S_ISFIFO(st_mode))
		ft_putchar('p');
	print_rights(st_mode);
}

void	take_size_const(int m[6], t_file_info *tmp)
{
	m[0] = max_len_pw_nb(tmp);
	m[1] = max_len_st_nb(tmp);
	m[2] = max_len_name(tmp);
	m[3] = max_len_name_gr(tmp);
	m[4] = max_len_major(tmp);
	m[5] = max_len_minor(tmp);
}

int		help_print_list(char *name, int max, int kkk)
{
	ft_putstr(name);
	ft_putspace((int)(max - ft_strlen(name)));
	return (kkk);
}
