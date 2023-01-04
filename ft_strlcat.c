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

static size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dest_lenght;
	size_t	src_length;
	size_t	src_index;

	dest_lenght = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dsize < dest_lenght + 1)
		return (dsize + src_length);
	else
	{
		src_index = 0;
		while (src_index + dest_lenght + 1 < dsize && src[src_index] != '\0')
		{
			dst[dest_lenght + src_index] = src[src_index];
			src_index++;
		}
		dst[dest_lenght + src_index] = '\0';
		return (dest_lenght + src_length);
	}
}

static size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}
