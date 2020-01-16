/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:44:36 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/16 10:40:36 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dir_utilities.h"

void	dir_add(t_dir **dirh, char *dir_name)
{
	if (*dirh == NULL)
		*dirh = dir_new(dir_name);
	else
		dir_add(&(*dirh)->next, dir_name);
}
