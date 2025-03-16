#include "pipex.h"
static int	count_word(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep && (i == 0 || str[i - 1] == sep))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_cope(char const *start, char const *end)
{
	int		i;
	char	*holder;

	i = 0;
	holder = (char *)malloc(end - start + 1);
	if (!holder)
		return (NULL);
	while (start < end)
		holder[i++] = *start++;
	holder[i] = '\0';
	return (holder);
}

static char	**free_splitted(char **splitted, int i)
{
	while (i > 0)
		free(splitted[--i]);
	free(splitted);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	char const	*start;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (*s)
	{
		if (*s && *s == c)
			s++;
		else
		{
			start = s;
			while (*s && *s != c)
				s++;
			tab[i++] = ft_cope(start, s);
			if (!tab[i - 1])
				return (free_splitted(tab, i));
		}
	}
	return (tab[i] = NULL, tab);
}