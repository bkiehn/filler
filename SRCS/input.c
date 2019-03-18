/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:57:49 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/18 20:02:41 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			input_token(t_filler *param)
{
	if (param->enemy_kill == 0)
	{
		if (param->board_prev != 0)
			find_last_coordinates(param);
		else
			find_coordinates(param, 0, 0);
		if (hit_enemy(param, param->me_i - param->token_h,
		param->me_j - param->token_w) || find_way(param))
		{
			param->somewhere = 0;
			return (1);
		}
		else if (somewhere(param))
			return (1);
	}
	else if (somewhere(param))
		return (1);
	param->i = 0;
	param->j = 0;
	return (0);
}

int			somewhere(t_filler *param)
{
	int		i;
	int		j;

	param->somewhere = 1;
	i = 0;
	j = 0;
	while (param->board[i] != 0)
	{
		while (param->board[i][j] != 0)
		{
			if (chek_input_token(param, i, j))
			{
				param->i = i;
				param->j = j;
				return (1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int			chek_paste(t_filler *param, int i, int j, int tmpj)
{
	int		y;
	int		x;
	int		ov;

	y = 0;
	x = 0;
	ov = 0;
	while (param->token[y] != 0)
	{
		while (param->token[y][x] != 0)
		{
			if (param->token[y][x] == '*' && BOA == param->me)
				ov++;
			if ((param->token[y][x] == '*' && BOA == param->enemy)
			|| ov > 1 || (BOA != '.' && BOA != 'O' && BOA != 'X'))
				return (0);
			x++;
			j++;
		}
		y++;
		i++;
		x = 0;
		j = tmpj;
	}
	return (ov);
}

int			chek_input_token(t_filler *param, int i, int j)
{
	int		overlap;

	overlap = 0;
	if (i < 0 || j < 0)
		return (0);
	if ((param->board_w - j >= param->token_w) &&
	(param->board_h - i >= param->token_h))
		overlap = chek_paste(param, i, j, j);
	else
		return (0);
	if (overlap == 1)
		return (1);
	return (0);
}
