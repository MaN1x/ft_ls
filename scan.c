/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:48:49 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/09 23:51:42 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_print_format	g_print_format;
extern t_scan_type		g_scan_type;
extern t_scan_mode		g_scan_mode;
extern t_sort_type		g_sort_type;
extern t_sort_mode		g_sort_mode;

/*
	DIR				*current_dir;
	struct dirent	*direntp;

	current_dir = opendir(argv[1]);
	while ((direntp = readdir(current_dir)))
	{
		if (*(direntp->d_name) != '.')
			printf("%s\n", direntp->d_name);
	}
	closedir(current_dir);
	return (0);
*/

static void	free_files(t_file_info **fileh)
{
	t_file_info	*tmp;

	while ((*fileh))
	{
		tmp = (*fileh)->next;
		free(*fileh);
		(*fileh) = tmp;
	}
}

static void	free_list(t_dir **path_list)
{
	t_dir	*list;
	t_dir	*tmp;

	list = *path_list;
	while (list)
	{
		tmp = list->next;
		free_files(&list->file);
		free(list->dir_name);
		free(list);
		list = tmp;
	}
}

static void	scan_file(t_dir **dir, char *path)
{
	struct stat	buf;
	t_file_info	*file;

	file = file_new();
	stat(path, &buf);
	file->file_name = ft_strdup(path);
	file_add(&(*dir)->file, file);
}

static void	scan_directory(char *path, t_dir **dir)
{
	char 			*full_path;
	DIR				*dirp;
	struct dirent	*direntp;

	dirp = opendir(path);
	while ((direntp = readdir(dirp)))
	{
		if (g_scan_type == RECURSIVE_SCAN && direntp->d_type == DT_DIR)
			dir_add(dir, direntp->d_name);
		full_path = ft_strjoin(path, direntp->d_name);
		scan_file(dir, full_path);
		free(full_path);
	}
	closedir(dirp);
}

void	scan(t_list *path_list)
{
	t_dir	*dir;

	dir = NULL;
	while (path_list)
	{
		scan_directory(path_list->content, &dir);
		print_dir(dir);
		path_list = path_list->next;
	}
	free_list(&dir);
}
