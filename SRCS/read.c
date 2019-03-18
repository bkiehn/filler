/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 21:08:28 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/16 20:32:55 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				read_headline(t_filler *param)
{
	char			*line;
	int				lstr;

	get_next_line(0, &line);
	if (line[10] == '1')
	{
		param->me = 'O';
		param->enemy = 'X';
	}
	else
	{
		param->me = 'X';
		param->enemy = 'O';
	}
	ft_strdel(&line);
	get_next_line(0, &line);
	lstr = ft_strlen(line);
	while (line[lstr] != ' ' && lstr != 1)
		lstr--;
	param->board_w = ft_atoi(line + lstr);
	lstr--;
	while (line[lstr] != ' ' && lstr != 0)
		lstr--;
	param->board_h = ft_atoi(line + lstr);
	ft_strdel(&line);
}

int					read_board(t_filler *param)
{
	char			*line;
	int				i;

	i = 0;
	if (!(get_next_line(0, &line)))
		return (0);
	if (*line == 'P')
	{
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	ft_strdel(&line);
	param->board = (char**)malloc(sizeof(char*) * (param->board_h + 1));
	param->board[param->board_h] = 0;
	while (i < param->board_h)
	{
		get_next_line(0, &line);
		param->board[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	return (1);
}

void				read_token(t_filler *param)
{
	char			*line;
	int				i;
	int				lstr;

	i = 0;
	get_next_line(0, &line);
	lstr = ft_strlen(line);
	while (line[lstr] != ' ' && lstr != 1)
		lstr--;
	param->token_w = ft_atoi(line + lstr);
	lstr--;
	while (line[lstr] != ' ' && lstr != 0)
		lstr--;
	param->token_h = ft_atoi(line + lstr);
	param->token = (char**)malloc(sizeof(char*) * (param->token_h + 1));
	param->token[param->token_h] = 0;
	ft_strdel(&line);
	i = 0;
	while (i < param->token_h)
	{
		get_next_line(0, &line);
		param->token[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
}
