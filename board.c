/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:10:16 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/04/14 23:02:57 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				minsquare(t_etris **tets)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	while (tets[i])
	{
		j = 0;
		while (j < 4)
		{
			if (tets[i]->x[j] > ret)
				ret = tets[i]->x[j];
			if (tets[i]->y[j] > ret)
				ret = tets[i]->y[j];
			j++;
		}
		i++;
	}
	return (ret + 1);
}

t_map			*init_board(int numtets, int minsq)
{
	int		square;
	t_map	*ret;
	int		x;
	int		y;

	square = minsq;
	while (square * square < numtets * 4)
		square++;
	CHECK_BAD(!(ret = (t_map*)malloc(sizeof(t_map))));
	CHECK_BAD(!(ret->map = (char**)malloc(sizeof(char*) * (square + 1))));
	ret->size = square;
	y = -1;
	while (++y < square)
	{
		x = -1;
		CHECK_BAD(!(ret->map[y] = (char*)malloc(sizeof(char) * (square + 1))));
		while (++x < square)
			ret->map[y][x] = '.';
		ret->map[y][x] = '\0';
	}
	ret->map[y] = NULL;
	return (ret);
}

static void		grow_board(t_map *board)
{
	char	**tmp;
	int		y;
	int		x;

	tmp = board->map;
	board->size += 1;
	board->map = NULL;
	CHECK_BAD_V(!(board->map =
		(char**)ft_memalloc(sizeof(char*) * (board->size + 1))));
	y = -1;
	while (++y < board->size)
	{
		x = -1;
		CHECK_BAD_V(!(board->map[y] = (char*)ft_strnew(board->size)));
		if (tmp[y])
		{
			ft_memcpy(board->map[y], tmp[y], ft_strlen(tmp[y]));
			board->map[y][board->size - 1] = '.';
		}
		else
			ft_memset(board->map[y], '.', board->size);
		board->map[y][x] = '\0';
	}
	board->map[y] = NULL;
}

char			print_board(t_map *board, int numtets, int i)
{
	int j;

	j = -1;
	if (i == numtets - 1)
	{
		while (board->map[++j])
		{
			ft_putstr(board->map[j]);
			ft_putchar('\n');
		}
	}
	return (1);
}

int				solve_board(t_map *board, t_etris **tets, int numtets, int i)
{
	int		x;
	int		y;

	zero_out(&i, &x, &y);
	ITERATE(is_placed(tets[i]), i);
	CHECK_BAD(!find_and_place(board, tets[i]));
	if (i == numtets - 1)
		CHECK_GOOD(print_board(board, numtets, i));
	while (!solve_board(board, tets, numtets, 0))
	{
		remove_tet(tets[i], board);
		adv_xy(board->size, &x, &y);
		while (!can_place(tets[i], board, x, y))
		{
			adv_xy(board->size, &x, &y);
			if (y > board->size)
			{
				CHECK_BAD(i != 0);
				zero_out(&i, &x, &y);
				grow_board(board);
			}
		}
		place_tet(tets[i], board, x, y);
	}
	return (1);
}
