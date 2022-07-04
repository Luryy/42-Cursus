#include <stdio.h>
#include <string.h>

// //ex00
// #include "./ex00/ft_strlen.c"
// int ft_strlen(char *str);

// //ex01
// #include "./ex01/ft_putstr.c"
// void ft_putstr(char *str);

// //ex02
// #include "./ex02/ft_putnbr.c"
// void ft_putnbr(int nb);

// //ex03
// #include "./ex03/ft_atoi.c"
// int ft_atoi(char *str);

//ex04
#include "./ex04/ft_putnbr_base.c"
void ft_putnbr_base(int nbr, char *base);

// //ex05
// #include "./ex05/ft_strlcat.c"
// unsigned int ft_strlcat(char *dest, char *src, unsigned int size);


int main()
{

	// //ex00
	// char s1[2] = "ab";
	// // char s2[15] = ";//argae23123rg";
	// int n12 = strlen(s1);
	// int n13 = ft_strlen(s1);
	// printf("%d %d", n12, n13);

	// //ex01
	// char s1[7] = ";/?Bsfw";
	// // char s1[] = ";//argae23123rg";
	// ft_putstr(s1);
	// printf("\n");


	// //ex02
	// ft_putnbr(42);
	// printf("\n");
	// ft_putnbr(2147483647);
	// printf("\n");
	// ft_putnbr(-2147483648);
	// printf("\n");

	// //ex03
	// int atoi;
	
	// // atoi = ft_atoi("\n \t ------+++57389dmk00");
	// atoi = ft_atoi(" ---+--+1234ab567");
	// printf("%d\n", atoi);


	// //ex04
	ft_putnbr_base(102345, "abcd");
	// ft_putnbr_base(10, "01");
	// ft_putnbr_base(10, "1");

	// //ex05
	// char srci[8] = ";/?Bsfw";
	// char srco[8] = ";/?Bsfw";
	// char desti[22] = ";//argae23123rg";
	// char desto[22] = ";//argae23123rg";
	// int n = 23;
	// int o = strlcat(desto, srco, n);
	// int i = ft_strlcat(desti, srci, n);
	// printf("%s\n", desto);
	// printf("%d\n", o);
	// printf("%s\n", desti);
	// printf("%d\n", i);

	return (0);
}
