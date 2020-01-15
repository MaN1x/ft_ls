/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:24:53 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/15 14:32:59 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern	t_print_format	g_print_format;
extern	t_scan_mode		g_scan_mode;
extern	t_scan_type		g_scan_type;
extern	t_sort_mode		g_sort_mode;
extern	t_sort_type		g_sort_type;

static void	err_message(const char *argv)
{
	printf("ls: illegal option -- %c\nusage: ls [-Ralrt] [file ...]\n", *argv);
}

static void	check_flag(char *argv)
{
	argv++;
	while (*argv)
	{
		if (*argv == 'l')
			g_print_format = LONG_FORMAT;
		else if (*argv == 'R')
			g_scan_type = RECURSIVE_SCAN;
		else if (*argv == 'a')
			g_scan_mode = SCAN_ALL;
		else if (*argv == 'r')
			g_sort_mode = REVERSE_SORT;
		else if (*argv == 't')
			g_sort_type = TIMESTAMP_SORT;
		else
		{
			err_message(argv);
			exit(0);
		}
		argv++;
	}
}

void		check_args(int argc, char **argv, t_file_info **path_list)
{
	int			arg_number;
	t_file_info	*tmp_path;
	int			flags;

	flags = 1;
	arg_number = 0;
	while (++arg_number < argc)
	{
		if (argv[arg_number][0] == '-' && flags)
			check_flag(argv[arg_number]);
		else
		{
			flags = 0;
			tmp_path = file_new();
			tmp_path->file_name = ft_strdup(argv[arg_number]);
			file_add(path_list, tmp_path);
		}
	}
	if (file_list_size(*path_list) == 0)
	{
		*path_list = file_new();
		(*path_list)->file_name = ft_strdup(".");
	}
}
