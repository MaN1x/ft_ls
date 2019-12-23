/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:44:36 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/23 12:17:47 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_print_format	g_print_format = SHORT_FORMAT;
t_scan_type		g_scan_type = SCAN_CURRENT_DIRECTORY;
t_scan_mode		g_scan_mode = IGNORE_DOT_NAMES;
t_sort_type		g_sort_type = ASCII_SORT;
t_sort_mode		g_sort_mode = NORMAL_SORT;

static void print_path_list(t_list *path_list)
{
	while (path_list)
	{
		ft_putstr("path = \"");
		ft_putstr(path_list->content);
		ft_putstr("\"\n");
		path_list = path_list->next;
	}
}

static void	free_path_list(t_list **path_list)
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

static void	sort_path_list(t_list **path_list)
{
	size_t	i;
	size_t	lst_size;
	t_list	*current_list;

	i = 0;
	lst_size = ft_lstsize(*path_list);
	current_list = *path_list;
	while (lst_size)
	{
		while (i < lst_size)
		{
			if (i + 1 != lst_size && ft_strcmp(current_list->content, current_list->next->content) > 0)
				ft_lstswap(path_list, current_list, current_list->next);
			else
				current_list = current_list->next;
			i++;
		}
		i = 0;
		current_list = *path_list;
		lst_size--;
	}
}

int	main(int argc, char **argv)
{
	t_list	*path_list;

	path_list = NULL;
	check_args(argc, argv, &path_list);
	/*
	printf("============FLAGS================\n");
	printf("print format = %d\n", g_print_format);
	printf("scan type = %d\n", g_scan_type);
	printf("scan mode = %d\n", g_scan_mode);
	printf("sort type = %d\n", g_sort_type);
	printf("sort mode = %d\n", g_sort_mode);
	printf("========END FLAGS================\n");
	*/
	print_path_list(path_list);
	ft_putstr("=================\n");

	sort_path_list(&path_list);
	print_path_list(path_list);
	scan(path_list);
	free_path_list(&path_list);
	//print_path_list(path_list);
	return 0;
}
