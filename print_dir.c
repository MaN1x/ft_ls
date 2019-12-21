/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:04:01 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/21 18:28:34 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_print_format	g_print_format;
extern t_scan_type		g_scan_type;
extern t_scan_mode		g_scan_mode;
extern t_sort_type		g_sort_type;
extern t_sort_mode		g_sort_mode;

static void	print_rights(mode_t st_mode)
{
	if (S_ISREG(st_mode))
		printf("-");
	if (S_ISLNK(st_mode))
		printf("l");
	if (S_ISDIR(st_mode))
		printf("d");
	if (st_mode & S_IRWXU & S_IRUSR)
		printf("r");
	else
		printf("-");
	if (st_mode & S_IRWXU & S_IWUSR)
		printf("w");
	else
		printf("-");
	if (st_mode & S_IRWXU & S_IXUSR)
		printf("x");
	else
		printf("-");
	if (st_mode & S_IRWXG & S_IRGRP)
		printf("r");
	else
		printf("-");
	if (st_mode & S_IRWXG & S_IWGRP)
		printf("w");
	else
		printf("-");
	if (st_mode & S_IRWXG & S_IXGRP)
		printf("x");
	else
		printf("-");
	if (st_mode & S_IRWXO & S_IROTH)
		printf("r");
	else
		printf("-");
	if (st_mode & S_IRWXO & S_IWOTH)
		printf("w");
	else
		printf("-");
	if (st_mode & S_IRWXO & S_IXOTH)
		printf("x");
	else
		printf("-");
}

void	print_dir(t_dir *dir)
{
	t_file_info	*tmp;

	if (g_print_format == SHORT_FORMAT)
	{
		while (dir)
		{
			tmp = dir->file;
			printf("%s:\n", dir->dir_name);
			while (tmp)
			{
				printf("%s\n", tmp->file_name);
				tmp = tmp->next;
			}
			printf("\n");
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
				printf("*owner*\t");
				printf("*group*\t");
				printf("*size*\t");
				printf("*date*\t");
				printf("%s\n", tmp->file_name);
				tmp = tmp->next;
			}
			printf("\n");
			dir = dir->next;
		}
	}
}