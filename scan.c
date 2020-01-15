/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:48:49 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/15 16:37:48 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_total_mode		g_total_mode;
extern t_first_head		g_first_head;

void	delete_lst(t_file_info **path_list, t_file_info *p)
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
		{
			delete_lst(path_list, p);
			p = *path_list;
		}
		else
			p = p->next;
	}
}

int		check_path(t_file_info *path_list)
{
	t_file_info	*p;
	struct stat	buf;
	char		*full_path;

	p = path_list;
	while (p)
	{
		if (*p->file_name != '/')
		{
			if (!(full_path = get_full_path(".", p->file_name)))
				return (0);
		}
		else
			if (!(full_path = get_full_path("", p->file_name)))
				return (0);
		if (!(use_lstat(p->file_name, full_path, &buf)))
		{
			free(full_path);
			p = p->next;
			continue;
		}
		free(full_path);
		add_param(p, buf);
		p = p->next;
	}
	return (1);
}

int		scan(t_file_info **path_list)
{
	t_dir		*dir;
	t_file_info *file_list;
	t_file_info *tmp;

	if (!(check_path(*path_list)))
		return (0);
	separate_file(path_list, &file_list);
	if (!(print_file_list(file_list)))
	{
		file_list = NULL;
		return (0);
	}
	file_list = NULL;
	g_total_mode = YES;
//	if ((tmp = *path_list)->next)
//		g_first_head = FOLLOW;
	/*
	 * после функции separate_file path_list становится NULL, т.к. там цикл работает, пока
	 * path_list не закончится. Ты передаёшь туда указатель на указатель, и поэтому
	 * path_list меняется и за перделами separate_file. Таким образом *path_list->next
	 * вызывает ошибку
	 */
	tmp = *path_list;
	while (tmp)
	{
		dir = NULL;
		dir_add(&dir, tmp->file_name);
		scan_directory(dir);
		free_dirlist(&dir);
		tmp = tmp->next;
	}
	return (1);
}
