/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:29:18 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/04/10 11:38:18 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			minsquare(t_etris **tets)
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

t_map		*init_board(int numtets, int minsq)
{
	size_t	square;
	t_map	*ret;
	int		x;
	int		y;

	square = (size_t)minsq;
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

void		grow_board(t_map *board)
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
		CHECK_BAD_VOID(!(board->map[y] = (char*)ft_strnew(board->size)));
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

int			find_and_place(t_map *board, t_etris *tet)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < board->size && !is_placed(tet))
	{
		x = 0;
		while (x < board->size && !is_placed(tet))
		{
			if (can_place(tet, board, x, y))
			{
				place_tet(tet, board, (int)x, (int)y);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void		adv_xy(size_t board_len, size_t *x, size_t *y)
{
	*y += (++*x / board_len);
	*x %= board_len;
}

int			solve_board(t_map *board, t_etris **tets, int numtets)
{
	int		i;
	int		j;
	size_t	x;
	size_t	y;

	i = 0;
	x = 0;
	j = 0;
	y = 0;
	while (is_placed(tets[i]))
		i++;
	if (!find_and_place(board, tets[i]))
		return (0);
	if (i == numtets - 1)
	{
		while (board->map[j])
		{
			ft_putstr(board->map[j]);
			ft_putchar('\n');
			j++;
		}
		return (1);
	}
	while (!solve_board(board, tets, numtets))
	{
		remove_tet(tets[i], board);
		adv_xy(board->size, &x, &y);
		while (!can_place(tets[i], board, x, y))
		{
			adv_xy(board->size, &x, &y);
			if (y > board->size)
			{
				CHECK_BAD(i != 0);
				x = 0;
				y = 0;
				i = 0;
				grow_board(board);
			}
		}
		place_tet(tets[i], board, (int)x, (int)y);
	}
	return (1);
}
