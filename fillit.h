/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:02:50 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/04/09 10:17:14 by cmckelvy         ###   ########.fr       */
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
# define CHECK_BAD_VOID(x)			if (x) return 
# define VALID_CHAR(c)			((c == '#' || c == '.' || c == '\n') ? 1 : 0)

typedef struct		s_etris
{
	char	letter;
	int		x[4];
	int		y[4];
	int		placedx[4];
	int		placedy[4];
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
void				clean_tetstructs(t_etris **tets);
int					minsquare(t_etris **tets);
t_map				*init_board(int numtets, int minsq);
void				remove_all(t_etris **tets, t_map *board);
void				remove_tet(t_etris *tet, t_map *board);
int					solve_board(t_map *board, t_etris **tets, int numtets);
int					is_placed(t_etris *tet);
#endif
