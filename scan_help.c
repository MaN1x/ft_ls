/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:50:17 by wanton            #+#    #+#             */
/*   Updated: 2020/01/15 15:10:31 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_print_format	g_print_format;
extern t_first_head		g_first_head;
extern t_line_break		g_line_break;

int		print_file_list(t_file_info *file_list)
{
	int			col;
	t_dir		*dir;

	if (file_list)
	{
		if (!(dir = dir_new(".")))
			return (0);
		dir->file = file_list;
		col = 0;
		sort_file_list(&file_list);
		if (g_print_format == SHORT_FORMAT)
			print_list(file_list, (find_maxlen(file_list) + 4),
					file_size(file_list), col);
		else if (g_print_format == LONG_FORMAT)
			print_long_list(dir);
		g_first_head = FOLLOW;
		g_line_break = NEXT_ELEM;
		free(dir);
	}
	return (1);
}

void	add_param(t_file_info *p, struct stat buf)
{
	p->st_mode = buf.st_mode;
	p->st_nlink = buf.st_nlink;
	p->pw_name = getpwuid(buf.st_uid)->pw_name;
	p->gr_name = getgrgid(buf.st_gid)->gr_name;
	p->st_size = buf.st_size;
	p->time = buf.st_mtimespec.tv_sec;
	p->block = buf.st_blocks;
}

void	start_error_message(char *name)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(name, 2);
}

int		use_lstat(char *name, char *path, struct stat *buf)
{
	errno = 0;
	if ((lstat(path, buf)) == -1)
	{
		if (errno == ENAMETOOLONG)
		{
			start_error_message(name);
			ft_putstr_fd(": File name too long\n", 2);
		}
		else if (errno == ENOENT)
		{
			start_error_message(name);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
		else if (errno == ENOMEM)
		{
			start_error_message(name);
			ft_putstr_fd(": Permission denied\n", 2);
		}
	}
	else
	{
		return (1);
	}
	return (0);
}
