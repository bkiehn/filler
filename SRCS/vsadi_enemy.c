/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsadi_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:41:15 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/18 19:51:18 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_set(t_vsadi *set, t_filler *param, int i, int j)
{
	set->x = param->token_w * 2 + 1;
	set->y = param->token_h * 2 + 1;
	set->iter = 1;
	set->i_end = i + param->token_h * 2 + 1;
	set->j_end = j + param->token_w * 2 + 1;
	set->tmpj = j;
}

int		vstavka(t_vsadi *set, t_filler *param, int i, int *j)
{
	if (set->iter % 2 != 0)
	{
		if (chek_input_token(param, i, *j))
		{
			param->i = i;
			param->j = *j;
			return (1);
		}
		*j += 1;
	}
	else
	{
		if (chek_input_token(param, set->i_end, set->j_end))
		{
			param->i = set->i_end;
			param->j = set->j_end;
			return (1);
		}
		set->j_end--;
	}
	return (0);
}

int		vsadi_enemy(int i, int j, t_filler *param)
{
	t_vsadi	set;

	ft_memset(&set, 0, sizeof(set));
	init_set(&set, param, i, j);
	while (set.y > 0)
	{
		while (set.x > 0)
		{
			if (vstavka(&set, param, i, &j))
				return (1);
			set.x--;
			set.iter++;
		}
		j = set.tmpj;
		set.j_end = set.tmpj + param->token_w * 2 + 1;
		set.i_end--;
		i++;
		set.x = param->token_w * 2 + 1;
		set.y--;
	}
	return (0);
}
