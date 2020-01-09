/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link_parent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 14:52:44 by wanton            #+#    #+#             */
/*   Updated: 2020/01/09 10:27:30 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void	print_link_parent(char *path, mode_t st_mode)
{
	char		buf[BUF_SIZE];

	if (S_ISLNK(st_mode))
	{
		ft_strclr(buf);
		readlink(path, buf, BUF_SIZE);
		ft_putstr(" -> ");
		ft_putstr(buf);
	}

}
