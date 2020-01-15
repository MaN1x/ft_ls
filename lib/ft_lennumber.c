/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lennumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:33:38 by wanton            #+#    #+#             */
/*   Updated: 2020/01/13 10:18:02 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lennumber(int nb)
{
	int count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}
