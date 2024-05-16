/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:45:33 by bsen              #+#    #+#             */
/*   Updated: 2024/01/05 20:00:11 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sum;
	int	sign;

	sign = 1;
	sum = 0;
	while ((*(char *)str <= 13 && *(char *)str >= 9) || *(char *)str == ' ')
		str++;
	if (*(char *)str == '+' || *(char *)str == '-')
	{
		if (*(char *)str == '-')
			sign = -1;
		str++;
	}
	while (*(char *)str >= '0' && *(char *)str <= '9')
	{
		sum = (*(char *)str - '0') + (sum * 10);
		str++;
	}
	return (sum * sign);
}
