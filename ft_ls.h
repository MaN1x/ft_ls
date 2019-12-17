/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:20:43 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/17 22:18:10 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "lib/libft.h"
# include <errno.h>

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
	ASCII_SORT,
	TIMESTAMP_SORT
}						t_sort_type;

typedef enum			e_sort_mode
{
	NORMAL_SORT,
	REVERSE_SORT
}						t_sort_mode;

typedef struct			s_file_info
{
	char				*file_name;
	mode_t				st_mode;
	nlink_t				st_link;
	char				*pw_name;
	char				*gr_name;
	struct s_file_info	*next;
}						t_file_info;

typedef struct			s_dir
{
	char				*dir_name;
	t_file_info			*file;
	struct s_dir		*next;
}						t_dir;

void					check_args(int argc, char **argv, t_list **path_list);
void					scan(t_list *path_list);
t_dir					*dir_new(char *dir_name);
void					dir_add(t_dir **dirh, char *dir_name);
void					print_dir(t_dir *dir);
t_file_info				*file_new(void);
void					file_add(t_file_info **file, t_file_info *new_file);
void					free_files(t_file_info **fileh);
void					free_dirlist(t_dir **path_list);
t_dir					*dir_getend(t_dir *dir);

#endif
