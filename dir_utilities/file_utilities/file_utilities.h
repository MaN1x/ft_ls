/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utilities.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:35:46 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/21 22:44:01 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_UTILITIES_H
# define FILE_UTILITIES_H

# include <sys/stat.h>
# include <stdlib.h>
# include "../../lib/libft.h"

typedef struct			s_file_info
{
	char				*file_name;
	mode_t				st_mode;
	nlink_t				st_nlink;
	char				*pw_name;
	char				*gr_name;
	struct s_file_info	*next;
}						t_file_info;

t_file_info				*file_new(void);
void					file_add(t_file_info **file, t_file_info *new_file);
void					free_files(t_file_info **fileh);
void					sort_file_list(t_file_info **file_list);
void					file_list_swap(t_file_info **head, t_file_info *lst1, t_file_info *lst2);
size_t					file_list_size(t_file_info *lst);
size_t					file_size(t_file_info *lst);

#endif
