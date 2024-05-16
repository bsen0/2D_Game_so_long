/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:40:10 by bsen              #+#    #+#             */
/*   Updated: 2024/01/19 13:45:01 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_int(int number)
{
	int	len;
	int	value;

	len = 0;
	if (number == 0)
		return (ft_putchar('0'));
	if (number == -2147483648)
		return (ft_string("-2147483648"));
	if (number < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		number *= -1;
		len++;
	}
	if (number > 9)
	{
		value = ft_int(number / 10);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (ft_putchar("0123456789"[number % 10]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_string(char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
	{
		if (ft_string("(null)") == -1)
			return (-1);
		return (6);
	}
	while (s[++i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
	}
	return (i);
}

int	ft_unsignedint(unsigned int a)
{
	int	len;
	int	value;

	len = 0;
	if (a > 9)
	{
		value = ft_unsignedint(a / 10);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (ft_putchar("0123456789"[a % 10]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_hexadec(unsigned long a, char format)
{
	int	len;
	int	temp;

	len = 0;
	if (format == 'p')
	{
		if (ft_string("0x") == -1)
			return (-1);
		len += 2;
	}
	if (a >= 16)
	{
		temp = ft_hexadec(a / 16, 'x');
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (ft_putchar("0123456789abcdef"[a % 16]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_upper_hexadec(unsigned int a)
{
	int	len;

	len = 0;
	if (a > 15)
	{
		len = ft_upper_hexadec(a / 16);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar("0123456789ABCDEF"[a % 16]) == -1)
		return (-1);
	return (len + 1);
}
