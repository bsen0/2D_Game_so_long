/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:15:55 by bsen              #+#    #+#             */
/*   Updated: 2024/01/19 13:44:59 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(int a)
{
	return (write(1, &a, 1));
}

static int	ft_check(char b)
{
	return (b == 'c' || b == 's' || b == 'p' || b == 'd' || b == 'i' || b == 'u'
		|| b == 'x' || b == 'X' || b == '%');
}

static int	ft_format(va_list arg, char a)
{
	if (a == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (a == 's')
		return (ft_string(va_arg(arg, char *)));
	else if (a == 'd' || a == 'i')
		return (ft_int(va_arg(arg, int)));
	else if (a == 'u')
		return (ft_unsignedint(va_arg(arg, unsigned int)));
	else if (a == 'x')
		return (ft_hexadec(va_arg(arg, unsigned int), a));
	else if (a == 'p')
		return (ft_hexadec(va_arg(arg, unsigned long), a));
	else if (a == 'X')
		return (ft_upper_hexadec(va_arg(arg, unsigned int)));
	else if (a == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		temp;
	int		len;

	len = 0;
	va_start(arg, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%' && ft_check(s[i + 1]))
		{
			i++;
			temp = ft_format(arg, s[i]);
			if (temp == -1)
				return (-1);
			len += temp;
		}
		else if (s[i] != '%' && ft_putchar(s[i]) == -1)
			return (-1);
		else if (s[i] != '%')
			len++;
	}
	va_end(arg);
	return (len);
}
