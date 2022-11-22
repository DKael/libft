/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:32:23 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:32:24 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str);

int	ft_atoi(const char *str)
{
	int	index;
	int	sign;
	int	number;

	index = 0;
	sign = 1;
	number = 0;
	while ((9 <= str[index] && str[index] <= 13) || str[index] == ' ')
		index++;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	while ('0' <= str[index] && str[index] <= '9')
		number = number * 10 + (str[index++] - '0');
	return (number * sign);
}
