#include <stdio.h>

// //ex00
// #include "./ex00/ft_iterative_factorial.c"
// int ft_iterative_factorial(int nb);

// //ex01
// #include "./ex01/ft_recursive_factorial.c"
// int ft_recursive_factorial(int nb);

// //ex02
// #include "./ex02/ft_iterative_power.c"
// int ft_iterative_power(int nb, int power);

// //ex03
// #include "./ex03/ft_recursive_power.c"
// int ft_recursive_power(int nb, int power);

// //ex04
// #include "./ex04/ft_fibonacci.c"
// int ft_fibonacci(int index);

// //ex05
// #include "./ex05/ft_sqrt.c"
// int ft_sqrt(int nb);

// //ex06
// #include "./ex06/ft_is_prime.c"
// int ft_is_prime(int nb);

// //ex07
// #include "./ex07/ft_find_next_prime.c"
// int ft_find_next_prime(int nb);

// //ex08
// #include "./ex08/ft_sort_int_tab.c"
// void ft_sort_int_tab(int *tab, int size);

int main(void)
{
	// //ex00
	// int facN = 12;
	// int fac1 = ft_iterative_factorial(facN);
	// printf("%d\n", fac1);

	//ex01
	// int facN = 13;
	// int fac2 = ft_recursive_factorial(facN);
	// printf("%d\n", fac2);

	// //ex02
	// int base = -10;
	// int pow = 2;
	// int result = ft_iterative_power(base, pow);
	// printf("%d\n", result);

	// //ex03
	// int base = -10;
	// int pow = 2;
	// int result = ft_recursive_power(base, pow);
	// printf("%d\n", result);

	// //ex04
	// int a =	ft_fibonacci(30);
	// printf("%d\n", a);

	// //ex05
	// int a =	ft_sqrt(2147483647);
	// printf("%d\n", a);2147488281

	// //ex06
	// int a =	ft_is_prime(2);
	// printf("%d\n", a);

	//ex07
	// int a =	ft_find_next_prime(2147483630);
	// printf("%d\n", a);

	return (0);
}


#include <stdio.h>
#include <time.h>
#include <limits.h>

//ex00
#include "./ex00/ft_iterative_factorial.c"
int ft_iterative_factorial(int nb);

//ex01
#include "./ex01/ft_recursive_factorial.c"
int ft_recursive_factorial(int nb);

//ex02
#include "./ex02/ft_iterative_power.c"
int ft_iterative_power(int nb, int power);

//ex03
#include "./ex03/ft_recursive_power.c"
int ft_recursive_power(int nb, int power);

//ex04
#include "./ex04/ft_fibonacci.c"
int ft_fibonacci(int index);

//ex05
#include "./ex05/ft_sqrt.c"
int ft_sqrt(int nb);

//ex06
// #include "./ex06/ft_is_prime.c"
// int ft_is_prime(int nb);

//ex07
#include "./ex07/ft_find_next_prime.c"
int ft_find_next_prime(int nb);

