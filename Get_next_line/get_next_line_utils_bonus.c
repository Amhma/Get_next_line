#include"get_next_line_bonus.h"

int	ft_strlen_gnl(char const *str)
{
	int	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

void	ft_bzero_gnl(char *str)
{
	int	i;

	i = 0;
	while (str && *(str + i))
		*(str + i++) = '\0';
}

void	*calloc_gnl(size_t count, size_t size)
{
	void	*dst;
	size_t	i;

	i = 0;
	dst = malloc(count * size);
	if (!dst)
		return (NULL);
	while (i < count)
		*((unsigned char *)dst + i++) = 0;
	return (dst);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int *y)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dst = calloc_gnl((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1), sizeof(char));
	if (!dst)
		return (NULL);
	while (s1 && *(s1 + j))
		*(dst + i++) = *(s1 + j++);
	j = 0;
	while (s2 && *(s2 + j) && *(s2 + j) != '\n')
		*(dst + i++) = *(s2 + j++);
	if (*(s2 + j) == '\n')
		*(dst + i) = *(s2 + j);
	if (s1)
		free(s1);
	if (*(s2 + *y) != '\n')
	{
		*y = 0;
		ft_bzero_gnl(s2);
	}
	return (dst);
}
