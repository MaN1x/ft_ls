/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 22:52:44 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/10 23:39:00 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			free_files(t_file_info **fileh)
{
	t_file_info	*tmp;

	while ((*fileh))
	{
		tmp = (*fileh)->next;
		free((*fileh)->file_name);
		free(*fileh);
		(*fileh) = tmp;
	}
}

t_file_info		*file_new(void)
{
	t_file_info *file;

	if (!(file = (t_file_info*)malloc(sizeof(t_file_info))))
		exit(0);
	file->file_name = NULL;
	file->next = NULL;
	file->gr_name = NULL;
	file->pw_name = NULL;
	return (file);
}

void			file_add(t_file_info **file, t_file_info *new_file)
{
	if (*file == NULL)
		*file = new_file;
	else
		file_add(&((*file)->next), new_file);
}
