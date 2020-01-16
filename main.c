/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:11:26 by wanton            #+#    #+#             */
/*   Updated: 2020/01/16 12:35:12 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_print_format	g_print_format = SHORT_FORMAT;
t_scan_type		g_scan_type = SCAN_CURRENT_DIRECTORY;
t_scan_mode		g_scan_mode = IGNORE_DOT_NAMES;
t_sort_type		g_sort_type = ASCII_SORT;
t_sort_mode		g_sort_mode = NORMAL_SORT;
t_line_break	g_line_break = FIRST_ELEM;
t_total_mode	g_total_mode = NO;
t_first_head	g_first_head = FIRST;
t_file_perm		g_file_perm = ALLOW;

void		free_path_list(t_file_info **path_list)
{
	t_file_info	*list;
	t_file_info	*tmp;

	list = *path_list;
	while (list)
	{
		tmp = list->next;
		if (list->file_name)
			free(list->file_name);
		free(list);
		list = tmp;
	}
}

static void	sort_path_list(t_file_info **path_list)
{
	size_t		i;
	size_t		lst_size;
	t_file_info	*current_list;

	i = 0;
	lst_size = file_list_size(*path_list);
	current_list = *path_list;
	while (lst_size)
	{
		while (i < lst_size)
		{
			if (i + 1 != lst_size && ft_strcmp(current_list->file_name,
					current_list->next->file_name) > 0)
				file_list_swap(path_list, current_list, current_list->next);
			else
				current_list = current_list->next;
			i++;
		}
		i = 0;
		current_list = *path_list;
		lst_size--;
	}
}

int			main(int argc, char **argv)
{
	t_file_info		*path_list;

	path_list = NULL;
	if (!(check_args(argc, argv, &path_list)))
	{
		free_path_list(&path_list);
		return (0);
	}
	sort_path_list(&path_list);
	if (!(scan(&path_list)))
	{
		free_path_list(&path_list);
		return (0);
	}
	free_path_list(&path_list);
	return (1);
}
