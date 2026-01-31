/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:00:00 by cborrome          #+#    #+#             */
/*   Updated: 2026/01/31 00:00:00 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		return1, return2;
	char	*str = "Hello, World!";
	int		num = 42;
	void	*ptr = &num;

	ft_printf("\n=== TEST FT_PRINTF ===\n\n");

	// Test Character
	ft_printf("--- Test Character (%%c) ---\n");
	return1 = ft_printf("ft_printf: %c\n", 'A');
	return2 = printf("   printf: %c\n", 'A');
	ft_printf("Return values: ft=%d, std=%d\n\n", return1, return2);

	// Test String
	ft_printf("--- Test String (%%s) ---\n");
	return1 = ft_printf("ft_printf: %s\n", str);
	return2 = printf("   printf: %s\n", str);
	ft_printf("Return values: ft=%d, std=%d\n\n", return1, return2);

	// Test String NULL
	ft_printf("--- Test String NULL ---\n");
	return1 = ft_printf("ft_printf: %s\n", (char *)NULL);
	return2 = printf("   printf: %s\n", (char *)NULL);
	ft_printf("Return values: ft=%d, std=%d\n\n", return1, return2);

	// Test Pointer
	ft_printf("--- Test Pointer (%%p) ---\n");
	return1 = ft_printf("ft_printf: %p\n", ptr);
	return2 = printf("   printf: %p\n", ptr);
	ft_printf("Return values: ft=%d, std=%d\n\n", return1, return2);

	// Test Decimal
	ft_printf("--- Test Decimal (%%d) ---\n");
	return1 = ft_printf("ft_printf: %d\n", num);
	return2 = printf("   printf: %d\n", num);
	ft_printf("Return values: ft=%d, std=%d\n\n", return1, return2);

	// Test Integer
	ft_printf("--- Test Integer (%%i) ---\n");
	return1 = ft_printf("ft_printf: %i\n", -42);
	return2 = printf("   printf: %i\n", -42);
	ft_printf("Return values: ft=%d, std=%d\n\n", return1, return2);

	// Test unsigned
	ft_printf("--- Test unsigned (%%u) ---\n");
	return1 = ft_printf("ft_printf: %u\n", 4294967295u);
	return2 = printf("   printf: %u\n", 4294967295u);
	ft_printf("Return values: ft=%d, std=%d\n\n", return1, return2);

	// Test hex Lower
	ft_printf("--- Test hex Lower (%%x) ---\n");
	return1 = ft_printf("ft_printf: %x\n", 255);
	return2 = printf("   printf: %x\n", 255);
	ft_printf("Return values: ft=%d, std=%d\n\n", return1, return2);

	// Test hex Upper
	ft_printf("--- Test hex Upper (%%X) ---\n");
	return1 = ft_printf("ft_printf: %X\n", 255);
	return2 = printf("   printf: %X\n", 255);
	ft_printf("Return values: ft=%d, std=%d\n\n", return1, return2);

	// Test Percentage
	ft_printf("--- Test Percentage (%%%%) ---\n");
	return1 = ft_printf("ft_printf: %%\n");
	return2 = printf("   printf: %%\n");
	ft_printf("Return values: ft=%d, std=%d\n\n", return1, return2);

	// Test Multiple
	ft_printf("--- Test Multiple ---\n");
	return1 = ft_printf("ft_printf: %s ha %d anni e vive a 0x%x\n", "Mario", 25, 0xCAFE);
	return2 = printf("   printf: %s ha %d anni e vive a 0x%x\n", "Mario", 25, 0xCAFE);
	ft_printf("Return values: ft=%d, std=%d\n\n", return1, return2);

	return (0);
}
