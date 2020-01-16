/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:20:43 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/16 13:14:50 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include "lib/libft.h"
# include "dir_utilities/dir_utilities.h"
# include <sys/ioctl.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <errno.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>

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

int						check_args(int argc, char **argv,
		t_file_info **path_list);
int						scan(t_file_info **path_list);
char					*get_full_path(char *path, char *file_name);
void					free_path_list(t_file_info **path_list);

/*
**-----------------------------Print functions----------------------------------
*/

int						find_maxlen(t_file_info *tmp);
int						max_len_pw_nb(t_file_info *tmp);
int						max_len_st_nb(t_file_info *tmp);
int						print_file_list(t_file_info *file_list);
int						use_lstat(char *name, char *path, struct stat *buf);
int						help_print_list(char *name, int max, int kkk);
int						max_len_name(t_file_info *tmp);
int						max_len_name_gr(t_file_info *tmp);
char					*use_gfp(char *c);
void					print_dir(t_dir *dir);
void					print_head(t_dir *dir);
void					print_total(t_file_info	*tmp);
void					print_time(t_file_info	*tmp);
void					print_pw_size(t_file_info	*tmp, int m_size);
void					print_st_size(t_file_info	*tmp, int m_size);
void					print_link_parent(char *path, mode_t st_mode);
void					get_file_acl(char *path);
void					print_list(t_file_info *tmp, int maxlen, int l,
		int col);
void					print_long_list(t_dir *dir);
void					add_param(t_file_info *p, struct stat buf);
void					short_format(t_dir *dir);
void					long_format(t_dir *dir);
void					print_name(t_file_info *tmp, int name_size);
void					print_name_gr(t_file_info *tmp, int size);
void					print_file_type(mode_t st_mode);
void					print_rights(mode_t st_mode);
t_file_info				*ft_take_elem(t_file_info *head, int n);

/*
**------------------------------Scan functions----------------------------------
*/

void					scan_file(t_dir **dir, char *path, char *file_name);
void					scan_directory(t_dir *dir);

#endif
