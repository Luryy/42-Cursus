#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int				get_next_line(int fd, char **line);

int	main()
{
	int				fd;
	int				i;
	int             j;
	char    		*line = 0;
	char			*lineadress[66];

	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/alphabet", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
}
