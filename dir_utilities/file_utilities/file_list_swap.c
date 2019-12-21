/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:39:28 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/21 22:39:28 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utilities.h"

void	file_list_swap(t_file_info **head, t_file_info *lst1, t_file_info *lst2)
{
	t_file_info *prev_list;

	if (*head != lst1)
	{
		prev_list = *head;
		while (prev_list->next != lst1)
			prev_list = prev_list->next;
		prev_list->next = lst2;
		lst1->next = lst2->next;
		lst2->next = lst1;
	}
	else
	{
		lst1->next = lst2->next;
		lst2->next = lst1;
		*head = lst2;
	}
}
