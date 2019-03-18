/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:47:44 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/16 20:08:34 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int			main(void)
{
	t_filler	param;
	int			end;

	ft_memset(&param, 0, sizeof(param));
	read_headline(&param);
	while (1)
	{
		if (read_board(&param))
		{
			read_token(&param);
			end = input_token(&param);
			if (param.somewhere == 0)
				find_figure(&param);
			ft_putnbr(param.i);
			ft_putchar(' ');
			ft_putnbr(param.j);
			ft_putchar('\n');
			cleaning(&param, end);
			if (end == 0)
				exit(0);
		}
	}
}
