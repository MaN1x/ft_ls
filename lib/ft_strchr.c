/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:17:33 by mjoss             #+#    #+#             */
/*   Updated: 2020/01/16 10:40:36 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*((unsigned char*)s) != (unsigned char)c && *s)
		s++;
	if (*s == '\0' && (unsigned char)c != '\0')
		return (0);
	return ((char*)s);
}
