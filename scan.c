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

static void	free_list(t_list **path_list)
{
	t_list	*list;
	t_list	*tmp;

	list = *path_list;
	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
}

static void	scan_directory(char *path, t_list **dir)
{
	t_dir			*tmp;
	DIR				*dirp;
	struct dirent	*direntp;
	struct stat		buf;

	dirp = opendir(path);
	while ((direntp = readdir(dirp)))
	{
		stat(direntp->d_name, &buf);
		if (S_ISDIR(buf.st_mode))
		{
			tmp = dir_new(direntp->d_name);
			dir_add(dir, tmp);
		}
	}
	closedir(dirp);
}

void	scan(t_list *path_list)
{
	t_list	*dir;

	dir = NULL;
	while (path_list)
	{
		scan_directory(path_list->content, &dir);
		print_dir(dir);
		path_list = path_list->next;
	}
	free_list(&dir);
}
