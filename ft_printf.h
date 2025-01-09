/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creynalt <creynalt@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:47:14 by creynalt          #+#    #+#             */
/*   Updated: 2025/01/09 13:32:14 by creynalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

/* For mapping Hex values */
# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(char const *str, ...);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	get_num_digits_in_base(unsigned long long n, char *base);
void	ft_putchar(char c, size_t *printed_chars_counter);
void	ft_putstr(char *c, size_t *printed_chars_counter);
void	ft_putptr(void *ptr, size_t *printed_chars_counter);
void	ft_putnbr(int num, size_t *printed_chars_counter);
void	ft_puthex(unsigned int num, size_t *printed_chars_counter, char *base);
char	*ft_convert_to_base(unsigned long long n, char *base);
void	*ft_memset(void *s, int c, size_t n);

#endif
