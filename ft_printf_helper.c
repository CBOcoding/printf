/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:22:35 by cborrome          #+#    #+#             */
/*   Updated: 2024/11/18 15:35:44 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(int c)
{
	write (1, &c, 1);
	return (1);
}

int	print_string(char *str)
{
	int	count;

	if (str == NULL)
	{
		str = "(null)";
	}
	count = 0;
	while (*str != '\0')
	{
		print_character((int)*str);
		++count;
		++str;
	}
	return (count);
}

int	print_digit(long long digit, int base, char dxX)
{
	int			count;
	const char	*available_output_lower = "0123456789abcdef";
	const char	*available_output_upper = "0123456789ABCDEF";

	if (digit < 0)
	{
		write (1, "-", 1);
		return (print_digit(-digit, base, dxX) + 1);
	}
	else if ((digit < base) && (dxX == 'x' || dxX == 'd'))
		return (print_character (available_output_lower[digit]));
	else if ((digit < base) && (dxX == 'X'))
		return (print_character (available_output_upper[digit]));
	else
	{
		count = print_digit(digit / base, base, dxX);
		return (count + print_digit (digit % base, base, dxX));
	}
}

int	print_digit_pointer(uintptr_t digit, uintptr_t base)
{
	int			count;
	const char	*available_output_lower = "0123456789abcdef";

	if ((digit < base))
		return (print_character (available_output_lower[digit]));
	else
	{
		count = print_digit_pointer(digit / base, base);
		return (count + print_digit_pointer (digit % base, base));
	}
}

int	print_pointer(uintptr_t pointer)
{
	int		count;

	if (pointer == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	count = 2;
	count += print_digit_pointer(pointer, 16);
	return (count);
}
