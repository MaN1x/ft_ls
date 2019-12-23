/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:38:42 by wanton            #+#    #+#             */
/*   Updated: 2019/12/23 14:38:42 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utilities.h"

size_t	file_size(t_file_info *lst)
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