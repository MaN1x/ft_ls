/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:03 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/04 19:56:32 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*dir_new(char *dir_name)
{
	t_dir	*dir;

	if (!(dir = (t_dir*)malloc(sizeof(t_dir))))
		exit(0);
	dir->dir_name = dir_name;
	dir->next = NULL;
	return (dir);
}

void	dir_add(t_dir **dirh, t_dir *new_dir)
{
	if (*dirh == NULL)
		*dirh = new_dir;
	else
	if ((*dirh)->next == NULL)
		(*dirh)->next = new_dir;
	else
		dir_add(&(*dirh)->next, new_dir);
}
