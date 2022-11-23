/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:25:48 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/23 15:25:50 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	idx;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	idx = 0;
	while (idx < len && s[(size_t)start + idx] != '\0')
	{
		result[idx] = s[(size_t)start + idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
