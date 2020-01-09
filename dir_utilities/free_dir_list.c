/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dir_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:43:26 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/09 10:27:30 by wanton           ###   ########.fr       */
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
