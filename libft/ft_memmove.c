/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:03:06 by bsen              #+#    #+#             */
/*   Updated: 2024/01/08 18:53:15 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_size_t.h>
#include <sys/_types/_null.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s = src;
	char		*ld;
	const char	*ls = &s[len - 1];

	d = dst;
	if (!dst && !src)
		return (NULL);
	if (d < s)
	{
		while (len-- > 0)
		{
			*d++ = *s++;
		}
	}
	else
	{
		ld = &d[len - 1];
		while (len-- > 0)
		{
			*ld-- = *ls--;
		}
	}
	return ((void *)dst);
}
