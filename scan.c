/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:48:49 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/09 10:27:30 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scan_utilities.h"

extern t_sort_type	g_sort_type;

void	scan(t_list *path_list)
{
	t_dir	*dir;

	dir = NULL;
	while (path_list)
	{
		dir_add(&dir, path_list->content);
		scan_directory(dir);
		if (g_sort_type == ASCII_SORT)
			sort_file_list(&dir->file);
		print_dir(dir);
		free_dirlist(&dir);
		dir = NULL;
		path_list = path_list->next;
	}
}
