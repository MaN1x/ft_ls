/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dir_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:42:21 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/21 22:20:42 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dir_utilities.h"

void	sort_dir_list(t_dir **dir_list)
{
	size_t	i;
	size_t	lst_size;
	t_dir	*current_dir;

	i = 0;
	lst_size = dir_list_size(*dir_list);
	current_dir = *dir_list;
	while (lst_size)
	{
		while (i < lst_size)
		{
			if (i + 1 != lst_size && ft_strcmp(current_dir->dir_name, current_dir->next->dir_name) > 0)
				dir_list_swap(dir_list, current_dir, current_dir->next);
			else
				current_dir = current_dir->next;
			i++;
		}
		i = 0;
		current_dir = *dir_list;
		lst_size--;
	}
}
