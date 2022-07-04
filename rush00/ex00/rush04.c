/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:32:50 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/04 14:31:19 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_first_line(int column, int total_columns)
{
	if (column == total_columns && column != 1)
	{
		ft_putchar('C');
		ft_putchar('\n');
	}
	else if (column == 1)
	{
		ft_putchar('A');
		if (column == total_columns)
		{
			ft_putchar('\n');
		}
	}
	else
	{
		ft_putchar('B');
	}
}

void	print_middle_line(int column, int total_columns)
{
	if (column == total_columns)
	{
		ft_putchar('B');
		ft_putchar('\n');
	}
	else if (column == 1)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	print_last_line(int column, int total_columns)
{
	if (column == total_columns && column != 1)
	{
		ft_putchar('A');
		ft_putchar('\n');
	}
	else if (column == 1)
	{
		ft_putchar('C');
		if (column == total_columns)
		{
			ft_putchar('\n');
		}
	}
	else
	{
		ft_putchar('B');
	}
}

void	print_lines(int line, int total_lines, int column, int total_columns)
{
	if (line == 1)
	{
		print_first_line(column, total_columns);
	}
	else if (line < total_lines)
	{
		print_middle_line(column, total_columns);
	}
	else
	{
		print_last_line(column, total_columns);
	}
}

void	rush(int x, int y)
{
	int current_column;
	int current_line;

	current_column = 1;
	current_line = 1;
	while (current_line <= y)
	{
		while (current_column <= x)
		{
			print_lines(current_line, y, current_column, x);
			current_column = current_column + 1;
		}
		current_column = 1;
		current_line = current_line + 1;
	}
}
