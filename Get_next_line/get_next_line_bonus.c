#include"get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static int	rd;
	char		*buffer;
	char		*dst;
	int			i;

	rd = 1;
	i = 0;
	dst = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	while (buffer && rd > 0 && *(buffer + i) != '\n')
	{
		rd = read(fd, buffer + i, BUFFER_SIZE - BUFFER_SIZE + 1);
		if ((i + 1 == BUFFER_SIZE || *(buffer + i) == '\n' || rd == 0)
			&& ft_strlen_gnl(buffer) > 0)
			dst = ft_strjoin_gnl(dst, buffer, &i);
		else
			i++;
	}
	if (buffer)
		free(buffer);
	return (dst);
}
