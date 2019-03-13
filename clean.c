/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 22:57:39 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/03/11 23:28:42 by cmckelvy         ###   ########.fr       */
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

void	clean_tetsructs(t_etris **tets)
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
