/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_getend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:45:15 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/09 10:27:30 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dir_utilities.h"

t_dir	*dir_getend(t_dir *dir)
{
	while (dir->next)
		dir = dir->next;
	return (dir);
}
