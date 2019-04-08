/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 22:57:39 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/04/05 12:48:14 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clean_tetstrings(char **tets)
{
	int i;

	i = -1;
	while (tets[++i])
	{
		free(tets[i]);
		tets[i] = NULL;
	}
	free(tets);
	tets = NULL;
}

void	clean_tetstructs(t_etris **tets)
{
	int i;

	i = -1;
	while (tets[++i])
	{
		free(tets[i]);
		tets[i] = NULL;
	}
	free(tets);
	tets = NULL;
}

void	remove_tet(t_etris *tet)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		tet->placedx[i] = -1;
		tet->placedy[i] = -1;
	}
}

void	remove_all(t_etris **tets)
{
	int i;

	i = -1;
	while (tets[++i])
		remove_tet(tets[i]);
}