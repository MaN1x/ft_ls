/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:38:29 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/21 21:38:29 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utilities.h"

void			file_add(t_file_info **file, t_file_info *new_file)
{
	if (*file == NULL)
		*file = new_file;
	else
		file_add(&((*file)->next), new_file);
}
