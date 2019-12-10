/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:48:49 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/10 23:37:32 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_print_format	g_print_format;
extern t_scan_type		g_scan_type;
extern t_scan_mode		g_scan_mode;
extern t_sort_type		g_sort_type;
extern t_sort_mode		g_sort_mode;

static char				*get_full_path(char *path, char *file_name)
{
	char *full_path;
	char *tmp;

	if (path[ft_strlen(path) - 1] != '/')
	{
		if (!(tmp = ft_strjoin(path, "/")))
			exit(0);
		if (!(full_path = ft_strjoin(tmp, file_name)))
			exit(0);
		free(tmp);
	}
	else if (!(full_path = ft_strjoin(path, file_name)))
		exit(0);
	return (full_path);
}

static void				scan_file(t_dir **dir, char *path, char *file_name)
{
	struct stat	buf;
	t_file_info	*file;

	file = file_new();
	stat(path, &buf);
	file->file_name = ft_strdup(file_name);
	file_add(&(*dir)->file, file);
}

static void				scan_directory(t_dir *dir)
{
	char			*full_path;
	DIR				*dirp;
	struct dirent	*direntp;

	dirp = opendir(dir->dir_name);
	while ((direntp = readdir(dirp)))
	{
		if (g_scan_type == RECURSIVE_SCAN && direntp->d_type == DT_DIR &&
			ft_strcmp(direntp->d_name, ".") != 0 &&
			ft_strcmp(direntp->d_name, "..") != 0)
		{
			full_path = get_full_path(dir->dir_name, direntp->d_name);
			dir_add(&dir, full_path);
			free(full_path);
			scan_directory((dir_getend(dir)));
		}
		scan_file(&dir, (dir)->dir_name, direntp->d_name);
	}
	closedir(dirp);
}

void					scan(t_list *path_list)
{
	t_dir	*dir;

	dir = NULL;
	while (path_list)
	{
		dir_add(&dir, path_list->content);
		scan_directory(dir);
		print_dir(dir);
		free_dirlist(&dir);
		dir = NULL;
		path_list = path_list->next;
	}
}
