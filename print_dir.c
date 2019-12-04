/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:04:01 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/04 19:56:32 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

void	print_dir(t_dir *dir)
{
	while (dir)
	{
		//if (*dir->dir_name != '.')
		{
			printf("dir_name: \"%s\"\n", dir->dir_name);
			//printf("*files info*\n");
		}
		dir = dir->next;
	}
}