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

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int	str_index;
	int	find_index;

	if (to_find[0] == '\0')
		return (str);
	str_index = 0;
	while (str[str_index] != '\0')
	{
		if (str[str_index] == to_find[0])
		{
			find_index = 1;
			while (to_find[find_index] != '\0')
			{
				if (str[str_index + find_index] != to_find[find_index])
					break ;
				find_index++;
			}
			if (to_find[find_index] == '\0')
				return (&str[str_index]);
		}
		str_index++;
	}
	return (0);
}
