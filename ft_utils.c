/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creynalt <creynalt@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:15:09 by creynalt          #+#    #+#             */
/*   Updated: 2025/01/09 15:41:30 by creynalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_num_digits_in_base(unsigned	long long n, char *base)
{
	size_t				len;
	unsigned long long	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (n >= base_len)
	{
		n = n / base_len;
		len++;
	}
	return (len);
}

void	ft_putchar(char c, size_t *printed_chars_counter)
{
	write(1, &c, 1);
	(*printed_chars_counter)++;
}

void	ft_putstr(char	*c,	size_t	*printed_chars_counter)
{
	if (!c)
		c = "(null)";
	while (*c)
	{
		ft_putchar(*c, printed_chars_counter);
		c++;
	}
}

void	ft_putptr(void	*ptr,	size_t	*printed_chars_counter)
{
	char			*str;
	unsigned long	ptr_address;

	ptr_address = (unsigned long)ptr;
	ft_putstr("0x", printed_chars_counter);
	str = ft_convert_to_base(ptr_address, HEX_LOW_BASE);
	ft_putstr(str, printed_chars_counter);
	free(str);
}

void	ft_putnbr(int num, size_t *printed_chars_counter)
{
	if (num == -2147483648)
		write(1, "-2147483648", 11);
	else if (num < 0)
	{
		ft_putchar('-', printed_chars_counter);
		num = -num;
		ft_putnbr(num, printed_chars_counter);
	}
	else if (num > 9)
	{
		ft_putnbr((num / 10), printed_chars_counter);
		ft_putnbr((num % 10), printed_chars_counter);
	}
	else
		ft_putchar(num + 48, printed_chars_counter);
}
