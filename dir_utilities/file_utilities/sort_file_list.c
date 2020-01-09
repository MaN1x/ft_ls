/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_file_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:34:46 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/09 10:46:37 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utilities.h"
#include "../../ft_ls.h"

extern t_sort_type		g_sort_type;
extern t_sort_mode		g_sort_mode;

void	ascii_sort(t_file_info **file_list)
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
			if (i + 1 != lst_size && ft_strcmp(current_file->file_name,
					current_file->next->file_name) > 0)
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

void	time_sort(t_file_info **file_list)
{
	int			flag;
	t_file_info	*current_file;

	flag = 1;
	current_file = *file_list;
	while (flag == 1)
	{
		flag = 0;
		while (current_file->next)
		{
			if (current_file->time < current_file->next->time)
			{
				file_list_swap(file_list, current_file, current_file->next);
				flag = 1;
			}
			else
				current_file = current_file->next;
		}
		current_file = *file_list;
	}
}

void	sort_file_list(t_file_info **file_list)
{
	if (*file_list)
	{
		if (g_sort_type == ASCII_SORT)
			ascii_sort(file_list);
		if (g_sort_type == TIMESTAMP_SORT)
			time_sort(file_list);
	}
}
