/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creynalt <creynalt@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:33:33 by creynalt          #+#    #+#             */
/*   Updated: 2025/01/09 13:07:28 by creynalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;

	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	ft_memset(tmp, 0, nmemb * size);
	return (tmp);
}
/*	Functions	to	HEX	*/

void	ft_puthex(unsigned int num, size_t *printed_chars_counter, char *base)
{
	char	*str;

	str = ft_convert_to_base(num, base);
	ft_putstr(str, printed_chars_counter);
	free(str);
}

char	*ft_convert_to_base(unsigned long long n, char	*base)
{
	char	*str;
	int		digits;
	int		base_len;

	digits = get_num_digits_in_base(n, base);
	base_len = ft_strlen(base);
	str = ft_calloc ((digits + 1), sizeof(char));
	if (!str)
		return (NULL);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	value;
	size_t			i;

	value = (unsigned char)c;
	dest = s;
	i = 0;
	while (i < n)
	{
		dest[i] = value;
		i++;
	}
	return (s);
}
