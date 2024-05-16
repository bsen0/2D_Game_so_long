/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:37:32 by bsen              #+#    #+#             */
/*   Updated: 2023/12/22 15:19:51 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc/_malloc.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	dest = malloc(i + 1);
	if (!dest)
		return (0);
	while (i-- >= 0)
	{
		dest[i + 1] = (char)s1[i + 1];
	}
	return (dest);
}
