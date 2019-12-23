/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:20:43 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/23 14:23:27 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h> // здесь константа TIOCGWINSZ для ioctl
# include <stdlib.h>
# include "lib/libft.h"
# include "dir_utilities/dir_utilities.h"
# include <sys/ioctl.h> // для получения размера консоли
# include <unistd.h>  // здесь константа STDOUT_FILENO для ioctl

typedef enum			e_print_format
{
	SHORT_FORMAT,
	LONG_FORMAT
}						t_print_format;

typedef enum			e_scan_type
{
	SCAN_CURRENT_DIRECTORY,
	RECURSIVE_SCAN
}						t_scan_type;

typedef enum			e_scan_mode
{
	IGNORE_DOT_NAMES,
	SCAN_ALL
}						t_scan_mode;

typedef enum			e_sort_type
{
	NO_SORT,
	ASCII_SORT,
	TIMESTAMP_SORT
}						t_sort_type;

typedef enum			e_sort_mode
{
	NORMAL_SORT,
	REVERSE_SORT
}						t_sort_mode;

void					check_args(int argc, char **argv, t_list **path_list);
void					scan(t_list *path_list);
void					print_dir(t_dir *dir);

#endif
