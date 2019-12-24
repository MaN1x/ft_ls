/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:04:01 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/24 11:26:28 by wanton           ###   ########.fr       */
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

void		print_dir(t_dir *dir)
{
	t_file_info	*tmp;
	int 		col; // переменная для print_list

	if (g_print_format == SHORT_FORMAT)
	{
		while (dir)
		{
			col = 0;
			tmp = dir->file;
			print_list(tmp, (find_maxlen(tmp) + 4), file_size(tmp), col);
			dir = dir->next;
		}
	}
	else if (g_print_format == LONG_FORMAT)
	{
		while (dir)
		{
			tmp = dir->file;
			printf("%s:\n", dir->dir_name);
			while (tmp)
			{
				print_rights(tmp->st_mode);
				printf("\t%d\t", tmp->st_nlink);
				printf("%s\t", tmp->pw_name);
				printf("%s\t", tmp->gr_name);
				printf("%d\t", (unsigned int)tmp->st_size);
				printf("%s\t", ctime(&tmp->time));
				printf("%s\n", tmp->file_name);
				tmp = tmp->next;
			}
			printf("\n");
			dir = dir->next;
		}
	}
}
