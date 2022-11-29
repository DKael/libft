/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:26:25 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/28 17:26:26 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd);
void	case_pos(int n, int digit, int fd);
void	case_neg(int n, int digit, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	int		digit;
	int		temp_n;

	temp_n = n;
	digit = 0;
	while (temp_n != 0)
	{
		digit++;
		temp_n /= 10;
	}
	if (n == 0)
		write(fd, "0", sizeof(char));
	else if (n > 0)
		case_pos(n, digit, fd);
	else
		case_neg(n, digit, fd);
}

void	case_pos(int n, int digit, int fd)
{
	char	result[20];

	while (n != 0)
	{
		result[digit--] = (n % 10) + '0';
		n /= 10;
	}
	write(fd, result, sizeof(char) * digit);
}

void	case_neg(int n, int digit, int fd)
{
	char	result[20];

	while (n != 0)
	{
		result[digit--] = (-1) * (n % 10) + '0';
		n /= 10;
	}
	write(fd, result, sizeof(char) * (digit + 1));
}