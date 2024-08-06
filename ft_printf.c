/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:27:23 by vberdugo          #+#    #+#             */
/*   Updated: 2024/08/06 16:30:25 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(const char **format, va_list args)
{
	int		count;
	char	*str ;

	count = 0;
	(*format)++;
	if (**format == 'c')
		count += ft_putchar_fd((char)va_arg(args, int), 1);
	else if (**format == 'd')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (**format == 's')
	{
		str = va_arg(args, char *);
		ft_putstr_fd(str, 1);
		count += ft_strlen(str);
	}
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += handle_format(&format, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
