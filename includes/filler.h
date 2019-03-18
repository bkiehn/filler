/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:33:21 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/18 20:02:40 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define BOA param->board[i][j]
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_filler
{
	char			me;
	char			enemy;
	int				board_h;
	int				board_w;
	int				token_h;
	int				token_w;
	int				enemy_i;
	int				enemy_j;
	int				me_i;
	int				me_j;
	int				i;
	int				j;
	char			somewhere;
	char			enemy_kill;
	char			**board_prev;
	char			**board;
	char			**token;
}					t_filler;

typedef struct		s_vsadi
{
	int				x;
	int				y;
	int				tmpj;
	int				iter;
	int				i_end;
	int				j_end;
}					t_vsadi;

void				read_headline(t_filler *param);
void				read_token(t_filler *param);
int					read_board(t_filler *param);
int					input_token(t_filler *param);
int					chek_input_token(t_filler *param, int i, int j);
void				cleaning(t_filler *param, int end);
int					vsadi_enemy(int i, int j, t_filler *param);
void				find_last_coordinates(t_filler *param);
void				find_coordinates(t_filler *param, int x, int y);
int					find_way(t_filler *param);
int					vsadi_way_1(t_filler *param);
int					vsadi_way_2(t_filler *param);
int					vsadi_way_3(t_filler *param);
int					vsadi_way_4(t_filler *param);
int					somewhere(t_filler *param);
void				find_figure(t_filler *param);
int					hit_enemy(t_filler *param, int i, int j);

#endif
