/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:22:35 by cborrome          #+#    #+#             */
/*   Updated: 2024/11/18 15:26:28 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char conversion_specifier, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

int	print_format(char conversion_specifier, va_list ap)
{
	int	count;

	count = 0;
	if (conversion_specifier == 'c')
		count += print_character(va_arg(ap, int));
	else if (conversion_specifier == 's')
		count += print_string(va_arg(ap, char *));
	else if (conversion_specifier == 'd')
		count += print_digit((long long)(va_arg(ap, int)), 10, 'd');
	else if (conversion_specifier == 'x')
		count += print_digit((long long)(va_arg(ap, unsigned int)), 16, 'x');
	else if (conversion_specifier == 'X')
		count += print_digit((long long)(va_arg(ap, unsigned int)), 16, 'X');
	else if (conversion_specifier == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10, 'd');
	else if (conversion_specifier == 'u')
		count += print_digit((long)(va_arg(ap, unsigned int)), 10, 'd');
	else if (conversion_specifier == 'p')
		count += print_pointer((uintptr_t)(va_arg(ap, uintptr_t)));
	else
		count += write(1, &conversion_specifier, 1);
	return (count);
}
