/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:47:21 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 22:03:15 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

int		ft_count_coloumn_view_start(int j, int **solution);
int		ft_count_coloumn_view_end(int j, int **solution);
int		ft_count_line_view_start(int i, int **solution);
int		ft_count_line_view_end(int i, int **solution);
void	ft_clear_value(int i, int j, int clear_value, int ***m);
void	ft_include_solution_i(int i, int j, int **solution, int ***mp);
void	ft_include_solution_n(int i, int *vec, int **solution, int ***mp);
void	ft_solution_matrix(int i, int j, int new_value, int **solution);
void	ft_clear_solution(int i, int j, int solution_value, int ***m);
int		**ft_matrix_factory(int lines, int coloumns);
int		*init(int n);
void	permute(int *v, const int start, int *line, int **permut);
int		ft_count_view_per_st_col(int *per, int total, int ***mp, int j);
int		ft_count_view_per_ed_col(int *per, int total, int ***mp, int j);
int		ft_count_view_per_st_ln(int *per, int total, int ***mp, int i);
int		ft_count_view_per_ed_ln(int *per, int total, int ***mp, int i);
int		ft_error(int i);
void	ft_sequence_filtration(int **views, int ***mp);
void	ft_format_n(int d, int l, int **solution, int ***mp);
void	ft_format_i(int d, int l, int **solution, int ***mp);
void	ft_format_m(int d, int l, int view, int ***mp);
int		*ft_view_vector(char *v);
int		***ft_possibilities_matrix(void);
void	print_possibilities_matrix(int ***m);
void	print_matrix(int **m, int lines, int coloumns);
void	ft_populate_matrix(int **m, int *values, int lines, int coloumns);
void	ft_view_verification(int **views, int **solution, int ***mp);
void	ft_verification_to_clear(int **view, int ***m, int **sol, int c);
int		ft_final_verify(int **view, int **solution);

#endif
