/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:12:56 by bsen              #+#    #+#             */
/*   Updated: 2024/01/08 19:36:41 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_size_t.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (needle[i] == '\0')
		return ((char *)&haystack[i]);
	while (haystack[i] != '\0' && i < len)
	{
		y = 0;
		if (haystack[i] == needle[y])
		{
			while (haystack[i + y] && needle[y] && i + y < len
				&& haystack[i + y] == needle[y])
			{
				y++;
				if (!needle[y])
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (0);
}
