//EX01

// #include "./ex01/ft_boolean.h"

// void ft_putstr(char *str)
// {
// 	while (*str)
// 	write(1, str++, 1);
// }

// t_bool ft_is_even(int nbr)
// {
// 	return ((EVEN(nbr)) ? TRUE : FALSE);
// }

// int main(int argc, char **argv)
// {
// 	(void)argv;
// 	if (ft_is_even(argc - 1) == TRUE)
// 	ft_putstr(EVEN_MSG);
// 	else
// 	ft_putstr(ODD_MSG);
// 	return (SUCCESS);
// }


// ------------------------------------------------------------

// EX02

// #include <stdio.h>
// #include "./ex02/ft_abs.h"

// int main()
// {
//    int val;
//    int abs;
   
//    val=-10;
//    abs = ABS(val);
//    printf("%d\n", abs);
//    val=10;
//     abs = ABS(val);
//    printf("%d\n", abs);
   
//    return 0;
// }


// ------------------------------------------------------------

// EX03

// #include "./ex03/ft_point.h"

// void set_point(t_point *point)
// {
// 	point->x = 42;
// 	point->y = 21;
// }
// int main(void)
// {
// 	t_point point;
// 	set_point(&point);
// 	return (0);
// }

// ------------------------------------------------------------

// EX04 e EX05

// #include "./ex04/ft_strs_to_tab.c"
// #include "./ex05/ft_show_tab.c"

// int main(void)
// {
// 	t_stock_str	*struct_matrix;
// 	char *av[] = {"1111", "", "33333", "444444", "ffef", "uscl..~", "1324331", "hfkje", "agrar"};

// 	struct_matrix = ft_strs_to_tab(9, av);

// 	struct_matrix[0].copy[2] = 'a';
// 	struct_matrix[0].copy[3] = 's';
// 	ft_show_tab(struct_matrix);
// 	return (1);
// }
