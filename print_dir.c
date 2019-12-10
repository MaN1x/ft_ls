/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:04:01 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/10 23:21:22 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

void	print_dir(t_dir *dir)
{
	t_file_info	*tmp;

	while (dir)
	{
		tmp = dir->file;
		//if (*dir->dir_name != '.')
		//{
			printf("dir_name: \"%s\"\n", dir->dir_name);
			while (tmp)
			{
				printf("file: \"%s\"\n", tmp->file_name);
				tmp = tmp->next;
			}
			//printf("*files info*\n");
		//}
		dir = dir->next;
	}
}