/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:32:12 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:32:13 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_idx;
	size_t	needle_idx;

	if (needle[0] == '\0')
		return ((char *)haystack);
	haystack_idx = 0;
	while (haystack[haystack_idx] != '\0' && haystack_idx < len)
	{
		if (haystack[haystack_idx] == needle[0])
		{
			needle_idx = 1;
			while (needle[needle_idx] != '\0')
			{
				if (haystack[haystack_idx + needle_idx] != needle[needle_idx]
					|| !(haystack_idx + needle_idx < len))
					break ;
				needle_idx++;
			}
			if (needle[needle_idx] == '\0')
				return ((char *)&haystack[haystack_idx]);
		}
		haystack_idx++;
	}
	return (0);
}
