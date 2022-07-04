/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:39:30 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/12 16:01:51 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char *argv[])
{
	int *views_values;
	int **views_matrix;
	int **solution_matrix;
	int ***possibilities_matrix;
	int is_ok;

	if (argc != 2)
		return (ft_error(1) - 1);
	views_values = ft_view_vector(argv[1]); // transforma input do usuário em um vetor
	views_matrix = ft_matrix_factory(8, 2); // crio uma matrix 8x2
	solution_matrix = ft_matrix_factory(4, 4); // cria a matriz 4x4
	possibilities_matrix = ft_possibilities_matrix(); // cria a matriz de possibilidades
	ft_populate_matrix(views_matrix, views_values, 8, 2); // popula a matriz de views
	ft_view_verification(views_matrix, solution_matrix, possibilities_matrix); // a partir 8x2 elimina
	// as possibilidades e gera a matriz de rolução
	ft_verification_to_clear(
		views_matrix, possibilities_matrix, solution_matrix, 0); // faz as eliminações
	is_ok = ft_final_verify(views_matrix, solution_matrix); // verifica se a solução está correta
	if (is_ok < 1)
		return (ft_error(1) - 1); // se tiver errada printa error
	print_matrix(solution_matrix, 4, 4); // por ultimo printa a matrix
	return (1);
}
