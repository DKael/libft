/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:30:43 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:30:44 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	index;
	size_t	index1;

	index = 0;
	index1 = 0;
	while (src[index] != '\0')
		index++;
	if (index >= dstsize)
	{
		while (index1 + 1 < dstsize)
		{
			dst[index1] = src[index1];
			index1++;
		}
	}
	else
	{
		while (src[index1] != '\0')
		{
			dst[index1] = src[index1];
			index1++;
		}
	}
	dst[index1] = '\0';
	return (index);
}
