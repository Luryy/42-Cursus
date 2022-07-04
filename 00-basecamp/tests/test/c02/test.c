#include <stdio.h>

// //ex00
// #include "./ex00/ft_strcpy.c"
// char *ft_strcpy(char *dest, char *src);

// //ex01
// #include "./ex01/ft_strncpy.c"
// char *ft_strncpy(char *dest, char *src, unsigned int n);

// //ex02
// #include "./ex02/ft_str_is_alpha.c"
// int ft_str_is_alpha(char *str);

// //ex03
// #include "./ex03/ft_str_is_numeric.c"
// int ft_str_is_numeric(char *str);

// //ex04
// #include "./ex04/ft_str_is_lowercase.c"
// int ft_str_is_lowercase(char *str);

// //ex05
// #include "./ex05/ft_str_is_uppercase.c"
// int ft_str_is_uppercase(char *str);

// //ex06
// #include "./ex06/ft_str_is_printable.c"
// int ft_str_is_printable(char *str);

// //ex07
// #include "./ex07/ft_strupcase.c"
// char *ft_strupcase(char *str);

// //ex08
// #include "./ex08/ft_strlowcase.c"
// char *ft_strlowcase(char *str);

// //ex09
// #include "./ex09/ft_strcapitalize.c"
// char *ft_strcapitalize(char *str);

// //ex10
// #include "./ex10/ft_strlcpy.c"
// unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

// //ex11
// #include "./ex11/ft_putstr_non_printable.c"
// void ft_putstr_non_printable(char *str);

// //ex12
// #include "./ex12/ft_print_memory.c"
// void *ft_print_memory(void *addr, unsigned int size);

#include <string.h>
#include <stdlib.h>

