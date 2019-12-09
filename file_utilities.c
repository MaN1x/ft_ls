/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 22:52:44 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/09 23:38:00 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_info  *file_new(void)
{
	t_file_info *file;

	if (!(file = (t_file_info*)malloc(sizeof(t_file_info))))
		exit (0);
	return (file);
}

void		file_add(t_file_info **file, t_file_info *new_file)
{
	if (*file == NULL)
		*file = new_file;
	else
		file_add(&(*file)->next, new_file);
}
