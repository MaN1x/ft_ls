/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_utilities.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:46:00 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/16 10:40:36 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIR_UTILITIES_H
# define DIR_UTILITIES_H

# include <stdlib.h>
# include "file_utilities/file_utilities.h"
# include "../lib/libft.h"

typedef struct			s_dir
{
	char				*dir_name;
	t_file_info			*file;
	struct s_dir		*next;
}						t_dir;

t_dir					*dir_new(char *dir_name);
void					dir_add(t_dir **dirh, char *dir_name);
void					free_dirlist(t_dir **path_list);

#endif
