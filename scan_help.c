/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:50:17 by wanton            #+#    #+#             */
/*   Updated: 2020/01/14 13:44:40 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_print_format	g_print_format;
extern t_first_head		g_first_head;

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
		ft_putchar('\n');
		free(dir);
	}
	return (1);
}

int		use_lstat(char *name, char *path, struct stat *buf)
{
	errno = 0;
	if ((lstat(path, buf)) == -1)
	{
		if (errno == ENAMETOOLONG)
		{
			ft_putstr_fd("ls: ", 2);
			ft_putstr_fd(name, 2);
			ft_putstr_fd(": File name too long\n", 2);
		}
		else if (errno == ENOENT)
		{
			ft_putstr_fd("ls: ", 2);
			ft_putstr_fd(name, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
		else if (errno == ENOMEM)
		{
			ft_putstr_fd("ls: ", 2);
			ft_putstr_fd(name, 2);
			ft_putstr_fd(": Permission denied\n", 2);
		}
	}
	else
		return (1);
	return (0);
}
