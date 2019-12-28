/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_date_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:25:48 by wanton            #+#    #+#             */
/*   Updated: 2019/12/28 15:06:17 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utilities.h"
#include "../../ft_ls.h"

static	void	add_arg(char r[15], char *arg)
{
	int	i;
	int a_i;
	int	tmp;

	i = 0;
	a_i = 0;
	tmp = ft_atoi(arg);
	while (r[i] != '\0')
		i++;
	if ((tmp / 10) == 0)
		r[i++] = '0';
	while (arg[a_i])
		r[i++] = arg[a_i++];
	r[i] = '\0';
}

unsigned long long	full_date(time_t time)
{
	struct tm	lt;
	char		result[15];
	char 		*tmp;

	result[0] = '\0';
	localtime_r(&time, &lt);
	tmp = ft_itoa(lt.tm_year + 1900);
	add_arg(result, tmp);
	free(tmp);
	tmp = ft_itoa(lt.tm_mon);
	add_arg(result, tmp);
	free(tmp);
	tmp = ft_itoa(lt.tm_mday);
	add_arg(result, tmp);
	free(tmp);
	tmp = ft_itoa(lt.tm_hour);
	add_arg(result, tmp);
	free(tmp);
	tmp = ft_itoa(lt.tm_min);
	add_arg(result, tmp);
	free(tmp);
	tmp = ft_itoa(lt.tm_sec);
	add_arg(result, tmp);
	free(tmp);
	return (ft_llatoi(result));
}