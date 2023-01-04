/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:31:32 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:31:33 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strrchr(const char *s, int c)
{
	int		index;
	int		find;

	index = 0;
	find = -1;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
			find = index;
		index++;
	}
	if (find != -1)
		return ((char *)s + find);
	if ((char)c == '\0')
		return ((char *)s + index);
	return (0);
}
