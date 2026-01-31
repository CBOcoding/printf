/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:18:14 by cborrome          #+#    #+#             */
/*   Updated: 2024/11/18 15:34:40 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	print_format(char conversion_specifier, va_list ap);
int	print_character(int c);
int	print_string(char *str);
int	print_digit(long long digit, int base, char dxX);
int	print_digit_pointer(uintptr_t digit, uintptr_t base);
int	print_pointer(uintptr_t pointer);

#endif
