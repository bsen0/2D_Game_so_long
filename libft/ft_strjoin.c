/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:55:02 by bsen              #+#    #+#             */
/*   Updated: 2023/12/22 15:26:04 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <malloc/_malloc.h>
#include <sys/_types/_null.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*p;
	int		i;

	len = ft_strlen(s1);
	len += ft_strlen(s2);
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (s1[i])
	{
		p[len++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		p[len++] = s2[i++];
	}
	p[len] = '\0';
	return (p);
}
