/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:49:35 by bsen              #+#    #+#             */
/*   Updated: 2023/12/22 15:25:23 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <malloc/_malloc.h>
#include <sys/_types/_null.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	total;

	total = count * size;
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, total);
	return (p);
}
