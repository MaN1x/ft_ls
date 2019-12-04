/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:48:49 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/04 17:38:09 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
	DIR				*current_dir;
	struct dirent	*direntp;

	current_dir = opendir(argv[1]);
	while ((direntp = readdir(current_dir)))
	{
		if (*(direntp->d_name) != '.')
			printf("%s\n", direntp->d_name);
	}
	closedir(current_dir);
	return (0);
*/

static void	scan_directory(char *path, t_dir **dir)
{
	t_file_info	*file;
}

void	scan(t_list *path_list, t_dir **dir)
{
	while (path_list)
	{
		scan_directory(path_list->content, dir);
		path_list = path_list->next;
	}
}