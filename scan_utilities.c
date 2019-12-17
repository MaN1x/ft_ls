/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:12:15 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/17 23:49:39 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scan_utilities.h"

extern t_print_format	g_print_format;
extern t_scan_type		g_scan_type;
extern t_scan_mode		g_scan_mode;

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

void				scan_file(t_dir **dir, char *path, char *file_name)
{
	struct stat	buf;
	t_file_info	*file;
	char 		*full_path;

	full_path = get_full_path(path, file_name);
	file = file_new();
	stat(full_path, &buf);
	free(full_path);
	file->file_name = ft_strdup(file_name);
	file->st_mode = buf.st_mode;
	file_add(&(*dir)->file, file);
}

void				scan_directory_utils(t_dir *dir, struct dirent	*direntp)
{
	char			*full_path;

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

void				scan_directory(t_dir *dir)
{
	DIR				*dirp;
	struct dirent	*direntp;

	dirp = opendir(dir->dir_name);
	while ((direntp = readdir(dirp)))
	{
		if (g_scan_mode == IGNORE_DOT_NAMES && *direntp->d_name != '.')
			scan_directory_utils(dir, direntp);
		else if (g_scan_mode == SCAN_ALL)
			scan_directory_utils(dir, direntp);
	}
	closedir(dirp);
}
