/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:47:41 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/16 20:03:29 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		cleaning_matrix(char ***matrix_for_cl)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = *matrix_for_cl;
	if (matrix == 0)
		return ;
	while (matrix[i] != 0)
	{
		ft_strdel(&matrix[i]);
		i++;
	}
	free(matrix);
	matrix = 0;
}

void		cleaning(t_filler *param, int end)
{
	if (param->board_prev != 0)
	{
		cleaning_matrix(&param->board_prev);
	}
	if (end == 1)
		param->board_prev = param->board;
	else
		cleaning_matrix(&param->board);
	cleaning_matrix(&param->token);
}
