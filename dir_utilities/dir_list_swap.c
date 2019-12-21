/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_list_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:20:45 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/21 22:20:45 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dir_utilities.h"

void	dir_list_swap(t_dir **head, t_dir *lst1, t_dir *lst2)
{
	t_dir *prev_list;

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
