/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:02:50 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/03/13 13:08:31 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

# define FILLED(c)				((c - '#' == 0) ? 1 : -1)
# define EMPTY(c)				((c - '.' == 0) ? 1 : 0)
# define CHECK_BAD(x)			if (x) return (0)
# define VALID_CHAR(c)			((c == '#' || c == '.' || c == '\n') ? 1 : 0)

typedef struct		s_etris
{
	char	letter;
	int		x[4];
	int		y[4];
}					t_etris;

typedef struct		s_map
{
	size_t	size;
	char	**map;
}					t_map;


void				tetread(char *filename);
size_t				tetsize(int fd);
int					verify(char **tets, int j);
void				split_pieces(char **tets, char *str, int i);
void				pieces(char *str, size_t size);
void				assign_coords(char **tets, int numtets, int i);
void				clean_tetstrings(char **tets);
void				clean_tetsructs(t_etris **tets);
#endif
