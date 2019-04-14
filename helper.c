/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:19:29 by elhampto          #+#    #+#             */
/*   Updated: 2019/04/14 00:47:15 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		place_tet(t_etris *tet, t_map *board, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tet->placedx[i] = tet->x[i] + x;
		tet->placedy[i] = tet->y[i] + y;
		board->map[tet->placedy[i]][tet->placedx[i]] = tet->letter;
		i++;
	}
}

int			can_place(t_etris *tet, t_map *board, int x, int y)
{
	int	i;

	CHECK_BAD(!tet);
	i = 0;
	if (is_placed(tet))
		return (0);
	while (i < 4)
	{
		if (tet->x[i] + x >= board->size || tet->y[i] + y >= board->size)
			return (0);
		if (board->map[tet->y[i] + y][tet->x[i] + x] != '.')
			return (0);
		i++;
	}
	return (1);
}

int			find_and_place(t_map *board, t_etris *tet)
{
	int	y;
	int	x;

	y = 0;
	while (y < board->size && !is_placed(tet))
	{
		x = 0;
		while (x < board->size && !is_placed(tet))
		{
			if (can_place(tet, board, x, y))
			{
				place_tet(tet, board, x, y);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void		adv_xy(int board_len, int *x, int *y)
{
	*y += (++*x / board_len);
	*x %= board_len;
}

void		zero_out(int *i, int *x, int *y)
{
	*i = 0;
	*x = 0;
	*y = 0;
}