int main(void)
{
	// //ex00
	// char str[7] = "lucass";
	// char dest[7];
	// ft_strcpy(dest, str);
	// printf("%s", dest);

		// char *src;
		// char *dest;

		// src = calloc(11, sizeof(char));
		// src = "malemolencia";
		// dest = calloc(11, sizeof(char));
		// ft_strcpy(dest, src);    
		// printf("src: %s\n", src);
		// printf("dest: %s\n", dest);
		// return (0);

	// //ex01
	// char str[6] = "lucass";
	// char dest[6];
	// ft_strncpy(dest, str, 6);
	// printf("%s", dest);

			// void    ft_strncpy_test(char *dest, char *ft_dest, char *src, unsigned int n)
			// {
			// 	char *res;
			// 	char *ft_res;

			// 	res = strncpy(dest, src, n);
			// 	ft_res = ft_strncpy(ft_dest, src, n);
			// 	if (ft_res != ft_dest)
			// 		printf("> KO, return addres doesn't match *ft_dest, expected: %p, got: %p\n", ft_res, ft_dest);
			// 	else if (strcmp(res, ft_res) != 0)
			// 		printf("> KO, string has not been copied properly, expected: %s, got: %s\n", res, ft_res);
			// 	else
			// 		printf("> OK, result: %s\n", ft_res);
			// }

			// unsigned int    n;
			// char             *src;
			// char             *dest;
			// char             *ft_dest;

			// src = calloc(100, sizeof(char));
			// dest = calloc(100, sizeof(char));
			// ft_dest = calloc(100, sizeof(char));
			// n = 0;
			// srand(0);
			// while (n < 99)
			// {
			// 	src[n] = rand() % 90 + '0' >  126 ? '.' : rand() % 90 + '0';
			// 	n++;
			// }
			// src[n] = '\0';
			// n = 0;
			// while (n < 100)
			// {
			// 	ft_strncpy_test(dest, ft_dest, src, n);
			// 	n++;
			// }


	// //ex02
	// int a = ft_str_is_alpha("adfefemkmaveioAZz");
	// int b = ft_str_is_alpha("dfef1emkmveio");
	// int c = ft_str_is_alpha("");
	// printf("%d, %d, %d\n", a, b, c);


	// //ex03
	// int a = ft_str_is_numeric("123456789097r653");
	// int b = ft_str_is_numeric("1234456789098765");
	// int c = ft_str_is_numeric("");
	// printf("%d, %d, %d\n", a, b, c);


	// //ex04
	// int a = ft_str_is_lowercase("afKJEHKFejnklz");
	// int b = ft_str_is_lowercase("gkjfhkrhagkiweifipi");
	// int c = ft_str_is_lowercase("");
	// printf("%d, %d, %d\n", a, b, c);

	// // ex05
	// int a = ft_str_is_uppercase("AFKAHFAHUAKZ");
	// int b = ft_str_is_uppercase("NKREAHFAUh");
	// int c = ft_str_is_uppercase("");
	// printf("%d, %d, %d\n", a, b, c);

	//ex06
	// int a = ft_str_is_printable(" !\"#$&%'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
	// int b = ft_str_is_printable("â");
	// int c = ft_str_is_printable("");
	// printf("%d, %d, %d\n", a, b, c);
		
		// char *str1;
		// char *str2;
		// char *str3;
		// char *str4;
		// char *str5;

		// str1 = calloc(10, sizeof(char));
		// str2 = calloc(10, sizeof(char));
		// str3 = calloc(10, sizeof(char));
		// str4 = calloc(10, sizeof(char));
		// str1 = "ABCDEFGHI";
		// str2 = "BCDEFGHI";
		// str3 = "ABCDFGHI*";
		// str4 = "ABCDEFGH";
		// str5 = "";
		// printf("str1: %s, is_printable: %d\n", str1, ft_str_is_printable(str1));
		// printf("str2: %s, is_printable: %d\n", str2, ft_str_is_printable(str2));
		// printf("str3: %s, is_printable: %d\n", str3, ft_str_is_printable(str3));
		// printf("str4: %s, is_printable: %d\n", str4, ft_str_is_printable(str4));
		// printf("str5: %s, is_printable: %d\n", str5, ft_str_is_printable(str5));

	// //ex07
	// char a[8] = "LuCaS10";
	// char b[11] = "fakhhrfyau";
	// char c[8] = "";
	// char *d = ft_strupcase(a);
	// char *e = ft_strupcase(b);
	// char *f = ft_strupcase(c);
	// printf("%s, %s, %s\n", d, e, f);

	// //ex08
	// char a[8] = "LuCaS10";
	// char b[11] = "FSHANDKRON";
	// char c[8] = "";
	// char *d = ft_strlowcase(a);
	// char *e = ft_strlowcase(b);
	// char *f = ft_strlowcase(c);
	// printf("%s, %s, %s\n", d, e, f);

	// //ex09
	// char a[] = "oi, tuDo bem? 42palAvras QuareNta-e-dUAs; cinqUEnta+e+um";
	// char *d = ft_strcapitalize(a);
	// printf("%s\n", d);

		// char str1[] = "alo maluco 42beleza!";
		// char str2[] = "ALO MALUCO 42BELEZA!";
		// char str3[] = "alo+ma|uco a2beleza!";
		// char str4[] = "ALO+MALUCO*a2BELEZA!";
		// char str5[] = "^uIv#= =9Hf~2y@F3A)FTzBgF";
		// char str6[] = "tsR1|vn_WE}7X6{Vm2vQf(rG}qdnT`1,qH+n";
		// char str7[] = "oi, tudo bem? 42palavras quarenta-e-duas; cinquenta+e+um";

		// printf("str1: %s\n", str1);
		// ft_strcapitalize(str1);
		// printf("str1_c: %s\n", str1);
		// printf("str2: %s\n", str2);
		// ft_strcapitalize(str2);
		// printf("str2_c: %s\n", str2);
		// printf("str3: %s\n", str3);
		// ft_strcapitalize(str3);
		// printf("str3_c: %s\n", str3);
		// printf("str4: %s\n", str4);
		// ft_strcapitalize(str4);
		// printf("str4_c: %s\n", str4);
		// printf("str5: %s\n", str5);
		// ft_strcapitalize(str5);
		// printf("str5_c: %s\n", str5);
		// printf("str6: %s\n", str6);
		// ft_strcapitalize(str6);
		// printf("str6_c: %s\n", str6);
		// ft_strcapitalize(str7);
		// printf("str6_c: %s\n", str7);

	//ex10
	// char t[5] = "lucas";
	// char d[6] = "o";
	// char n = ft_strlcpy(d, t, 4);
	// printf("%d \n", n);
	// printf("%s \n", d);
		// // just to see how strlcpy works
		// char t[5] = "lucas";
		// char d[6] = "o";
		// int n = strlcpy(d, t, 7);
		// printf("%d \n", n);
		// printf("%s \n", d);

	// //ex11
	// // char str[] = {'0', '1', 2, 30, 16, '4', '\n', 19, 'C'};
	// char str[] = "Oi\nvoce esta bem?";
	// // char str[] = {'0', '1', '2', 'a', '1', 'b', '\n', '1', 'C'};
    // ft_putstr_non_printable(str);

	// //ex12
	// char *str = "Bonjour les aminches\n\b\rc  est fou\ntout\rce qu on peut faire avec\r\r\nprint_memory\n\n\r\blol\rlol\r \b";
    // ft_print_memory(str, strlen(str));
	// // int str = 4;
	// printf("\n %p\n", str);
	// printf("\n %lu\n", strlen(str));

	return (0);
}