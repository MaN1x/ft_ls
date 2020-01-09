/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:35:12 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/09 10:27:30 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utilities.h"

void			free_files(t_file_info **fileh)
{
	t_file_info	*tmp;

	while ((*fileh))
	{
		tmp = (*fileh)->next;
		free((*fileh)->file_name);
		free(*fileh);
		(*fileh) = tmp;
	}
}
