/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:30:05 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:30:07 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len);

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*b_char;
	unsigned char	c_char;

	index = 0;
	b_char = (unsigned char *)b;
	c_char = (unsigned char)c;
	while (index < len)
	{
		b_char[index] = c_char;
		index++;
	}
	return (b);
}
