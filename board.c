/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:52:56 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/04/08 12:14:09 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int        minsquare(t_etris **tets)
{
    int i;
    int j;
    int ret;

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

t_map    *init_board(int numtets, int minsq)
{
    size_t        square;
    t_map    *ret;
    int        x;
    int        y;

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
        printf("%s\n", ret->map[y]);
    }
    ret->map[y] = NULL;
    return (ret);
}

void        place_tet(t_etris *tet, t_map *board, int x, int y)
{
    int i;

    i = 0;
    while (i < 4)
    {
        tet->placedx[i] = tet->x[i] + x;
        tet->placedy[i] = tet->y[i] + y;
        board->map[tet->placedy[i]][tet->placedx[i]] = tet->letter;
        i++;
    }
}

int            can_place(t_etris *tet, t_map *board, int x, int y)
{
    int i;

    i = 0;
    if(is_placed(tet))
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

void        solve_board(t_map *board, t_etris **tets, int numtets)
{
    int     i;
    int        j;
    size_t    x;
    size_t    y;

    i = 0;
    y = 0;
    j = 0;
    y = 0;
    remove_all(tets);
    while (i < numtets)
    {
        if (!is_placed(tets[i]))
            printf("tet %d is not placed\n", i);
        i++;
    }
    i = 0;
    while (is_placed(tets[i]))
        i++;
    while (tets[i])
    {
        y = 0;
        while (y < board->size && !is_placed(tets[i]))
        {
            x = 0;
            while (x < board->size && !is_placed(tets[i]))
            {
                if (can_place(tets[i], board, x, y))
                    place_tet(tets[i], board, (int)x, (int)y);
                x++;
            }
            y++;
        }
        i++;
    }
    while (board->map[j])
    {
        ft_putstr(board->map[j]);
        ft_putchar('\n');
        j++;
    }
}

/* need to figure out how to iterate tets while checking if they 
can be placed on coords
*/