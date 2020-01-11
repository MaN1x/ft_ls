/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:48:49 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/11 21:16:31 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scan_utilities.h"

extern t_sort_type	g_sort_type;

void	scan(t_list *path_list)
{
	t_dir	*dir;

	dir = NULL;
	while (path_list)
	{
		dir_add(&dir, path_list->content);
		scan_directory(dir);
		free_dirlist(&dir);
	//	dir = NULL;	//удали эту строчку и проверь на утечки. Почему так работает? P.S. Проверяй с несколькими аргументами
	//				UPD Кажется я понял, С - это и правда 2 в 16 способов отстрелить себе конечности.
		path_list = path_list->next;
	}
}
