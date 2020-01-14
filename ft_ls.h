/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:20:43 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/14 14:43:20 by wanton           ###   ########.fr       */
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
# include <errno.h>

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

typedef enum			e_line_break
{
	FIRST_ELEM,
	NEXT_ELEM
}						t_line_break;

typedef enum			e_total_mode
{
	YES,
	NO
}						t_total_mode;

typedef enum			e_first_head
{
	FIRST,
	FOLLOW
}						t_first_head;

typedef enum			e_file_perm
{
	ALLOW,
	DISALLOW
}						t_file_perm;

void					check_args(int argc, char **argv,
		t_file_info **path_list);
int						scan(t_file_info **path_list);
char					*get_full_path(char *path, char *file_name);

/*
**-----------------------------Print functions----------------------------------
*/

int						find_maxlen(t_file_info *tmp);
int						max_len_pw_nb(t_file_info *tmp);
int						max_len_st_nb(t_file_info *tmp);
int						print_file_list(t_file_info *file_list);
int						use_lstat(char *name, char *path, struct stat *buf);
void					print_dir(t_dir *dir);
void					print_head(t_dir *dir);
void					print_total(t_file_info	*tmp);
void					print_time(t_file_info	*tmp);
void					print_pw_size(t_file_info	*tmp, int m_size);
void					print_st_size(t_file_info	*tmp, int m_size);
void					print_link_parent(char *path, mode_t st_mode);
void					get_file_acl(char *path);
void					print_list(t_file_info *tmp, int maxlen, int l, int col);
void					print_long_list(t_dir *dir);
t_file_info				*ft_take_elem(t_file_info *head, int n);

#endif
