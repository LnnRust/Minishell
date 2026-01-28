/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:55:03 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/26 14:12:50 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <limits.h>

// @brief Sub-function of `ft_printf()`.
// Depending on what is present in the first argument, you must print the n'th
// argument properly.
//
// @param *chars_printed Pointer to the number of characters printed.
// Will be updated by the sub-functions.
// @param fixed_flags First argument of the `ft_printf()` function.
// @param args All the other arguments of `ft_printf()`, that will be processed
// here.
// @return Number of characters in `fixed_flags` that have been processed.
// Example : `%i` would return (2) as `%i` is a valid conversion.
// `%t` would return (1), as `t` is not a valid conversion. We return (1) so
// that the main function prints thereafter the character `t` and only steps
// one character in `args`. `ft_print_cases()` would then continue to process
// right after the character `t` if there are more args.
// @warning DOES NOT return the number of characters printed !
// This value is updated via the pointer `*chars_printed`.
// @note Can be upgraded to `ft_printf_fd()` by adding a `fd` argument.
int	ft_printf_cases(int *chars_printed, const char fixed_flags, va_list args)
{
	if (fixed_flags == 'c')
		*chars_printed += ft_putchar_fd(va_arg(args, int), 1);
	else if (fixed_flags == 's')
		*chars_printed += ft_putstr_fd(va_arg(args, char *), 1);
	else if (fixed_flags == 'p')
		*chars_printed += ft_putpointer(va_arg(args, void *), 1);
	else if (fixed_flags == 'd' || fixed_flags == 'i')
		*chars_printed += ft_putnbr_fd(va_arg(args, int), 1);
	else if (fixed_flags == 'u')
		*chars_printed += ft_putnbr_u_fd(va_arg(args, unsigned int), 1);
	else if (fixed_flags == 'x')
		*chars_printed += ft_puthexa_fd(va_arg(args, int), 1);
	else if (fixed_flags == 'X')
		*chars_printed += ft_puthexa_caps_fd(va_arg(args, int), 1);
	else if (fixed_flags == '%')
		*chars_printed += ft_putchar_fd('%', 1);
	else
		return (-1);
	return (2);
}

/// @brief A reproduction of the original `printf()` with no `malloc()`.
///
/// Supported conversions :
///
/// - `%c` Prints a single character.
///
/// - `%s` Prints a string (as defined by the common C convention).
///
/// - `%p` The void * pointer argument has to be printed in hexadecimal format.
///
/// - `%d` Prints a decimal (base 10) number.
///
/// - `%i` Prints an integer in base 10.
///
/// - `%u` Prints an unsigned decimal (base 10) number.
///
/// - `%x` Prints a number in hexadecimal (base 16) lowercase format.
///
/// - `%X` Prints a number in hexadecimal (base 16) uppercase format.
///
/// - `%%` Prints a percent sign.
///
/// External functions : `malloc()`, `free()`, `write()`,
/// `va_start()`, `va_arg()`, `va_copy()`, `va_end()`.
///
/// Mandatory includes : `<stdarg.h>`, `libft.h`.
///
/// @warning - No buffer management. Cannot check the number of `va_args`.
/// @warning - If `fixed_flags` contains too much data, behavior is undefined.
/// @warning - If `fixed_flags` conflicts with the data types in the next
/// arguments, behavior is undefined.
/// @attention You are reponsible for choosing the right conversion flags.
/// Unlike the original `printf()`, there are no checks at compile time.
/// @param fixed_flags A string composed of one or several flags
/// (see supported conversions) and/or printable characters.
/// @param (...) Any int, char, char* or void* that you want to write.
/// @return Number of bytes printed, no matter what happens.
int	ft_printf(const char *fixed_flags, ...)
{
	int		i;
	int		chars_printed;
	va_list	args;

	if (fixed_flags == NULL)
		return (-1);
	va_start(args, fixed_flags);
	i = 0;
	chars_printed = 0;
	while (fixed_flags[i] != '\0')
	{
		if (fixed_flags[i] == '%')
		{
			i += ft_printf_cases(&chars_printed, fixed_flags[i + 1], args);
		}
		else
		{
			chars_printed += ft_putchar_fd(fixed_flags[i], 1);
			i++;
		}
	}
	return (chars_printed);
}

// int	main(void)
// {
// 	//void	*BIG;
// 	//char	*huge;

// 	// ft_printf("%s%c%c%c%d%c%i%c", "bonjour", '\n', 'a', '\n', 1234567980,
// 	// '\n', 1234567980, '\n');
// 	//BIG = ft_calloc(8003, 1);
// 	//*(int *)BIG = 42;
// 	//huge = "I am the biggest thing you ever saw";
// 	// Hexadecimal test
// 	// ft_printf("%x", 255);
// 	// ft_printf("%c", '\n');
// 	// ft_printf("%%%e%s");
// 	// ft_printf("%s%s%s%s%s");
// 	// ft_printf("%s%c",
// 	// printf("%i", 1821821);
// 	//
// 	// printf("%d %d\n", printf("%p %p %u %s cccaca %x %X\n", NULL, BIG,
// 	// 		*(int *)BIG, huge, *(int *)BIG, *(int *)BIG),
// 	// 	ft_printf("%p %p %u %s cccaca %x %X\n", NULL, BIG, *(int *)BIG,
// 	// 		huge, *(int *)BIG, *(int *)BIG));
// 	//
// 	//
// 	//ft_printf("%i", ' ');
// 	printf("Number of chars from ft_printf : %i\n", ft_printf("%i", -1));
// 	return (0);
// }
