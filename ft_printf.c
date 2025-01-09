/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creynalt <creynalt@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:04:20 by creynalt          #+#    #+#             */
/*   Updated: 2025/01/09 13:36:44 by creynalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_selector(char *str, size_t *chars_counter, va_list vargs)
{
	if (*str == 'c')
		ft_putchar(va_arg(vargs, int), chars_counter);
	else if (*str == 's')
		ft_putstr(va_arg(vargs, char *), chars_counter);
	else if (*str == 'p')
		ft_putptr(va_arg(vargs, void *), chars_counter);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(vargs, int), chars_counter);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			ft_puthex(va_arg(vargs, unsigned int), chars_counter, HEX_LOW_BASE);
		else
			ft_puthex(va_arg(vargs, unsigned int), chars_counter, HEX_UPP_BASE);
	}
	else if (*str == '%')
		ft_putchar(*str, chars_counter);
}

int	ft_printf(char const *str, ...)
{
	va_list	vargs;
	size_t	chars_counter;

	chars_counter = 0;
	if (!str)
		return (0);
	va_start(vargs, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_selector((char *)str, &chars_counter, vargs);
		}
		else
			ft_putchar(*str, &chars_counter);
		str++;
	}
	va_end(vargs);
	return (chars_counter);
}
