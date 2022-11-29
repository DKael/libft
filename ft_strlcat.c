/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:30:53 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:30:55 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
unsigned int	ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
int				ft_strlen(char *str);

unsigned int	ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
	int	dest_lenght;
	int	src_length;
	int	src_index;
	int	remain_size;
	int	signed_size;

	signed_size = (int)dstsize;
	dest_lenght = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (signed_size < 0)
		signed_size = dest_lenght + src_length + 1;
	remain_size = signed_size - dest_lenght - 1;
	src_index = 0;
	while (src_index < remain_size && src_index < src_length)
	{
		dst[dest_lenght + src_index] = src[src_index];
		src_index++;
	}
	dst[dest_lenght + src_index] = '\0';
	if (src_length + signed_size < src_length + dest_lenght)
		return (src_length + signed_size);
	else
		return (dest_lenght + src_length);
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}
