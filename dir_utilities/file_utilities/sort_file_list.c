/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_file_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:34:46 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/21 22:34:46 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utilities.h"

void	sort_file_list(t_file_info **file_list)
{
	size_t	i;
	size_t	lst_size;
	t_file_info	*current_file;

	i = 0;
	lst_size = file_list_size(*file_list);
	current_file = *file_list;
	while (lst_size)
	{
		while (i < lst_size)
		{
			if (i + 1 != lst_size && ft_strcmp(current_file->file_name, current_file->next->file_name) > 0)
				file_list_swap(file_list, current_file, current_file->next);
			else
				current_file = current_file->next;
			i++;
		}
		i = 0;
		current_file = *file_list;
		lst_size--;
	}
}
