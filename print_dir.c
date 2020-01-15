/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:04:01 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/15 15:15:02 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_print_format	g_print_format;
extern t_scan_type		g_scan_type;
extern t_scan_mode		g_scan_mode;
extern t_sort_type		g_sort_type;
extern t_sort_mode		g_sort_mode;
extern t_line_break		g_line_break;
extern t_file_perm		g_file_perm;

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

static void	print_rights(mode_t st_mode)
{
	if (S_ISREG(st_mode))
		ft_putchar('-');
	if (S_ISLNK(st_mode))
		ft_putchar('l');
	if (S_ISDIR(st_mode))
		ft_putchar('d');
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
			{
				ft_putstr(p->file_name);
				ft_putspace((int)(maxlen - ft_strlen(p->file_name)));
				num = num + kkk;
			}
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

	tmp = dir->file;
	print_head(dir);
	print_total(tmp);
	while (tmp)
	{
		print_rights(tmp->st_mode);
		get_file_acl(get_full_path(dir->dir_name, tmp->file_name));
		ft_putchar(' ');
		print_pw_size(tmp, max_len_pw_nb(tmp));
		ft_putstr(tmp->pw_name);
		ft_putchar('\t');
		ft_putstr(tmp->gr_name);
		ft_putstr("  ");
		print_st_size(tmp, max_len_st_nb(tmp));
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
	t_file_info	*tmp;
	char		*name;
	int			col;

	if (g_print_format == SHORT_FORMAT)
	{
		while (dir)
		{
			if (g_line_break == NEXT_ELEM)
				ft_putchar('\n');
			col = 0;
			g_line_break = NEXT_ELEM;
			tmp = dir->file;
			print_head(dir);
			print_list(tmp, (find_maxlen(tmp) + 4), file_size(tmp), col);
			if (g_file_perm == DISALLOW)
			{
				ft_putstr_fd("ls: ", 2);
				if (!(name = ft_strrchr(dir->dir_name, '/')))
					name = dir->dir_name;
				ft_putstr_fd(++name, 2);
				ft_putstr_fd(": Permission denied\n", 2);
				g_file_perm = ALLOW;
			}
			dir = dir->next;
		}
	}
	else if (g_print_format == LONG_FORMAT)
	{
		while (dir)
		{
			if (g_line_break == NEXT_ELEM)
				ft_putchar('\n');
			g_line_break = NEXT_ELEM;
			print_long_list(dir);
			dir = dir->next;
		}
	}
}
