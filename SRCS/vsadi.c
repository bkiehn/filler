/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsadi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 21:39:35 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/18 15:18:28 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		vsadi_way_1(t_filler *param)
{
	int	x;
	int	y;

	x = param->board_w;
	y = param->board_h;
	while (y >= param->me_i - param->token_h)
	{
		while (x >= param->me_j - param->token_w)
		{
			if (chek_input_token(param, y, x))
			{
				param->i = y;
				param->j = x;
				return (1);
			}
			x--;
		}
		x = param->board_w;
		y--;
	}
	return (0);
}

int		vsadi_way_2(t_filler *param)
{
	int	x;
	int	y;

	x = param->board_w;
	y = param->board_h;
	while (y >= param->me_i - param->token_h)
	{
		while (x <= param->me_j + param->token_w && x < param->board_w)
		{
			if (chek_input_token(param, y, x))
			{
				param->i = y;
				param->j = x;
				return (1);
			}
			x++;
		}
		x = param->board_w;
		y--;
	}
	return (0);
}

int		vsadi_way_3(t_filler *param)
{
	int	x;
	int	y;

	x = param->board_w;
	y = param->board_h;
	while (y <= param->me_i + param->token_h && y < param->board_h)
	{
		while (x <= param->me_j + param->token_w && x < param->board_w)
		{
			if (chek_input_token(param, y, x))
			{
				param->i = y;
				param->j = x;
				return (1);
			}
			x++;
		}
		x = param->board_w;
		y++;
	}
	return (0);
}

int		vsadi_way_4(t_filler *param)
{
	int	x;
	int	y;

	x = param->board_w;
	y = param->board_h;
	while (y <= param->me_i + param->token_h && y < param->board_h)
	{
		while (x >= param->me_j - param->token_w)
		{
			if (chek_input_token(param, y, x))
			{
				param->i = y;
				param->j = x;
				return (1);
			}
			x--;
		}
		x = param->board_w;
		y++;
	}
	return (0);
}
