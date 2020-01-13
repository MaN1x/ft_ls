/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:48:49 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/13 14:51:36 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scan_utilities.h"

extern t_sort_type		g_sort_type;
extern t_print_format	g_print_format;
extern t_total_mode		g_total_mode;

void	delete_lst(t_file_info **path_list, t_file_info *p)
{
	t_file_info *tmp;

	tmp = *path_list;
	if (tmp == p)
	{
		*path_list = p->next;
	}
	else
	{
		while (tmp->next != p)
			tmp = tmp->next;
		tmp->next = p->next;
	}
	free(p);
}

void	remove_lst(t_file_info **path_list, t_file_info *p)
{
	t_file_info *tmp;

	tmp = *path_list;
	if (tmp == p)
		*path_list = p->next;
	else
	{
		while (tmp->next != p)
			tmp = tmp->next;
		tmp->next = p->next;
	}
	p->next = NULL;
}

void	separate_file(t_file_info **path_list, t_file_info **file_list)
{
	t_file_info	*p;

	p = *path_list;
	*file_list = NULL;
	while (p)
	{
		if (S_ISREG(p->st_mode) || S_ISLNK(p->st_mode))
		{
			file_add(file_list, p);
			remove_lst(path_list, p);
			p = *path_list;
		}
		else if (!(S_ISDIR(p->st_mode)))
			delete_lst(path_list, p);
		else
			p = p->next;
	}
}

void 	check_path(t_file_info *path_list)
{
	t_file_info	*p;
	struct stat	buf;
	char		*full_path;

	p = path_list;
	while (p)
	{
		full_path = get_full_path(".", p->file_name);
		if ((lstat(full_path, &buf)) == -1)
		{
			ft_putstr(p->file_name);
			ft_putstr(" - error file\n\n");
			free(full_path);
			p = p->next;
			continue;
		}
		free(full_path);
		p->st_mode = buf.st_mode;
		p->st_nlink = buf.st_nlink;
		p->pw_name = getpwuid(buf.st_uid)->pw_name;
		p->gr_name = getgrgid(buf.st_gid)->gr_name;
		p->st_size = buf.st_size;
		p->time = buf.st_mtimespec.tv_sec;
		p->block = buf.st_blocks;
		p = p->next;
	}
}

void	scan(t_file_info *path_list)
{
	int			col;
	t_dir		*dir;
	t_file_info *file_list;

	check_path(path_list);
	file_list = NULL;
	separate_file(&path_list, &file_list);
	dir = dir_new(".");
	dir->file = file_list;
	col = 0;
	sort_file_list(&file_list);
	if (g_print_format == SHORT_FORMAT)
		print_list(file_list, (find_maxlen(file_list) + 4),
				file_size(file_list), col);
	else if (g_print_format == LONG_FORMAT)
		print_long_list(dir);
	ft_putchar('\n');
	free(dir);
	g_total_mode = YES;
	while (path_list)
	{
		dir = NULL;
		dir_add(&dir, path_list->file_name);
		scan_directory(dir);
		free_dirlist(&dir);
	//	dir = NULL;	//удали эту строчку и проверь на утечки. Почему так работает? P.S. Проверяй с несколькими аргументами
	//				UPD Кажется я понял, С - это и правда 2 в 16 способов отстрелить себе конечности.
		path_list = path_list->next;
	}
}