int main(void)
{
	printf("\e[1;31m-- Exercício 00: \e[0m");

	if (ft_iterative_factorial(5) != 5*4*3*2*1)
		printf("KO, wrong 5 factorial");
	else if (ft_iterative_factorial(3) != 6)
		printf("KO, wrong 3 factorial");
	else if (ft_iterative_factorial(7) != 7*6*5*4*3*2*1)
		printf("KO, wrong 7 factorial");
	else if (ft_iterative_factorial(4) != 4*3*2*1)
		printf("KO, wrong 4 factorial");
	else if (ft_iterative_factorial(0) != 1)
		printf("KO, wrong 0 factorial");
	else if (ft_iterative_factorial(-3) != 0)
		printf("KO, wrong -3 factorial");
	else if (ft_iterative_factorial(2) != 2)
		printf("KO, wrong 2 factorial");
	else
		printf("OK\n");

	printf("\e[1;31m-- Exercício 01: \e[0m");

	if (ft_recursive_factorial(5) != 5*4*3*2*1)
		printf("KO, wrong 5 factorial");
	else if (ft_recursive_factorial(3) != 6)
		printf("KO, wrong 3 factorial");
	else if (ft_recursive_factorial(7) != 7*6*5*4*3*2*1)
		printf("KO, wrong 7 factorial");
	else if (ft_recursive_factorial(4) != 4*3*2*1)
		printf("KO, wrong 4 factorial");
	else if (ft_recursive_factorial(0) != 1)
		printf("KO, wrong 0 factorial");
	else if (ft_recursive_factorial(-3) != 0)
		printf("KO, wrong -3 factorial");
	else if (ft_recursive_factorial(2) != 2)
		printf("KO, wrong 2 factorial");
	else
		printf("OK\n");

	printf("\e[1;31m-- Exercício 02: \e[0m");

	if (ft_iterative_power(2, 2) != 4)
		printf("KO, wrong 2 ^ 2\n");
	else if (ft_iterative_power(4, 2) != 16)
		printf("KO, wrong 4 ^ 2\n");
	else if (ft_iterative_power(3, 3) != 27)
		printf("KO, wrong 3 ^ 3\n");
	else if (ft_iterative_power(2, 4) != 16)
		printf("KO, wrong 2 ^ 4\n");
	else if (ft_iterative_power(47, 0) != 1)
		printf("KO, wrong 47 ^ 0\n");
	else if (ft_iterative_power(47, -5) != 0)
		printf("KO, wrong 47 ^ -5\n");
	else
		printf("OK\n");


	printf("\e[1;31m-- Exercício 03: \e[0m");
	fflush(stdout);

	if (ft_recursive_power(2, 2) != 4)
		printf("KO, wrong 2 ^ 2\n");
	else if (ft_recursive_power(4, 2) != 16)
		printf("KO, wrong 4 ^ 2\n");
	else if (ft_recursive_power(3, 3) != 27)
		printf("KO, wrong 3 ^ 3\n");
	else if (ft_recursive_power(2, 4) != 16)
		printf("KO, wrong 2 ^ 4\n");
	else if (ft_recursive_power(47, 0) != 1)
		printf("KO, wrong 47 ^ 0\n");
	else if (ft_recursive_power(47, -5) != 0)
		printf("KO, wrong 47 ^ -5\n");
	else
		printf("OK\n");


	printf("\e[1;31m-- Exercício 04: \e[0mCalculando....");
	fflush(stdout);

	int ret;

	if ((ret = ft_fibonacci(0)) != 0)
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, fibo 0 is 0, got %i", ret);
	else if ((ret = ft_fibonacci(1)) != 1)
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, fibo 1 is 1, got %i", ret);
	else if ((ret = ft_fibonacci(2)) != 1)
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, fibo 2 is 1, got %i", ret);
	else if ((ret = ft_fibonacci(3)) != 2)
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, fibo 3 is 2, got %i", ret);
	else if ((ret = ft_fibonacci(4)) != 3)
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, fibo 4 is 3, got %i", ret);
	else if ((ret = ft_fibonacci(5)) != 5)
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, fibo 5 is 5, got %i", ret);
	else if ((ret = ft_fibonacci(6)) != 8)
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, fibo 6 is 8, got %i", ret);
	else if ((ret = ft_fibonacci(6)) != 8)
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, fibo 6 is 8, got %i", ret);
	else if ((ret = ft_fibonacci(-27)) != -1)
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, fibo -27 is -1, got %i", ret);
	else if ((ret = ft_fibonacci(-23532)) != -1)
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, fibo -23532 is -1, got %i", ret);
#ifndef FAST
	else if ((ret = ft_fibonacci(20)) != 6765)
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, fibo 20 is 6765, got %i", ret);
	else if ((ret = ft_fibonacci(40)) != 102334155)
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, fibo 40 is 102334155, got %i", ret);
#endif
	else
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bOK");

	printf("               \n");

	printf("\e[1;31m-- Exercício 05: \e[0m");

	if ((ret = ft_sqrt(4)) != 2) printf("KO, sqrt 4 is 2, got %i\n", ret);
	else if ((ret = ft_sqrt(16)) != 4) printf("KO, sqrt 16 is 4, got %i\n", ret);
	else if ((ret = ft_sqrt(64)) != 8) printf("KO, sqrt 64 is 8, got %i\n", ret);
	else if ((ret = ft_sqrt(9)) != 3) printf("KO, sqrt 9 is 3, got %i\n", ret);
	else if ((ret = ft_sqrt(81)) != 9) printf("KO, sqrt 81 is 9, got %i\n", ret);
	else if ((ret = ft_sqrt(49)) != 7) printf("KO, sqrt 49 is 7, got %i\n", ret);
	else if ((ret = ft_sqrt(121)) != 11) printf("KO, sqrt 121 is 11, got %i\n", ret);
	else if ((ret = ft_sqrt(25)) != 5) printf("KO, sqrt 25 is 5, got %i\n", ret);
	else if ((ret = ft_sqrt(21)) != 0) printf("KO, sqrt 21 is 0, got %i\n", ret);
	else if ((ret = ft_sqrt(2)) != 0) printf("KO, sqrt 2 is 0, got %i\n", ret);
	else if ((ret = ft_sqrt(2209)) != 47) printf("KO, sqrt 2209 is 47, got %i\n", ret);
	else
		printf("OK\n");

	printf("\e[1;31m-- Exercício 06: \e[0m");

	if ((ret = ft_is_prime(0)) != 0) printf("KO, 0 is not prime\n");
	else if ((ret = ft_is_prime(1)) != 0) printf("KO, 1 is not prime\n");
	else if ((ret = ft_is_prime(4)) != 0) printf("KO, 4 is not prime\n");
	else if ((ret = ft_is_prime(-3)) != 0) printf("KO, -3 is not prime\n");
	else if ((ret = ft_is_prime(-7)) != 0) printf("KO, -7 is not prime\n");
	else if ((ret = ft_is_prime(-8)) != 0) printf("KO, -8 is not prime\n");
	else if ((ret = ft_is_prime(9)) != 0) printf("KO, 9 is not prime\n");
	else if ((ret = ft_is_prime(50)) != 0) printf("KO, 50 is not prime\n");
	else if ((ret = ft_is_prime(234521)) != 0) printf("KO, 234521 is not prime\n");
	else if ((ret = ft_is_prime(2)) != 1) printf("KO, 2 is prime\n");
	else if ((ret = ft_is_prime(3)) != 1) printf("KO, 3 is prime\n");
	else if ((ret = ft_is_prime(11)) != 1) printf("KO, 11 is prime\n");
	else if ((ret = ft_is_prime(13)) != 1) printf("KO, 13 is prime\n");
	else if ((ret = ft_is_prime(5987)) != 1) printf("KO, 5987 is prime\n");
	else if ((ret = ft_is_prime(3023)) != 1) printf("KO, 3023 is prime\n");
	else
		printf("OK\n");

	printf("\e[1;31m-- Exercício 07: \e[0mCalculando....");
	fflush(stdout);

	time_t time_bef;
	time(&time_bef);

	if ((ret = ft_find_next_prime(0)) != 2) printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, prime after 0 is 2, got %i", ret);
	else if ((ret = ft_find_next_prime(1)) != 2) printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, prime after 1 is 2, got %i", ret);
	else if ((ret = ft_find_next_prime(2)) != 2) printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, prime after 2 is 2, got %i", ret);
	else if ((ret = ft_find_next_prime(8)) != 11) printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, prime after 8 is 11, got %i", ret);
	else if ((ret = ft_find_next_prime(4)) != 5) printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, prime after 4 is 5, got %i", ret);
	else if ((ret = ft_find_next_prime(13)) != 13) printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, prime after 4 is 5, got %i", ret);
	else if ((ret = ft_find_next_prime(5982)) != 5987) printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, prime after 5982 is 5987, got %i", ret);
	else if ((ret = ft_find_next_prime(2000000000)) != 2000000011) printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, prime after 2000000000 is 2000000011, got %i", ret);
	else if ((ret = ft_find_next_prime(INT_MAX - 11)) != INT_MAX) printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, prime after INT_MAX - 11 is INT_MAX, got %i", ret);
	else if ((ret = ft_find_next_prime(-50)) != 2) printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, prime after -50 is 2, got %i", ret);
	else if ((time_bef = (time(NULL) - time_bef)) > 10) printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO, timeout! max time is 10 seconds, took %li", time_bef);
	else
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bOK, time: %li seconds", time_bef);

	printf("               \n");
}
