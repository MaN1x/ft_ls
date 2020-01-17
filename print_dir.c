/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:04:01 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/17 10:50:07 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_print_format	g_print_format;
extern t_scan_type		g_scan_type;
extern t_scan_mode		g_scan_mode;
extern t_sort_type		g_sort_type;
extern t_sort_mode		g_sort_mode;

static void	print_rights2(mode_t st_mode)
{
	if (st_mode & S_IRWXG & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (st_mode & S_IRWXG & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
	if (st_mode & S_IRWXO & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (st_mode & S_IRWXO & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (st_mode & S_IRWXO & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void		print_rights(mode_t st_mode)
{
	if (st_mode & S_IRWXU & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (st_mode & S_IRWXU & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (st_mode & S_IRWXU & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
	if (st_mode & S_IRWXG & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	print_rights2(st_mode);
}

void		print_list(t_file_info *tmp, int maxlen, int l, int col)
{
	t_file_info		*p;
	struct winsize	w;
	int				i;
	int				kkk;
	int				num;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	col = w.ws_col / maxlen + (w.ws_col / maxlen == 0 ? 1 : 0);
	l = l / col + (l % col == 0 ? 0 : 1);
	kkk = l;
	num = 0;
	while (l-- != 0)
	{
		i = 0;
		while (i++ < col)
		{
			if ((p = ft_take_elem(tmp, num)))
				num = num + help_print_list(p->file_name, maxlen, kkk);
			else
				break ;
		}
		num = (num - (kkk * --i)) + 1;
		ft_putchar('\n');
	}
}

void		print_long_list(t_dir *dir)
{
	t_file_info	*tmp;
	int			m[6];

	tmp = dir->file;
	take_size_const(m, tmp);
	print_head(dir);
	print_total(tmp);
	while (tmp)
	{
		print_file_type(tmp->st_mode);
		get_file_acl(get_full_path(dir->dir_name, tmp->file_name));
		print_pw_size(tmp, m[0]);
		print_name(tmp, m[2]);
		print_name_gr(tmp, m[3]);
		print_st_size(tmp, m[1], m[4], m[5]);
		print_time(tmp);
		ft_putstr(tmp->file_name);
		print_link_parent(get_full_path(dir->dir_name,
				tmp->file_name), tmp->st_mode);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void		print_dir(t_dir *dir)
{
	if (g_print_format == SHORT_FORMAT)
		short_format(dir);
	else if (g_print_format == LONG_FORMAT)
		long_format(dir);
}
