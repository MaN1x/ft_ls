/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:44:03 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/21 18:44:34 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dir_utilities.h"

t_dir	*dir_new(char *dir_name)
{
	t_dir	*dir;

	if (!(dir = (t_dir*)malloc(sizeof(t_dir))))
		exit(0);
	dir->file = NULL;
	dir->dir_name = ft_strdup(dir_name);
	dir->next = NULL;
	return (dir);
}
