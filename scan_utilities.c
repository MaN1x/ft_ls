/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:12:15 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/14 13:40:28 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scan_utilities.h"

extern t_print_format	g_print_format;
extern t_scan_type		g_scan_type;
extern t_scan_mode		g_scan_mode;

char				*get_full_path(char *path, char *file_name)
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
	char		*full_path;

	full_path = get_full_path(path, file_name);
	file = file_new();
	lstat(full_path, &buf);
	free(full_path);
	file->file_name = ft_strdup(file_name);
	file->st_mode = buf.st_mode;
	file->st_nlink = buf.st_nlink;
	file->pw_name = getpwuid(buf.st_uid)->pw_name;
	file->gr_name = getgrgid(buf.st_gid)->gr_name;
	file->st_size = buf.st_size;
	file->time = buf.st_mtimespec.tv_sec;
	file->block = buf.st_blocks; // total
	file_add(&(*dir)->file, file);
}

static void			recursive_scan(t_dir *dir)
{
	t_dir		*tmp_dir;
	t_file_info	*file;
	char		*full_path;

	file = dir->file;
	while (file)
	{
		if (S_ISDIR((*file).st_mode) &&
			ft_strcmp(file->file_name, ".") != 0 &&
			ft_strcmp(file->file_name, "..") != 0)
		{
			full_path = get_full_path(dir->dir_name, file->file_name);
			tmp_dir = dir_new(full_path);
			scan_directory(tmp_dir);
			free_dirlist(&tmp_dir);
			free(full_path);
		}
		file = file->next;
	}
}

void				scan_directory(t_dir *dir)
{
	DIR				*dirp;
	struct dirent	*direntp;

	dirp = opendir(dir->dir_name);
	while ((direntp = readdir(dirp)))
	{
		if (g_scan_mode == IGNORE_DOT_NAMES && *direntp->d_name != '.')
			scan_file(&dir, (dir)->dir_name, direntp->d_name);
		else if (g_scan_mode == SCAN_ALL)
			scan_file(&dir, (dir)->dir_name, direntp->d_name);
	}
	closedir(dirp);
	sort_file_list(&dir->file);
	print_dir(dir);
	if (g_scan_type == RECURSIVE_SCAN)
		recursive_scan(dir);
}
