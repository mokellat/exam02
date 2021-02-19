#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// ft_strlen ; ft_strdup ; ft_strjoin; 

size_t	ft_strlen(const char *str)
{
	size_t length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		cpt;
	char	*new;

	i = 0;
	cpt = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[cpt++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		new[cpt++] = s2[i++];
	}
	new[cpt] = '\0';
	return (new);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	while (src[i])
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int get_next_line(char **line)
{
    char buf[1];
    int ret;

    if (!line || !(*line = ft_strdup("")))
        return (-1);
    while ((ret = read(0, buf, 1)) > 0)
    {
        if (buf[0] == '\n' || buf[0] == '\0')
        {
            buf[0] = '\0';
            break ;
        }
        *line = ft_strjoin(*line, buf);
    }
    buf[0] = '\0';
    return (ret);
}

int main()
{
    char *line;

    while (get_next_line(&line))
    {
        printf("%s\n", line);
    }
    printf("%s\n", line);
}