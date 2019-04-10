/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:04:48 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/04/09 20:00:01 by cmckelvy         ###   ########.fr       */
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

int		verify(char **tets, int j)
{
	int		i;
	int		squares;
	int		connections;

	i = -1;
	squares = 0;
	connections = 0;
	while (tets[j][++i])
	{
		CHECK_BAD(tets[j][i] != '#' && tets[j][i] != '.' && tets[j][i] != '\n');
		if (FILLED(tets[j][i]) == 1)
		{
			squares++;
			if ((i > 3) && FILLED(tets[j][i - 5]) == 1)
				connections++;
			if (FILLED(tets[j][i + 5]) == 1)
				connections++;
			if ((i > 0) && FILLED(tets[j][i - 1]) == 1)
				connections++;
			if (FILLED(tets[j][i + 1]) == 1)
				connections++;
		}
	}
	CHECK_BAD(squares != 4 || (connections != 8 && connections != 6));
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
		tets[j] = ft_strnew(21);
		tets[j] = ft_strncpy(tets[j], &str[f], 20);
		tets[j][21] = '\0';
		if (!verify(tets, j))
		{
			ft_putstr("Error1");
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
	/*
	need to replace the above if statement with a way to just check the number of newlines
	between tets in the file to count instead
	*/
	{
		ft_putstr("Error2");
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
