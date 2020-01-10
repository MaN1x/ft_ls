/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:20:43 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/10 09:47:55 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <time.h>
# include <stdio.h> // здесь константа TIOCGWINSZ для ioctl
# include <stdlib.h> // test
# include "lib/libft.h"
# include "dir_utilities/dir_utilities.h"
# include <sys/ioctl.h> // для получения размера консоли
# include <unistd.h>  // здесь константа STDOUT_FILENO для ioctl
# include <fcntl.h> // for open()
# include <sys/xattr.h>
# include <sys/acl.h>

# define BUF_SIZE 100

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
char					*get_full_path(char *path, char *file_name);

/*
**-----------------------------Print functions----------------------------------
*/

int						find_maxlen(t_file_info *tmp);
int						max_len_pw_nb(t_file_info *tmp);
int						max_len_st_nb(t_file_info *tmp);
void					print_dir(t_dir *dir);
void					print_head(t_dir *dir);
void					print_total(t_file_info	*tmp);
void					print_time(t_file_info	*tmp);
void					print_pw_size(t_file_info	*tmp, int m_size);
void					print_st_size(t_file_info	*tmp, int m_size);
void					print_link_parent(char *path, mode_t st_mode);
void					get_file_acl(char *path);
t_file_info				*ft_take_elem(t_file_info *head, int n);

#endif
