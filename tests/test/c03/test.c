#include <stdio.h>
#include <string.h>

//ex00
#include "./ex00/ft_strcmp.c"
int ft_strcmp(char *s1, char *s2);

//ex01
#include "./ex01/ft_strncmp.c"
int ft_strncmp(char *s1, char *s2, unsigned int n);

//ex02
#include "./ex02/ft_strcat.c"
char	*ft_strcat(char *dest, char *src);

//ex03
#include "./ex03/ft_strncat.c"
char *ft_strncat(char *dest, char *src, unsigned int nb);

//ex04
#include "./ex04/ft_strstr.c"
char *ft_strstr(char *str, char *to_find);

//ex05
#include "./ex05/ft_strlcat.c"
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);


int main()
{

	// //ex00
	// char s1[] = ";?Bsfw";
	// char s2[] = ";//argae23123rg";
	// int n12 = strcmp(s1, s2);
	// int n13 = ft_strcmp(s1, s2);
	// printf("%d %d", n12, n13);

	// //ex01
	// char s1[] = ";/?Bsfw";
	// char s2[] = ";//argae23123rg";
	// int n = 3;
	// int n12 = strncmp(s1, s2, n);
	// int n13 = ft_strncmp(s1, s2, n);
	// printf("%d %d", n12, n13);

	// //ex02
	// char srco[8] = ";/?Bsfw";
	// char srci[8] = ";/?Bsfw";
	// char desto[21] = ";//argae23123rg";
	// char desti[21] = ";//argae23123rg";
	// char *o = strcat(desto, srco);
	// char *i = ft_strcat(desti, srci);
	// printf("%s\n", o);
	// printf("%s\n", desto);
	// printf("%s\n", i);
	// printf("%s\n", desti);

	// //ex03
	// char srci[8] = ";/?Bsfw";
	// char srco[8] = ";/?Bsfw";
	// char desto[21] = ";//argae23123rg";
	// char desti[21] = ";//argae23123rg";
	// int n = 3;
	// char *o = strncat(desto, srco, n);
	// char *i = ft_strncat(desti, srci, n);
	// printf("%s\n", o);
	// printf("%s\n", desto);
	// printf("%s\n", i);
	// printf("%s\n", desti);

	//ex04
	// char haystacko[21] = "ads;/?/argae23123rg";
	// char haystacki[21] = "asd;/?/argae23123rg";
	// char needleo[8] = ";/?";
	// char needlei[8] = ";/?";
	char haystacko[] = "abacabacabcvaab";
	char haystacki[] = "abacabacabcvaab";
	char needleo[] = "abc";
	char needlei[] = "abc";
	char *o = strstr(haystacko, needleo);
	char *i = ft_strstr(haystacki, needlei);
	printf("%s\n", o);
	printf("%s\n", i);

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
