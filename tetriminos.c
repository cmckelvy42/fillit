/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:36:02 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/04/10 19:47:49 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_etris	**malloctets(int numtets, int i, int j)
{
	t_etris **tmp;

	if (!(tmp = (t_etris**)ft_memalloc(sizeof(t_etris*) * numtets + 1)))
	{
		ft_putstr("error\n");
		return (NULL);
	}
	while (++i < numtets)
	{
		if (!(tmp[i] = (t_etris*)ft_memalloc(sizeof(t_etris))))
		{
			ft_putstr("error\n");
			return (NULL);
		}
		tmp[i]->letter = 'A' + i;
		j = 0;
		while (++j < 4)
		{
			tmp[i]->x[j] = 0;
			tmp[i]->y[j] = 0;
		}
	}
	tmp[i] = NULL;
	return (tmp);
}

void	assign_coords2(char **tets, t_etris **tmp, int i, int j)
{
	int x;
	int y;
	int square;

	x = 0;
	y = 0;
	square = 0;
	while (tets[i][++j])
	{
		if (tets[i][j] == '#')
		{
			tmp[i]->x[square] = x;
			tmp[i]->y[square] = y;
			square++;
		}
		x++;
		if (tets[i][j] == '\n')
		{
			x = 0;
			y++;
		}
	}
}

void	zerocoords(t_etris **tets)
{
	int i;
	int j;
	int left;
	int top;

	i = -1;
	while (tets[++i])
	{
		j = -1;
		left = 3;
		while (++j < 4)
			if (tets[i]->x[j] < left)
				left = tets[i]->x[j];
		j = -1;
		top = tets[i]->y[0];
		while (++j < 4)
		{
			tets[i]->x[j] = tets[i]->x[j] - left;
			tets[i]->y[j] = tets[i]->y[j] - top;
		}
	}
}

void	assign_coords(char **tets, int numtets, int i)
{
	t_etris	**tmp;
	t_map	*board;

	tmp = malloctets(numtets, -1, -1);
	while (tets[++i])
	{
		assign_coords2(tets, tmp, i, -1);
		zerocoords(tmp);
	}
	clean_tetstrings(tets);
	board = init_board(numtets, minsquare(tmp));
	remove_all(tmp, board);
	solve_board(board, tmp, numtets);
	clean_tetstructs(tmp);
	clean_board(board);
}

int		is_placed(t_etris *tet)
{
	int i;

	i = -1;
	while (++i < 4)
		if (tet->placedx[i] < 0 || tet->placedy[i] < 0)
			return (0);
	return (1);
}
