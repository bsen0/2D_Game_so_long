/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:45:33 by bsen              #+#    #+#             */
/*   Updated: 2024/01/17 16:02:02 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(int a);
int	ft_string(char *s);
int	ft_unsignedint(unsigned int a);
int	ft_hexadec(unsigned long a, char format);
int	ft_upper_hexadec(unsigned int a);
int	ft_int(int number);
int	ft_printf(const char *s, ...);

#endif