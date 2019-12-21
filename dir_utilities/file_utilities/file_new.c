/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:38:00 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/21 21:38:00 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utilities.h"

t_file_info		*file_new(void)
{
	t_file_info *file;

	if (!(file = (t_file_info*)malloc(sizeof(t_file_info))))
		exit(0);
	file->file_name = NULL;
	file->next = NULL;
	file->gr_name = NULL;
	file->pw_name = NULL;
	file->st_mode = 0;
	return (file);
}
