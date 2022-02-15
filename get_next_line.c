#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
//nel nostro é presente un BUFFER_SIZE ma un semplice BUFFER_SIZE * 0 + 1
//sembra bastare per rendere il codice estremamente semplice
char	*get_next_line(int fd)
{
	int	rd;
	int	i;
	char	c;
	char	*buffer = malloc(9999);

	i = 0;
	while ((rd = read(fd, &c, BUFFER_SIZE * 0 + 1)) > 0)
	{
		buffer[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if ((!buffer[i - 1] && !rd) || rd == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}
