/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link_parent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 14:52:44 by wanton            #+#    #+#             */
/*   Updated: 2020/01/15 17:07:26 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_link_parent(char *path, mode_t st_mode)
{
	char		buf[BUF_SIZE + 1];
	int			p;

	if (S_ISLNK(st_mode))
	{
		p = readlink(path, buf, BUF_SIZE);
		buf[p] = '\0';
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
	if (path)
		free(path);
}

void	get_file_acl(char *path)
{
	acl_t	tmp;
	char	buf[101];

	if (listxattr(path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	else if ((tmp = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		ft_putchar('+');
	}
	else
		ft_putchar(' ');
	if (path)
		free(path);
	ft_putchar(' ');
}
