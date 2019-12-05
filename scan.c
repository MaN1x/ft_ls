/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:48:49 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/04 19:56:32 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

static void	free_list(t_dir **path_list)
{
	t_dir	*list;
	t_dir	*tmp;

	list = *path_list;
	while (list)
	{
		tmp = list->next;
		free(list->dir_name);
		free(list);
		list = tmp;
	}
}

static void	scan_directory(char *path, t_dir **dir)
{
	char 			*full_path;
	DIR				*dirp;
	struct dirent	*direntp;
	struct stat		buf;

	dirp = opendir(path);
	while ((direntp = readdir(dirp)))
	{
		full_path = ft_strjoin(path, direntp->d_name);
		stat(full_path, &buf);
		if (S_ISDIR(buf.st_mode))
			dir_add(dir, direntp->d_name);
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
