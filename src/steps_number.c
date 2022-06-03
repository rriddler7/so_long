/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:41:19 by rriddler          #+#    #+#             */
/*   Updated: 2022/01/08 14:41:23 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	digits_number(int number)
{
	int	size;

	size = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		size++;
		number /= 10;
	}
	return (size);
}

static char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * (digits_number(n) + (n < 0) + 1));
	if (str == NULL)
		return (NULL);
	i = digits_number(n) + (n < 0);
	str[i] = '\0';
	i--;
	if (n < 0)
		str[0] = '-';
	if (n < 0)
		n = -n;
	str[i] = '0';
	while (n && str[i] != '-')
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}

void	steps_number(t_solong *game)
{
	char	*tmp;
	char	*str;

	tmp = ft_itoa(game->steps);
	str = ft_strjoin("Number of steps: ", tmp);
	free(tmp);
	mlx_string_put(game->mlx, game->window, 2,
		game->size_y * IMG_SIZE, 800080, str);
	free(str);
}
