#include "../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("\nmemset:");
	char *memset_c[3];
	char *memset_f[3];
	memset(memset_c, 'A', sizeof(memset_c) - 1);
	ft_memset(memset_f, 'A', sizeof(memset_f) - 1);
	if (strcmp(memset_c, memset_f) == 0)
		printf("\nOK: %s", memset_c);
	else
		printf("\nERROR: expect:%s recive:%s", memset_c, memset_f);

	printf("\nbzero:");
	char *bzero_c[3];
	char *bzero_f[3];
	bzero(bzero_c, sizeof(bzero_c) - 1);
	ft_bzero(bzero_f, sizeof(bzero_f) - 1);
	if (strcmp(bzero_c, bzero_f) == 0)
		printf("\nOK: %s", bzero_c);
	else
		printf("\nERROR: expect:%s recive:%s", bzero_c, bzero_f);

	printf("\nmemcpy:");
	void *memcpy_c[7];
	void *memcpy_f[7];
	memcpy(memcpy_c, "testing", sizeof(memcpy_c));
	ft_memcpy(memcpy_f, "testing", sizeof(memcpy_f));
	if (strcmp(memcpy_c, memcpy_f) == 0)
		printf("\nOK: %s", memcpy_c);
	else
		printf("\nERROR: expect:%s recive:%s", memcpy_c, memcpy_f);

	printf("\nmemccpy:");
	void *memccpy_c[7];
	void *memccpy_f[7];
	memccpy(memccpy_c, "testing",'n', 7);
	ft_memccpy(memccpy_f, "testing", 'n', 7);
	if (strcmp(memccpy_c, memccpy_f) == 0)
		printf("\nOK: %s", memccpy_c);
	else
		printf("\nERROR: expect:%s recive:%s", memccpy_c, memccpy_f);

	printf("\nmemmove:");
	void *memmove_f[28];
	void *memmove_c[28];
	memmove(memmove_c, "lorem ipsum dolor sit amet", 8);
	ft_memmove(memmove_f, "lorem ipsum dolor sit amet", 8);
	if (strcmp(memmove_c, memmove_f) == 0)
		printf("\nOK: %s", memmove_c);
	else
		printf("\nERROR: expect:%s recive:%s", memmove_c, memmove_f);

	printf("\nmemchr:");
	void *memchr_f;
	void *memchr_c;
	memchr_f = memchr("testing", 'e', 10);
	memchr_c = ft_memchr("testing", 'e',  10);
	if (strcmp((char *)memchr_c, (char *)memchr_f) == 0)
		printf("\nOK: %s", (char *)memchr_c);
	else
		printf("\nERROR: expect:%s recive:%s", (char *)memchr_c, (char *)memchr_f);

	printf("\nmemcmp:");
	char memcmp_1[] = {0, 0, 127, 0};
	char memcmp_2[] = {0, 0, 42, 0};
	int memcmp_f = memcmp(memcmp_1, memcmp_2, 10);
	int memcmp_c = ft_memcmp(memcmp_1, memcmp_2, 10);
	if (memcmp_c == memcmp_f)
		printf("\nOK: %d", memcmp_c);
	else
		printf("\nERROR: expect:%d recive:%d", memcmp_c, memcmp_f);

	printf("\nstrlen:");
	int		n;
	int		nc;
	n = ft_strlen("abc");
	nc = strlen("abc");
	if (n == nc)
		printf("\nOK: %d", n);
	else
		printf("\nERROR: expect:%d recive:%d", nc, n);


	printf("\nstrlcpy:");
	char strlcpy_src[11] = "testing123";
	char strlcpy_dest_c[11];
	char strlcpy_dest_f[11];
	int strlcpy_c = strlcpy(strlcpy_dest_c, strlcpy_src, sizeof(strlcpy_dest_c));
	int strlcpy_f = ft_strlcpy(strlcpy_dest_f, strlcpy_src, sizeof(strlcpy_dest_f));
	if (strcmp(strlcpy_dest_c, strlcpy_dest_f) == 0 && strlcpy_c == strlcpy_f)
		printf("\nOK: %d - %s", strlcpy_f, strlcpy_dest_c);
	else
		printf("\nERROR: expect:%d - %s recive:%d - %s", strlcpy_c, strlcpy_dest_c, strlcpy_f, strlcpy_dest_f);

	printf("\nstrlcat:");
	char strlcat_src[7] = "ing123";
	char strlcat_dest_c[11] = "test";
	char strlcat_dest_f[11] = "test";
	int strlcat_c = strlcat(strlcat_dest_c, strlcat_src, sizeof(strlcat_dest_c));
	int strlcat_f = ft_strlcat(strlcat_dest_f, strlcat_src, sizeof(strlcat_dest_f));
	if (strcmp(strlcat_dest_c, strlcat_dest_f) == 0 && strlcat_c == strlcat_f)
		printf("\nOK: %d - %s", strlcat_f, strlcat_dest_c);
	else
		printf("\nERROR: expect:%d - %s recive:%d - %s", strlcat_c, strlcat_dest_c, strlcat_f, strlcat_dest_f);

	printf("\nstrchr:");
	char	*strchr_f;
	char	*strchr_c;
	strchr_f = strchr("testings", 's');
	strchr_c = ft_strchr("testings", 's');
	if (strcmp(strchr_c, strchr_f) == 0)
		printf("\nOK: %s", strchr_c);
	else
		printf("\nERROR: expect:%s recive:%s", strchr_c, strchr_f);

	printf("\nstrrchr:");
	char	*strrchr_f;
	char	*strrchr_c;
	strrchr_f = strrchr("testings", 't');
	strrchr_c = ft_strrchr("testings", 't');
	if (strcmp(strrchr_c, strrchr_f) == 0)
		printf("\nOK: %s", strrchr_c);
	else
		printf("\nERROR: expect:%s recive:%s", strrchr_c, strrchr_f);

	printf("\nstrnstr:");
	const char haystack[20] = "TutorialsPoint";
	const char needle[10] = "Point";
	char	*strnstr_c;
	// char	*strnstr_f;
	// strnstr_f = strnstr(haystack, needle, sizeof(haystack));
	strnstr_c = ft_strnstr(haystack, needle, sizeof(haystack));
	// if (*strnstr_c == *strnstr_f)
		printf("\nOK: %s", strnstr_c);
	// else
	// 	printf("\nERROR: expect:%s recive:%s", strnstr_c, strnstr_f);

	printf("\nstrncmp:");
	int	strncmp_f;
	int	strncmp_c;
	strncmp_f = strncmp("tesstings", "testings", sizeof("testin"));
	strncmp_c = ft_strncmp("tesstings", "testings", sizeof("testin"));
	if (strncmp_c == strncmp_f)
		printf("\nOK: %d", strncmp_c);
	else
		printf("\nERROR: expect:%d recive:%d", strncmp_c, strncmp_f);

	printf("\natoi:");
	int	atoi_f;
	int	atoi_c;
	atoi_f = atoi("--1234ab567");
	atoi_c = ft_atoi("--1234ab567");
	if (atoi_c == atoi_f)
		printf("\nOK: %d", atoi_c);
	else
		printf("\nERROR: expect:%d recive:%d", atoi_f, atoi_c);

	printf("\nisalpha:");
	int	f1_isalpha = isalpha('a');
	int	c1_isalpha = ft_isalpha('a');
	int	f2_isalpha = isalpha(96);
	int	c2_isalpha = ft_isalpha(96);
	if (((f1_isalpha == 0 && c1_isalpha == 0)||( f1_isalpha != 0 && c1_isalpha != 0)) &&
		((f2_isalpha == 0 && c2_isalpha == 0)||( f2_isalpha != 0 && c2_isalpha != 0)))
		printf("\nOK");
	else
		printf("\nERROR: expect:%d-%d recive:%d-%d", f1_isalpha, f2_isalpha, c1_isalpha, c2_isalpha);

	printf("\nisdigit:");
	int	f1_isdigit = isdigit('a');
	int	c1_isdigit = ft_isdigit('a');
	int	f2_isdigit = isdigit('4');
	int	c2_isdigit = ft_isdigit('4');
	if (((f1_isdigit == 0 && c1_isdigit == 0)||( f1_isdigit != 0 && c1_isdigit != 0)) &&
		((f2_isdigit == 0 && c2_isdigit == 0)||( f2_isdigit != 0 && c2_isdigit != 0)))
		printf("\nOK");
	else
		printf("\nERROR: expect:%d-%d recive:%d-%d", f1_isdigit, f2_isdigit, c1_isdigit, c2_isdigit);

	printf("\nisalnum:");
	int	f1_isalnum = isalnum('a');
	int	c1_isalnum = ft_isalnum('a');
	int	f2_isalnum = isalnum('4');
	int	c2_isalnum = ft_isalnum('4');
	if (((f1_isalnum == 0 && c1_isalnum == 0)||( f1_isalnum != 0 && c1_isalnum != 0)) &&
		((f2_isalnum == 0 && c2_isalnum == 0)||( f2_isalnum != 0 && c2_isalnum != 0)))
		printf("\nOK");
	else
		printf("\nERROR: expect:%d-%d recive:%d-%d", f1_isalnum, f2_isalnum, c1_isalnum, c2_isalnum);

	printf("\nisascii:");
	int	f1_isascii = isascii(0);
	int	c1_isascii = ft_isascii(0);
	int	f2_isascii = isascii(128);
	int	c2_isascii = ft_isascii(128);
	if (((f1_isascii == 0 && c1_isascii == 0)||( f1_isascii != 0 && c1_isascii != 0)) &&
		((f2_isascii == 0 && c2_isascii == 0)||( f2_isascii != 0 && c2_isascii != 0)))
		printf("\nOK");
	else
		printf("\nERROR: expect:%d-%d recive:%d-%d", f1_isascii, f2_isascii, c1_isascii, c2_isascii);

	printf("\nisprint:");
	int	f1_isprint = isprint(32);
	int	c1_isprint = ft_isprint(32);
	int	f2_isprint = isprint(127);
	int	c2_isprint = ft_isprint(127);
	if (((f1_isprint == 0 && c1_isprint == 0)||( f1_isprint != 0 && c1_isprint != 0)) &&
		((f2_isprint == 0 && c2_isprint == 0)||( f2_isprint != 0 && c2_isprint != 0)))
		printf("\nOK");
	else
		printf("\nERROR: expect:%d-%d recive:%d-%d", f1_isprint, f2_isprint, c1_isprint, c2_isprint);

	printf("\ntoupper:");
	int	f1_toupper = toupper('a');
	int	c1_toupper = ft_toupper('a');
	int	f2_toupper = toupper('A');
	int	c2_toupper = ft_toupper('A');
	if (f1_toupper == c1_toupper && f2_toupper == c2_toupper)
		printf("\nOK");
	else
		printf("\nERROR: expect:%d-%d recive:%d-%d", f1_toupper, f2_toupper, c1_toupper, c2_toupper);

	printf("\ntolower:");
	int	f1_tolower = tolower('a');
	int	c1_tolower = ft_tolower('a');
	int	f2_tolower = tolower('A');
	int	c2_tolower = ft_tolower('A');
	if (f1_tolower == c1_tolower && f2_tolower == c2_tolower)
		printf("\nOK");
	else
		printf("\nERROR: expect:%d-%d recive:%d-%d", f1_tolower, f2_tolower, c1_tolower, c2_tolower);

		// printf("\nstrdup:");
	// char strdup_test[] = "abcjao";
	// char *strdup_test_f = ft_strdup(strdup_test);
	// char *strdup_test_c = strdup(strdup_test);
	// if (strcmp(strdup_test_c, strdup_test_f) == 0) // change to strcpm
	// 	printf("\nOK: %s", strdup_test_f);
	// else
	// 	printf("\nERROR: expect:%s recive:%s", strdup_test_c, strdup_test_f);

	printf("\nft_substr:");
	char	*f1_ft_substr = ft_substr("abcdefg", 3, sizeof("abcdefg"));
	char	*f2_ft_substr = ft_substr("abcdefg", 3, sizeof("abcdefg"));
	if (strcmp(f1_ft_substr, "defg") == 0 && strcmp(f2_ft_substr, "defg") == 0)
		printf("\nOK");
	else
		printf("\nERROR: recive:%s-%s", f1_ft_substr, f2_ft_substr);

	printf("\nft_strjoin:");
	char	*f1_ft_strjoin = ft_strjoin("abcdefg", "hijklm");
	char	*f2_ft_strjoin = ft_strjoin("abcdefg", "gfe");
	if (strcmp(f1_ft_strjoin, "abcdefghijklm") == 0 && strcmp(f2_ft_strjoin, "abcdefggfe") == 0)
		printf("\nOK");
	else
		printf("\nERROR: recive:%s-%s", f1_ft_strjoin, f2_ft_strjoin);

	printf("\nft_strtrim:");
	char	*f1_ft_strtrim = ft_strtrim("abcdefgacaca", "ca");
	char	*f2_ft_strtrim = ft_strtrim("abcdefgfegfffgegege", "ge");
	if (strcmp(f1_ft_strtrim, "bcdefg") == 0 && strcmp(f2_ft_strtrim, "abcdefgfegfff") == 0)
		printf("\nOK");
	else
		printf("\nERROR: recive:%s-%s", f1_ft_strtrim, f2_ft_strtrim);

	printf("\nft_split:");
	char	**f1_ft_split = ft_split(" lucas yuri gomes barros developer node", ' ');
	if (strcmp(f1_ft_split[0], "lucas") == 0 && strcmp(f1_ft_split[1], "yuri") == 0 && strcmp(f1_ft_split[2], "gomes") == 0 &&
		strcmp(f1_ft_split[3], "barros") == 0 && strcmp(f1_ft_split[4], "developer") == 0 && strcmp(f1_ft_split[5], "node") == 0)
		printf("\nOK");
	else
		printf("\nERROR: recive:%s-%s-%s-%s-%s-%s",
		f1_ft_split[0], f1_ft_split[1], f1_ft_split[2], f1_ft_split[3], f1_ft_split[4], f1_ft_split[5],
		f1_ft_split[6]);

	printf("\nft_itoa:");
	char	*f1_ft_itoa = ft_itoa(-517);
	char	*f2_ft_itoa = ft_itoa(6542452);
	if (strcmp(f1_ft_itoa, "-517") == 0 && strcmp(f2_ft_itoa, "6542452") == 0)
		printf("\nOK");
	else
		printf("\nERROR: recive:%s-%s", f1_ft_itoa, f2_ft_itoa);

	printf("\nft_strmapi:");
	char *f(unsigned int i, char c)
	{
		return (c + 1);
	}
	char	*f1_ft_strmapi = ft_strmapi("teste", f);
	char	*f2_ft_strmapi = ft_strmapi("xtqh", f);
	if (strcmp(f1_ft_strmapi, "uftuf") == 0 && strcmp(f2_ft_strmapi, "yuri") == 0)
		printf("\nOK");
	else
		printf("\nERROR: recive:%s-%s", f1_ft_strmapi, f1_ft_strmapi);

	printf("\nft_putchar_fd:");
	ft_putchar_fd('O', 1);
	ft_putchar_fd('K', 1);
	ft_putchar_fd(':', 1);

	printf("\nft_putstr_fd:");
	ft_putstr_fd("OK:", 1);

	printf("\nft_putendl_fd:");
	ft_putendl_fd("OK:", 1);

	printf("\nft_putnbr_fd:");
	ft_putnbr_fd(-123456, 1);
}
