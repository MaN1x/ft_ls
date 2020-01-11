/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:04:01 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/11 21:28:44 by mjoss            ###   ########.fr       */
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
{									// maxlen - длина самого длинного слова
	t_file_info		*p;			   // l - кол-во элементов для печати
	struct winsize	w;
	int				i;
	int				kkk;
	int				num;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); // оперделяю размеры окна терминала (данные в w)
	col = w.ws_col / maxlen + (w.ws_col / maxlen == 0 ? 1 : 0); // расчитываю кол-во колонок для печати
	l = l / col + (l % col == 0 ? 0 : 1); // кол-во строк
	kkk = l; // нужно будет избавиться
	num = 0;
	while (l-- != 0)
	{
		i = 0;
		while (i++ < col)
		{
			if ((p = ft_take_elem(tmp, num))) // возвращает элемента номера num
			{
				ft_putstr(p->file_name);
				ft_putspace((int)(maxlen - ft_strlen(p->file_name))); //заполняет оставшееся место пробелами
				num = num + kkk;
			}
			else
				break ;
		}
		num = (num - (kkk * --i)) + 1;
		ft_putchar('\n');
	}
}

// TODO: сделать отступы между директориями
void		print_long_list(t_dir *dir)
{
	t_file_info	*tmp;
	int 		m1;
	int 		m2;

	tmp = dir->file;
	m1 = max_len_pw_nb(tmp);
	m2 = max_len_st_nb(tmp);
	print_head(dir);
	print_total(tmp);
	while (tmp)
	{
		print_rights(tmp->st_mode);
		get_file_acl(get_full_path(dir->dir_name, tmp->file_name));
		ft_putchar(' ');
		print_pw_size(tmp, m1);
		ft_putstr(tmp->pw_name);
		ft_putchar('\t');
		ft_putstr(tmp->gr_name);
		ft_putstr("  ");
		print_st_size(tmp, m2);
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
	int		col; // переменная для print_list

	if (g_print_format == SHORT_FORMAT)
	{
		while (dir)
		{
			col = 0;
			tmp = dir->file;
			print_head(dir);
			print_list(tmp, (find_maxlen(tmp) + 4), file_size(tmp), col);
			if (dir->next)
				ft_putchar('\n');
			dir = dir->next;
		}
	}
	else if (g_print_format == LONG_FORMAT)
	{
		while (dir)
		{
			print_long_list(dir);
			if (dir->next)
				printf("\n");
			dir = dir->next;
		}
	}
}
