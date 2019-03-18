/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:09:45 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/18 20:02:26 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_last_coordinates(t_filler *param)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (param->board[y] != 0)
	{
		while (param->board[y][x] != 0)
		{
			if (param->board[y][x] == param->enemy &&
			(param->board[y][x] != param->board_prev[y][x]))
			{
				param->enemy_i = y;
				param->enemy_j = x;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	param->enemy_kill = 1;
}

void	find_coordinates(t_filler *param, int x, int y)
{
	int	f;

	f = 0;
	while (param->board[y] != 0 && f < 2)
	{
		while (param->board[y][x] != 0)
		{
			if (f < 2 && param->board[y][x] == param->me)
			{
				param->me_i = y;
				param->me_j = x;
				f++;
			}
			if (f < 2 && param->board[y][x] == param->enemy)
			{
				param->enemy_i = y;
				param->enemy_j = x;
				f++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int		find_way(t_filler *param)
{
	int	difx;
	int	dify;

	difx = param->enemy_j - param->me_j;
	dify = param->enemy_i - param->me_i;
	if (difx >= 0 && dify >= 0)
		if (vsadi_way_1(param) || vsadi_way_2(param))
			return (1);
	if (difx < 0 && dify >= 0)
		if (vsadi_way_2(param) || vsadi_way_3(param))
			return (1);
	if (difx <= 0 && dify <= 0)
		if (vsadi_way_3(param) || vsadi_way_4(param))
			return (1);
	if (difx > 0 && dify <= 0)
		if (vsadi_way_4(param) || vsadi_way_1(param))
			return (1);
	return (0);
}

void	find_figure(t_filler *param)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (param->token[y] != 0)
	{
		while (param->token[y][x] != 0)
		{
			if (param->token[y][x] == '*')
			{
				param->me_j = x + param->j;
				param->me_i = y + param->i;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int		hit_enemy(t_filler *param, int i, int j)
{
	int x;
	int y;
	int tmpj;

	tmpj = j;
	x = param->token_w * 2 + 1;
	y = param->token_h * 2 + 1;
	while (y > 0)
	{
		while (x > 0)
		{
			if (i >= 0 && j >= 0 && i < param->board_h && j < param->board_w
			&& param->board[i][j] == param->enemy)
				if (vsadi_enemy(i - param->token_h, j - param->token_w, param))
					return (1);
			x--;
			j++;
		}
		x = param->token_w * 2 + 1;
		j = tmpj;
		i++;
		y--;
	}
	return (0);
}
