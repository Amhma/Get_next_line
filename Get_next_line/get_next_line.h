#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*calloc_gnl(size_t count, size_t size);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_if_new_line_gnl(char *str);
int		ft_strlen_gnl(char const *str);
void	ft_bzero_gnl(char *str);
int		ft_strchr_nl(char *str);

#endif
