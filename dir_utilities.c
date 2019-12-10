/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:03 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/10 22:57:32 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_dirlist(t_dir **path_list)
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

t_dir	*dir_new(char *dir_name)
{
	t_dir	*dir;

	if (!(dir = (t_dir*)malloc(sizeof(t_dir))))
		exit(0);
	dir->file = NULL;
	dir->dir_name = ft_strdup(dir_name);
	dir->next = NULL;
	return (dir);
}

void	dir_add(t_dir **dirh, char *dir_name)
{
	if (*dirh == NULL)
		*dirh = dir_new(dir_name);
	else
		dir_add(&(*dirh)->next, dir_name);
}

t_dir	*dir_getend(t_dir *dir)
{
	while (dir->next)
		dir = dir->next;
	return (dir);
}
