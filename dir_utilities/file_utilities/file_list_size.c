/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:37:38 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/21 22:37:38 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utilities.h"

size_t	file_list_size(t_file_info *lst)
{
	size_t count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
