/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dir_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:43:26 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/21 18:44:01 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dir_utilities.h"

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
