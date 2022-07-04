#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// //ex00
// #include "./ex00/ft_strdup.c"
// char *ft_strdup(char *src);

// //ex01
// #include "./ex01/ft_range.c"
// int *ft_range(int min, int max);

// //ex02
// #include "./ex02/ft_ultimate_range.c"
// int ft_ultimate_range(int **range, int min, int max);

//ex03
#include "./ex03/ft_strjoin.c"
char *ft_strjoin(int size, char **strs, char *sep);

int		validate_range(int *buf, int min, int max)
{
	int i;

	i = 0;
	while (min < max)
		if (buf[i++] != min++)
			return (0);
	return (1);
}

int main()
{

	// //ex00
	// char s1[6] = "abrgrg";
	// // char s1[15] = ";//argae23123rg";
	// // char s1[2] = "1\0";
	// char *n12 = strdup(s1);
	// char *n13 = ft_strdup(s1);
	// printf("%p %s\n", s1, s1);
	// printf("%p %s\n", n12, n12);
	// printf("%p %s\n", n13, n13);


	// //ex01
	// int max = 100;
	// int min = 6;
	// // int max = 6;
	// // int min = 6;
	// int i = -1;
	// int *p = ft_range(min, max);
	// while (++i < max - min)
	// 	printf("%d, ", p[i]);

	// //ex02
	// int **range;
	// int max = 2147483547;
	// int min = -100;
	// // // int i = 0;
	// // // int j;
	// range = malloc(1);
	// int size = ft_ultimate_range(range, min, max);
	// printf("%d\n", size);
	// // while (range[i] != '\0')
	// {
	// 	j = 0;
	// 	while (j < size)
	// 	{
	// 		printf("%d, ", range[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }

	// //ex03
	// char *p[3];
	// char sep[] = "|gds";
	// char a[] = "12345";
	// char b[] = "54321";
	// char c[] = "rq34rq43";
	// *p = a;
	// *(p + 1) = b;
	// *(p + 2) = c;
	// char *conc = ft_strjoin(3, p, sep);
	// printf("%s", conc);
	// free(conc);

	// printf("\e[1;31m-- Exercício 00: \e[0m");
	// char str0[] = "minha string de teste";
	// char str1[] = "OutraSuperDste";
	// char str2[] = "ainda mais um teste";
	// char str3[] = "";

	// char *test0;
	// char *test1;
	// char *test2;
	// char *test3;

	// test0 = ft_strdup(str0);
	// test1 = ft_strdup(str1);
	// test2 = ft_strdup(str2);
	// test3 = ft_strdup(str3);

	// if (strcmp(test0, str0) != 0)
	// 	printf("KO, expected \"%s\" got \"%s\"\n", test0, str0);
	// else if (strcmp(test1, str1) != 0)
	// 	printf("KO, expected \"%s\" got \"%s\"\n", test1, str1);
	// else if (strcmp(test2, str2) != 0)
	// 	printf("KO, expected \"%s\" got \"%s\"\n", test2, str2);
	// else if (strcmp(test3, str3) != 0)
	// 	printf("KO, expected \"%s\" got \"%s\"\n", test3, str3);
	// else
	// 	printf("OK\n");

	// free(test0);
	// free(test1);
	// free(test2);
	// free(test3);

	// int *buf0;
	// int *buf1;
	// int *buf2;
	// int *buf3;
	// int *buf4;
	// int *buf5;

	// printf("\e[1;31m-- Exercício 01: \e[0m");

	// buf0 = ft_range(2, 7);
	// buf1 = ft_range(1, 1000);
	// buf2 = ft_range(-10, -5);
	// buf3 = ft_range(28, 16);
	// buf4 = ft_range(590, 1200);
	// buf5 = ft_range(7, 9);

	// if (buf0 == NULL)
	// 	printf("KO, range 2 - 7 returned NULL\n");
	// else if (buf1 == NULL)
	// 	printf("KO, range 1 - 1000 returned NULL\n");
	// else if (buf2 == NULL)
	// 	printf("KO, range -10 - -5 returned NULL\n");
	// else if (buf3 != NULL)
	// 	printf("KO, range 28 - 16 should return NULL\n");
	// else if (buf4 == NULL)
	// 	printf("KO, range 590 - 1200 returned NULL\n");
	// else if (buf5 == NULL)
	// 	printf("KO, range 7 - 9 returned NULL\n");
	// else if (!validate_range(buf0, 2, 7))
	// 	printf("KO, range 2 - 7 is invalid\n");
	// else if (!validate_range(buf1, 1, 1000))
	// 	printf("KO, range 1 - 1000 is invalid\n");
	// else if (!validate_range(buf2, -10, -5))
	// 	printf("KO, range -10 - -5 is invalid\n");
	// else if (!validate_range(buf3, 28, 16))
	// 	printf("KO, range 28 - 16 is invalid\n");
	// else if (!validate_range(buf4, 590, 1200))
	// 	printf("KO, range 590 - 1200 is invalid\n");
	// else if (!validate_range(buf5, 7, 9))
	// 	printf("KO, range 7 - 9 is invalid\n");
	// else
	// 	printf("OK\n");

	// free(buf0);
	// free(buf1);
	// free(buf2);
	// free(buf3);
	// free(buf4);
	// free(buf5);

	// int *buf0 = NULL;
	// int *buf1 = NULL;
	// int *buf2 = NULL;
	// int *buf3 = NULL;
	// int *buf4 = NULL;
	// int *buf5 = NULL;
	// int ret;

	// printf("\e[1;31m-- Exercício 02: \e[0m");

	// if ((ret = ft_ultimate_range(&buf0, 2, 7) != 5))
	// 	printf("KO, range 2 - 7 has size 5 got %i\n", ret);
	// else if ((ret = ft_ultimate_range(&buf1, 1, 1000)) != 999)
	// 	printf("KO, range 1 - 1000 has size 999 got %i\n", 999);
	// else if ((ret = ft_ultimate_range(&buf2, -10, -5)) != 5)
	// 	printf("KO, range -10 - -5 has size 5 got %i\n", ret);
	// else if ((ret = ft_ultimate_range(&buf3, 28, 16)) != 0)
	// 	printf("KO, range 28 = 16 has size 0 got %i\n", ret);
	// else if ((ret = ft_ultimate_range(&buf4, 590, 1200)) != (610))
	// 	printf("KO, range 590 - 1200 has size 610 got %i\n", ret);
	// else if ((ret = ft_ultimate_range(&buf5, 7, 9)) != (9 - 7))
	// 	printf("KO, range 7 - 9 has size 2 got %i\n", ret);
	// else if ((ret = ft_ultimate_range(NULL, 7, 9)) != -1)
	// 	printf("KO, range = NULL should return -1, got %i\n", ret);
	// else if (buf0 == NULL)
	// 	printf("KO, range 2 - 7 returned NULL\n");
	// else if (buf1 == NULL)
	// 	printf("KO, range 1 - 1000 returned NULL\n");
	// else if (buf2 == NULL)
	// 	printf("KO, range -10 - -5 returned NULL\n");
	// else if (buf3 != NULL)
	// 	printf("KO, range 28 - 16 should return NULL\n");
	// else if (buf4 == NULL)
	// 	printf("KO, range 590 - 1200 returned NULL\n");
	// else if (buf5 == NULL)
	// 	printf("KO, range 7 - 9 returned NULL\n");
	// else if (!validate_range(buf0, 2, 7))
	// 	printf("KO, range 2 - 7 is invalid\n");
	// else if (!validate_range(buf1, 1, 1000))
	// 	printf("KO, range 1 - 1000 is invalid\n");
	// else if (!validate_range(buf2, -10, -5))
	// 	printf("KO, range -10 - -5 is invalid\n");
	// else if (!validate_range(buf3, 28, 16))
	// 	printf("KO, range 28 - 16 is invalid\n");
	// else if (!validate_range(buf4, 590, 1200))
	// 	printf("KO, range 590 - 1200 is invalid\n");
	// else if (!validate_range(buf5, 7, 9))
	// 	printf("KO, range 7 - 9 is invalid\n");
	// else
	// 	printf("OK\n");

	// free(buf0);
	// free(buf1);
	// free(buf2);
	// free(buf3);
	// free(buf4);
	// free(buf5);

	// printf("\e[1;31m-- Exercício 03: \e[0m");
	// char *buf0[] = {"caminla", "eduardo", "mauricio", "larissa", "wagner", "gabriel"};

	// char *ret0 = NULL;
	// char *ret1 = NULL;
	// char *ret2 = NULL;
	// char *ret3 = NULL;

	// char *tru0 = "caminla : eduardo : mauricio : larissa : wagner : gabriel";;
	// char *tru1 = "caminla, eduardo";;
	// char *tru2 = "larissa-wagner-gabriel";;
	// char *tru3 = "eduardomauricio";;

	// if (strcmp(ret0 = ft_strjoin(6, buf0, " : "), tru0) != 0)
	// 	printf("KO, test00\n");
	// else if (strcmp(ret1 = ft_strjoin(2, buf0, ", "), tru1) != 0)
	// 	printf("KO, test01\n");
	// else if (strcmp(ret2 = ft_strjoin(3, buf0 + 3, "-"), tru2) != 0)
	// 	printf("KO, test02\n");
	// else if (strcmp(ret3 = ft_strjoin(2, buf0 + 1, ""), tru3) != 0)
	// 	printf("KO, test03\n");
	// else if (strcmp(ft_strjoin(0, buf0, "0"), "") != 0)
	// 	printf("KO, test04\n");
	// else
	// 	printf("OK\n");

	// free(ret0);
	// free(ret1);
	// free(ret2);
	// free(ret3);

	return (0);
}
