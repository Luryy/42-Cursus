#include <stdio.h>

//ex00
#include "./ex00/ft_ft.c"
void    ft_ft(int *nbr);

// //ex01
// #include "./ex01/ft_ultimate_ft.c"
// void ft_ultimate_ft(int *********nbr);

// //ex02
// #include "./ex02/ft_swap.c"
// void ft_swap(int *a, int *b);

// //ex03
// #include "./ex03/ft_div_mod.c"
// void ft_div_mod(int a, int b, int *div, int *mod);

// //ex04
// #include "./ex04/ft_ultimate_div_mod.c"
// void ft_ultimate_div_mod(int *a, int *b);

// //ex05
// #include "./ex05/ft_putstr.c"
// void ft_putstr(char *str);

// //ex06
// #include "./ex06/ft_strlen.c"
// int ft_strlen(char *str);

// //ex07
// #include "./ex07/ft_rev_int_tab.c"
// void ft_rev_int_tab(int *tab, int size);

// //ex08
// #include "./ex08/ft_sort_int_tab.c"
// void ft_sort_int_tab(int *tab, int size);

int main(void)
{
	//ex00
	int nbr = 10;
	ft_ft(&nbr);
	printf("%d", nbr);

	// //ex01
	// int nbr = 10;
	// int *nbr1 = &nbr;
	// int **nbr2 = &nbr1;
	// int ***nbr3 = &nbr2;
	// int ****nbr4 = &nbr3;
	// int *****nbr5 = &nbr4;
	// int ******nbr6 = &nbr5;
	// int *******nbr7 = &nbr6;
	// int ********nbr8 = &nbr7;
	// ft_ultimate_ft(&nbr8);
	// printf("%d", nbr);

	// //ex02
	// int a = 10;
	// int b = 11;
	// printf("%d, %d\n", a, b);
	// ft_swap(&a, &b);
	// printf("%d, %d", a, b);

	// //ex03
	// int a = 111;
	// int b = 11;
	// int div;
	// int mod;
	// ft_div_mod(a, b, &div, &mod);
	// printf("%d, %d", div, mod);

	// //ex04
	// int a = 111;
	// int b = 11;
	// ft_ultimate_div_mod(&a, &b);
	// printf("%d, %d", a, b);

	//ex05
	// ft_putstr("leptospirose");

	// //ex06
	// printf("Resultado %d", ft_strlen("leptospirose"));

	// //ex07
	// int tab[6] = {-2147483648,395,3,2,1,0};
    // int size = 6;
    // printf("*------ANTES------*\n");
    // int i = 0;
    // while (i < size)
    // {
    //     printf("%d: %d\n", i + 1, tab[i]);
    //     i++;
    // }
    // ft_rev_int_tab(tab, size);
    //     printf("*------DEPOIS------*\n");
    // i = 0;
    // while (i < size)
    // {
    //     printf("%d: %d\n", i + 1, tab[i]);
    //     i++;
    // }

	// //ex08
	// int tab[10] = {-2147483648,395,3,2,1,900, -4, 2147483647, 9, -1};
    // int size = 10;
    // printf("*------ANTES------*\n");
    // int i = 0;
    // while (i < size)
    // {
    //     printf("%d: %d\n", i + 1, tab[i]);
    //     i++;
    // }
    // ft_sort_int_tab(tab, size);
    //     printf("*------DEPOIS------*\n");
    // i = 0;
    // while (i < size)
    // {
    //     printf("%d: %d\n", i + 1, tab[i]);
    //     i++;
    // }


	return (0);
}