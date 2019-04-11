/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:04:48 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/04/10 20:31:15 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	tetsize(int fd, int *numtets)
{
	size_t	i;
	char	buf[1];
	int		lines;

	i = 0;
	lines = 0;
	*numtets = 0;
	while (read(fd, buf, 1))
	{
		i++;
		if (buf[0] == '\n')
			lines++;
		if (lines == 5)
		{
			*numtets += 1;
			lines = 0;
		}
	}
	*numtets += 1;
	close(fd);
	return (i);
}

int		verify(char **tets, int j, int con, int lines)
{
	int		i;
	int		sq;

	i = -1;
	sq = 0;
	while (tets[j][++i])
	{
		CHECK_BAD(tets[j][i] != '#' && tets[j][i] != '.' && tets[j][i] != '\n');
		if (tets[j][i] == '\n')
			lines++;
		if (FILLED(tets[j][i]) == 1)
		{
			sq++;
			if ((i > 3) && FILLED(tets[j][i - 5]) == 1)
				con++;
			if (FILLED(tets[j][i + 5]) == 1)
				con++;
			if ((i > 0) && FILLED(tets[j][i - 1]) == 1)
				con++;
			if (FILLED(tets[j][i + 1]) == 1)
				con++;
		}
	}
	CHECK_BAD(lines != 3 || i != 19 || sq != 4 || (con != 8 && con != 6));
	return (1);
}

void	split_pieces(char **tets, char *str, int i)
{
	int f;
	int j;

	f = 0;
	j = -1;
	while (++j < i)
	{
		tets[j] = ft_strnew(20);
		tets[j] = ft_strncpy(tets[j], &str[f], 19);
		tets[j][20] = '\0';
		if (!verify(tets, j, 0, 0))
		{
			ft_putstr("error");
			return ;
		}
		f += 21;
	}
	tets[j] = NULL;
	assign_coords(tets, i, -1);
}

void	pieces(char *str, int numtets)
{
	char	**tets;
	int		f;
	int		j;

	j = -1;
	f = 0;
	if (!(tets = (char**)malloc(sizeof(char*) * (numtets + 1)))
			|| numtets > 26)
	{
		ft_putstr("error");
		return ;
	}
	split_pieces(tets, str, numtets);
}

void	tetread(char *filename)
{
	int			fd;
	char		*tfile;
	size_t		tsize;
	int			numtets;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error: invalid file\n");
		return ;
	}
	tsize = tetsize(fd, &numtets);
	tfile = ft_strnew(tsize);
	fd = open(filename, O_RDONLY);
	read(fd, tfile, tsize);
	pieces(tfile, numtets);
	free(tfile);
}
