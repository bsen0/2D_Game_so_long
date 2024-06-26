/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:06:19 by bsen              #+#    #+#             */
/*   Updated: 2023/12/15 16:30:34 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*d;

	i = 0;
	a = c;
	d = (char *)s;
	while (d[i] && d[i] != a)
		i++;
	if (d[i] == a)
		return (d + i);
	return (0);
}
