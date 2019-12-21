/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_utilities.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:15:41 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/21 23:03:26 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAN_UTILITIES_H
# define SCAN_UTILITIES_H

# include "ft_ls.h"
# include <dirent.h>
# include <pwd.h>
# include <grp.h>

void	scan_file(t_dir **dir, char *path, char *file_name);
void	scan_directory_utils(t_dir *dir, struct dirent	*direntp);
void	scan_directory(t_dir *dir);

#endif
