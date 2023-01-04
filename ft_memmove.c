/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:30:35 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:30:36 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;
	char	*dst_cptr;
	char	*src_cptr;

	index = -1;
	dst_cptr = (char *)dst;
	src_cptr = (char *)src;
	if (dst != 0 || src != 0)
	{
		if ((long)src - (long)dst > 0)
		{
			while (++index < len)
				dst_cptr[index] = src_cptr[index];
		}
		else
		{
			while (++index < len)
				dst_cptr[len - index - 1] = src_cptr[len - index - 1];
		}
	}
	return (dst);
}
